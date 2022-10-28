#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

int n, m, d[N];
vector<int> adj[N], radj[N];
int max_vis[N], cnt_unvis[N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        max_vis[i] = 0;
        cnt_unvis[i] = sz(adj[i]);
    }

    std::fill(d, d + n, MOD);
    d[n-1] = 0;

    min_pq<pair<int, int>> q;
    q.push({0, n-1});

    while (sz(q)) {
        auto [d_c, c] = q.top(); q.pop();
        if (d[c] != d_c) continue;
        for (auto nxt : radj[c]) {
            max_vis[nxt] = max(max_vis[nxt], d_c);
            cnt_unvis[nxt]--;
            if (d[nxt] > max_vis[nxt] + cnt_unvis[nxt] + 1) {
                d[nxt] = max_vis[nxt] + cnt_unvis[nxt] + 1;
                q.push({d[nxt], nxt});
            }
        }
    }
    cout << d[0] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}