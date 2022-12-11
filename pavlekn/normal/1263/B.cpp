#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(4));
        map<vector<char>, int> used;
        int ans = 0;
        vector<int> c;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin >> a[i][j];
            }
            if (used[a[i]])
            {
                c.push_back(i);
                ++ans;
            }
            used[a[i]] = true;
        }
        for (auto i : c)
        {
            for (int j = 0; j < 10; ++j)
            {
                a[i][0] = '0' + j;
                if (!used[a[i]])
                {
                    break;
                }
            }
            used[a[i]] = true;
        }
        cout << ans << endl;
        for (auto el : a)
        {
            for (int i = 0; i < 4; ++i)
            {
                cout << el[i];
            }
            cout << endl;
        }
    }
    return 0;
}