#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

const int MAXN = 63;

char a[MAXN][MAXN];

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
        vector<int> cnt1(n);
        vector<int> cnt2(m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 'P')
                {
                    ++cnt1[i];
                    ++cnt2[j];
                }
            }
        }
        int ans = 5;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] == 'P')
                {
                    continue;
                }
                int cur = 4;
                int fl = true;
                for (int k = 0; k < i; ++k)
                {
                    if (a[k][j] == 'P')
                    {
                        fl = false;
                    }
                }
                cur -= fl;
                fl = true;
                for (int k = i + 1; k < n; ++k)
                {
                    if (a[k][j] == 'P')
                    {
                        fl = false;
                    }
                }
                cur -= fl;
                fl = true;
                for (int k = 0; k < j; ++k)
                {
                    if (cnt2[k])
                    {
                        fl = false;
                    }
                }
                cur -= fl;
                fl = true;
                for (int k = j + 1; k < m; ++k)
                {
                    if (cnt2[k])
                    {
                        fl = false;
                    }
                }
                cur -= fl;
                ans = min(ans, cur);
                cur = 4;
                fl = true;
                for (int k = 0; k < j; ++k)
                {
                    if (a[i][k] == 'P')
                    {
                        fl = false;
                    }
                }
                cur -= fl;
                fl = true;
                for (int k = j + 1; k < m; ++k)
                {
                    if (a[i][k] == 'P')
                    {
                        fl = false;
                    }
                }
                cur -= fl;
                fl = true;
                for (int k = 0; k < i; ++k)
                {
                    if (cnt1[k])
                    {
                        fl = false;
                    }
                }
                cur -= fl;
                fl = true;
                for (int k = i + 1; k < n; ++k)
                {
                    if (cnt1[k])
                    {
                        fl = false;
                    }
                }
                cur -= fl;
                ans = min(ans, cur);
            }
        }
        if (ans == 5)
        {
            cout << "MORTAL" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}