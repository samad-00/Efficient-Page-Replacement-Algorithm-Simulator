#include <bits/stdc++.h>
using namespace std;
// Code for FIFO Page Replacement

void saveResults(string algo, int pageFaults)
{
    ofstream fout("results.txt", ios::app); // Open file in append mode
    fout << algo << " " << pageFaults << endl;
    fout.close();
}

void FIFO(vector<int> pages, int frames)
{
    queue<int> frameQueue;
    unordered_map<int, bool> pageMap;
    int pageFaults = 0;
    cout << "\nFIFO Page Replacement Algorithm:\n";
    for (int page : pages)
    {
        if (!pageMap[page])
        { //  if page fault occurs
            if (frameQueue.size() >= frames)
            { // if it happens, remove oldest page if full
                int oldest = frameQueue.front();
                frameQueue.pop();
                pageMap.erase(oldest);
            }
            frameQueue.push(page);
            pageMap[page] = true;
            pageFaults++;
        }
    }
    cout << "Total Page Faults: " << pageFaults << endl;
    saveResults("FIFO", pageFaults);
}
