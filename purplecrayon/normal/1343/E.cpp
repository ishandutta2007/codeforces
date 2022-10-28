#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

void solve() {
    int n, m, a, b, c; cin >> n >> m >> a >> b >> c, --a, --b, --c;
    vector<int> cost(m); for (auto& x : cost) cin >> x;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y, --x, --y;
        adj[x].push_back(y), adj[y].push_back(x);
    }

    auto get_dist = [&](int s) {
        vector<int> d(n, MOD);
        d[s] = 0;
        vector<int> q{s}; q.reserve(n);
        for (int rep = 0; rep < sz(q); rep++) {
            int c = q[rep];
            for (auto nxt : adj[c]) if (d[nxt] > d[c] + 1) {
                d[nxt] = d[c] + 1;
                q.push_back(nxt);
            }
        }
        return d;
    };

    auto da = get_dist(a), db = get_dist(b), dc = get_dist(c);
    sort(cost.begin(), cost.end());
    vector<ll> sum(m);
    for (int i = 0; i < m; i++) {
        sum[i] = cost[i];
        if (i) sum[i] += sum[i-1];
    }

    auto qry = [&](int L, int R) {
        if (L > R) return 0LL;
        return sum[R] - (L ? sum[L-1] : 0);
    };

    ll ans = INF;
    for (int mid = 0; mid < n; mid++) {
        int two = db[mid], one = da[mid] + dc[mid];
        if (two + one > m) continue;
        ans = min(ans, 2 * qry(0, two-1) + qry(two, two + one - 1));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}