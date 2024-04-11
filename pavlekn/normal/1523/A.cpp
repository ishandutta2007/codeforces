#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        m = min(n, m);
        vector<int> a(n + 2);
        vector<int> b(n + 2);
        for (int i = 0; i < n; ++i)
        {
            a[i + 1] = s[i] - '0';
        }
        for (int ii = 0; ii < m; ++ii)
        {
            for (int i = 1; i <= n; ++i)
            {
                int cnt = a[i - 1] + a[i + 1];
                if (a[i] || cnt == 1)
                {
                    b[i] = true;
                }
            }
            for (int i = 1; i <= n; ++i)
            {
                a[i] = b[i];
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}