#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(51);

const int N = 5e5 + 10, INF = 1e18;
vector<pair<int,int>> g[N];

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> d(n, INF), color(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[b].pb({a, c});
    }
    d[n - 1] = 0;
    deque<int> q{n - 1};
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto to : g[v]) {
            if (d[to.first] == INF) {
                if (color[to.first] == -1) {
                    color[to.first] = (to.second ^ 1);
                }
                if (to.second == color[to.first]) {
                    d[to.first] = d[v] + 1;
                    q.pb(to.first);
                }
            }
        }
    }
    if (d[0] == INF) cout << -1 << endl;
    else cout << d[0] << endl;
    for (int i = 0; i < n; i++) {
        cout << (color[i] == -1 ? 0 : color[i]);
    }
    cout << endl;
    return 0;
}