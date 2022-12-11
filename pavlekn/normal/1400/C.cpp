#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 225;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;
        int x;
        cin >> x;
        int n = s.size();
        vector<char> w(n);
        for (int i = 0; i < n; ++i)
        {
            w[i] = '1';
        }
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                if (i + x < n)
                {
                    w[i + x] = '0';
                }
                if (i - x >= 0)
                {
                    w[i - x] = '0';
                }
            }
        }
        int fl = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '1')
            {
                if ((i + x >= n || w[i + x] == '0') && (i - x < 0 || w[i - x] == '0'))
                {
                    fl = -1;
                }
            }
        }
        if (fl == -1)
        {
            cout << -1 << endl;
            continue;
        }
        for (auto el : w)
        {
            cout << el;
        }
        cout << endl;
    }
    return 0;
}