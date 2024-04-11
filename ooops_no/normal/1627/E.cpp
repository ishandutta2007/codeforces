#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int INF = 1e18;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> x(n), ans(k + 2, INF), h(k + 2);
        vector<vector<pair<int,int>>> all(n);
        ans[k] = 0;
        all[0].pb({0, k});
        all[n - 1].pb({m - 1, k + 1});
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < k; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d >> h[i];
            a--, b--, c--, d--;
            all[a].pb({b, i});
            all[c].pb({d, i});
        }
        for (int i = 0; i < n; i++) {
            sort(all[i].begin(), all[i].end());
            int mn = INF;
            map<int,int> need;
            for (int j = 0; j < all[i].size(); j++) {
                if (j > 0) mn += (all[i][j].first - all[i][j - 1].first) * x[i];
                int ind = all[i][j].second;
                if (ans[ind] == INF) {
                    need[ind] = 1;
                    ans[ind] = min(ans[ind], mn - h[ind]);
                } else {
                    mn = min(mn, ans[ind]);
                }
            }
            mn = INF;
            for (int j = (int)(all[i].size()) - 1; j >= 0; j--) {
                if (j + 1 < all[i].size()) mn += (all[i][j + 1].first - all[i][j].first) * x[i];
                int ind = all[i][j].second;
                if (need[ind]) {
                    ans[ind] = min(ans[ind], mn - h[ind]);
                } else {
                    mn = min(mn, ans[ind]);
                }
            }
        }
        if (ans[k + 1] >= INF / 10) cout << "NO ESCAPE" << endl;
        else cout << ans[k + 1] << endl;
    }
    return 0;
}