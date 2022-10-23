#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e5 + 10;
const int md = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vl> g(n, vl(n, 0));
    vector<ar<int, 3>> edges;
    rep(j, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push_back({u, v, w});
        g[u][v] = g[v][u] = 1;
    }
    vector<vl> d(n, vl(n, -1));
    d[0][n - 1] = 0;
    d[n - 1][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, n - 1});
    q.push({n - 1, 0});
    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        rep(k, n) {
            if ((u == v || g[u][k]) && d[k][v] == -1) {
                d[k][v] = d[u][v] + 1;
                q.push({k, v});
            }
            if ((u == v || g[v][k]) && d[u][k] == -1) {
                d[u][k] = d[u][v] + 1;
                q.push({u, k});
            }
        }
    }
    ll ans = INF;
    for (auto [u, v, w]: edges) {

        ans = min(ans, 1ll * w * (d[u][v] + 1));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}