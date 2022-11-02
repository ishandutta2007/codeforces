#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int INF = 1e18, MOD = 1e9 + 7;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<int>> g(n);
        s--, t--;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        deque<int> q{s};
        vector<int> d(n, INF);
        d[s] = 0;
        vector<vector<int>> cnt(n, vector<int>(2));
        while (q.size() > 0) {
            int v = q.front();
            q.pop_front();
            for (auto to : g[v]) {
                if (d[to] == INF) {
                    d[to] = d[v] + 1;
                    q.pb(to);
                }
            }
        }
        vector<vector<pair<int,int>>> a(n + 1);
        for (int i = 0; i < n; i++) {
            if (d[i] == INF) continue;
            a[d[i]].pb({i, 0});
            a[d[i] + 1].pb({i, 1});
        }
        cnt[s][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (auto [v, t] : a[i]) {
                for (auto to : g[v]) {
                    if (i + 1 == d[to]) {
                        cnt[to][0] = add(cnt[to][0], cnt[v][t]);
                    }
                    if (i + 1 == d[to] + 1) {
                        cnt[to][1] = add(cnt[to][1], cnt[v][t]);
                    }
                }
            }
        }
        cout << add(cnt[t][0], cnt[t][1]) << endl;
    }
    return 0;
}