#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 2e5 + 20;
const int LG = 30;

vi g[maxN];
vi path;

bool get_path(int v, int p, int f) {
    path.push_back(v);
    if (v == f) return true;
    for (auto &u : g[v]) {
        if (u == p) continue;
        if (get_path(u, v, f)) return true;
    }
    path.pop_back();
    return false;
}

int ans = 0;

bool used[maxN];
bool good[maxN];

bool dfs(int v) {
    used[v] = true;
    bool r = good[v];
    for (auto &u : g[v]) {
        if (used[u]) continue;
        if (dfs(u)) {
            ans += 2;
            r = true;
        }
    }
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    vi a(k);
    rep(i, k) cin >> a[i];
    rep(_, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, k) good[a[i]] = true;
    get_path(x, -1, y);
    ans = (int) path.size() - 1;
    for (auto &v : path) used[v] = true;
    for (auto &v : path) dfs(v);
    for (int i = 1; i <= n; ++i) {
        used[i] = false;
        good[i] = false;
        g[i].clear();
    }
    cout << ans << '\n';
    path.clear();
    ans = 0;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}