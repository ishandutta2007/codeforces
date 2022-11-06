#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* freq = new int[n + 1];
    int* hist = new int[100001];
    int maxFreq = 0;
    fill(freq, freq + n + 1, 0);
    fill(hist, hist + 100001, 0);
    int numColors = 0;
    int sol = 1;
    for (int i = 1; i <= n; i++)
    {
        int color;
        cin >> color;
        if (hist[color] == 0)
        {
            numColors++;
            hist[color] = 1;
            freq[1]++;
        }
        else
        {
            freq[hist[color]]--;
            hist[color]++;
            freq[hist[color]]++;
        }

        if (hist[color] > maxFreq)
            maxFreq = hist[color];

        if (numColors == 1)
            sol = i;
        else if (maxFreq == 1)
            sol = i;
        else
        {
            if (freq[maxFreq] == 1 && freq[maxFreq - 1] == numColors - 1)
                sol = i;
            else if (freq[1] == 1 && freq[maxFreq] == numColors - 1)
                sol = i;
        }
    }

    cout << sol;
    return 0;
}