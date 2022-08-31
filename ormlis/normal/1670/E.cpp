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
const int maxN = 1e6 + 20;
const int LG = 100;

vpi g[maxN];
int ans1[maxN], ans2[maxN];
int T = 1;
int n;

void dfs(int v, int p, int c) {
    for (auto &[u, i] : g[v]) {
        if (u == p) continue;
        if (c == 0) {
            ans2[i] = T;
            ans1[u] = n + T;
            T++;
            dfs(u, v, n);
        } else {
            assert(c == n);
            ans2[i] = n + T;
            ans1[u] = T;
            T++;
            dfs(u, v, 0);
        }
    }
}

void solve() {
    int p;
    cin >> p;
    n = (1 << p);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    cout << "1\n";
    ans1[1] = n;
    dfs(1, -1, n);
    T = 1;
    rep(i, n + 1) g[i].clear();
    for(int i = 1; i <= n; ++i) cout << ans1[i] << ' ';
    cout << '\n';
    rep(i, n - 1) cout << ans2[i] << ' ';
    cout << '\n';
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