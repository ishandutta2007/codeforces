#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> freq;
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freq[x]++;
            mx = max(mx, freq[x]);
        }
        if (mx * 2 <= n)
        {
            if (n & 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else
            cout << mx * 2 - n << "\n";
    }
    return 0;
}