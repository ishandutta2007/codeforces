#include <bits/stdc++.h>

using namespace std;

int T, n, k;
long long arr[2 * (int) 2e5];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int fs = 0, sec = k;
        long long minRange = 1e9;
        int start = 0;
        while (sec < n)
        {
            if (arr[sec] - arr[fs] < minRange)
            {
                minRange = arr[sec] - arr[fs];
                start = fs;
            }
            fs++;
            sec++;
        }
        cout << (arr[start] + arr[start + k]) / 2 << endl;
    }
    return 0;
}