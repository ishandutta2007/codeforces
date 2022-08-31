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
const int maxN = 2e5 + 30;
const int LG = 20;

vi a[2];
vi g[maxN];

void dfs(int v, int p, int c) {
    a[c].push_back(v);
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v, c ^ 1);
    }
}

void solve() {
    int n;
    cin >> n;
    rep(_, n - 1) {
        int v, u;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0);
    vi p(n);
    for (int i = n, j = n; i >= 1; i = j) {
        while ((i ^ j) <= j) j--;
        int len = i - j;
        int c = 0;
        if (a[c].size() < len) c++;
        assert(a[c].size() >= len);
        for (int e = i; e > j; --e) {
            p[a[c].back() - 1] = e;
            a[c].pop_back();
        }
    }
    rep(i, n) cout << p[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; ++i) g[i].clear();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}