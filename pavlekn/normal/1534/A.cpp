#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char> (m));
        int cnt1 = 0;
        int cnt2 = 0;
        vector<set<int>> b(2);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
                int num = (i + j) % 2;
                if (a[i][j] == 'R')
                {
                    ++cnt1;
                    b[num].insert(0);
                }
                else if (a[i][j] == 'W')
                {
                    ++cnt2;
                    b[num].insert(1);
                }
            }
        }
        if (cnt1 == 0)
        {
            if (b[0].size() == 0)
            {
                b[0].insert(0);
            }
            else
            {
                b[1].insert(0);
            }
        }
        if (cnt2 == 0)
        {
            if (b[0].size() == 0)
            {
                b[0].insert(1);
            }
            else
            {
                b[1].insert(1);
            }
        }
        if (b[0].size() >= 2 || b[1].size() >= 2)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int num = (i + j) % 2;
                if ((*b[num].begin()) == 0)
                {
                    cout << 'R';
                }
                else
                {
                    cout << 'W';
                }
            }
            cout << endl;
        }
    }
    return 0;
}