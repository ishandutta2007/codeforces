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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 1e5 + 30;
const int LG = 20;

void solve() {
    int n, m;
    cin >> n >> m;
    vi p(n);
    rep(i, n) cin >> p[i];
    vector<int> x(m), y(m);
    rep(i, m) cin >> x[i] >> y[i];
    rep(i, n) {
        p[i]--;
    }
    rep(i, m) {
        x[i]--;
        y[i]--;
    }
    vvi to(n);
    rep(i, m) {
        to[x[i]].push_back(i);
        to[y[i]].push_back(i);
    }
    vvi g(m);
    vi d(n, -1);
    vi sz(n, -1);
    rep(i, n) {
        if (d[i] != -1) continue;
        int cur = 0;
        int pos = i;
        while (d[pos] == -1) {
            d[pos] = cur++;
            pos = p[pos];
        }
        while (sz[pos] == -1) {
            sz[pos] = cur;
            pos = p[pos];
        }
    }
    rep(i, n) {
        sort(all(to[i]), [&](const int &a, const int &b) {
            int ya = x[a] ^y[a] ^i;
            int yb = x[b] ^y[b] ^i;
            int L = (d[i] + 1) % sz[i];
            int Ra = d[ya] % sz[i];
            int Rb = d[yb] % sz[i];
            Ra = (Ra - L + sz[i]) % sz[i];
            Rb = (Rb - L + sz[i]) % sz[i];
            return Ra < Rb;
        });
        for (int j = 1; j < to[i].size(); ++j) {
            g[to[i][j - 1]].push_back(to[i][j]);
        }
    }
    vi was(m);
    vi ts;
    function<void(int)> dfs = [&](int v) {
        was[v] = 1;
        for (auto &u : g[v]) {
            if (was[u]) continue;
            dfs(u);
        }
        ts.push_back(v);
    };
    rep(i, m) if (!was[i]) dfs(i);
    reverse(all(ts));
    for(auto &v : ts) cout << v + 1 << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}