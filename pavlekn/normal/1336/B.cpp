#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 9e18 + 999189;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a(3);
        a[0].resize(n);
        a[1].resize(m);
        a[2].resize(k);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[0][i];
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> a[1][i];
        }
        for (int i = 0; i < k; ++i)
        {
            cin >> a[2][i];
        }
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        sort(a[2].begin(), a[2].end());
        vector<int> p = {0, 1, 2};
        int ans = INF;
        do
        {
            for (auto el : a[p[0]])
            {
                int ind2 = lower_bound(a[p[1]].begin(), a[p[1]].end(), el) - a[p[1]].begin();
                int ind1 = lower_bound(a[p[2]].begin(), a[p[2]].end(), el) - a[p[2]].begin();
                if (ind2 != a[p[1]].size())
                {
                    int el1 = a[p[1]][ind2];
                    if (ind1 != 0 && (ind1 == a[p[2]].size() || a[p[2]][ind1] > el))
                    {
                        --ind1;
                    }
                    int el2 = a[p[2]][ind1];
                    int cur = (el1 - el) * (el1 - el) + (el2 - el) * (el2 - el) + (el1 - el2) * (el1 - el2);
                    ans = min(ans, cur);
                }
            }
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << endl;
    }
    return 0;
}