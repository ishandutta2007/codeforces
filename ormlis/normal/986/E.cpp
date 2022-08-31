#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;
const int maxV = 1e7 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


vector<int> g[maxN];
int mp[maxV];
vector<int> primes;

void init() {
    for (int i = 2; i < maxV; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }
        for (auto &p : primes) {
            if (1ll * p * i >= maxV || p > mp[i]) break;
            mp[p * i] = p;
        }
    }
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> ans;
    while (x != 1) {
        int p = mp[x];
        ans.emplace_back(p, 0);
        while (x % p == 0) {
            x /= p;
            ans.back().second++;
        }
    }
    return ans;
}

int up[maxN][20];
int h[maxN];

void dfs1(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for (auto &u : g[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs1(u, v);
    }
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (h[up[v][i]] >= h[u]) v = up[v][i];
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; --i) {
        if (up[v][i] != up[u][i]) v = up[v][i], u = up[u][i];
    }
    return up[v][0];
}

int dist(int a, int b) {
    return h[a] + h[b] - 2 * h[lca(a, b)];
}


inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int a[maxN];
vector<ar<int, 4>> qs[maxN];
int ans[maxN];

vector<int> pref[maxV];

void dfs(int v, int p) {
    auto f = factorize(a[v]);
    for (auto &[pp, c] : f) {
        while (pref[pp].size() <= c) {
            pref[pp].push_back(0);
        }
        pref[pp][c]++;
    }
    for (auto &[pp, c, i, t] : qs[v]) {
        int cnt = 0;
        for (int j = 0; j < pref[pp].size(); ++j) cnt += pref[pp][j] * min(j, c);
        if (t == -1) {
            ans[i] = mul(ans[i], rev(binpow(pp, cnt * 2)));
        } else {
            ans[i] = mul(ans[i], binpow(pp, cnt));
        }
    }
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    for (auto &[pp, c] : f) {
        pref[pp][c]--;
    }
}

void solve() {
    int n;
    cin >> n;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];

    dfs1(1, 1);
    int q;
    cin >> q;
    range(i, q) {
        int u, v, x;
        cin >> u >> v >> x;
        int w = lca(u, v);
        ans[i] = abs(__gcd(x, a[w]));
        auto res = factorize(x);
        for (auto &[p, c] : res) {
            qs[v].push_back({p, c, i, 1});
            qs[u].push_back({p, c, i, 1});
            qs[w].push_back({p, c, i, -1});
        }
    }
    dfs(1, 1);
    range(i, q) cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    init();
    range(_, tests) {
        solve();
    }
    return 0;
}