#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18 + 11;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j % 2 == 0)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << (1ll << (i + j)) << " ";
            }
        }
        cout << endl;
    }
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int ans;
        cin >> ans;
        int i = 0;
        int j = 0;
        vector<pair<int, int>> res = {{1, 1}};
        for (int k = 1; k < 2 * n - 1; ++k)
        {
            if (ans & (1ll << k))
            {
                if (j % 2)
                {
                    ++i;
                }
                else
                {
                    ++j;
                }
            }
            else
            {
                if (j % 2)
                {
                    ++j;
                }
                else
                {
                    ++i;
                }
            }
            res.push_back({i + 1, j + 1});
        }
        for (auto el : res)
        {
            cout << el.first << " " << el.second << endl;
        }
    }
    return 0;
}