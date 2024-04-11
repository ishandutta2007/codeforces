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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = double;
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

const int maxN = 2e5 + 5;
vi g[maxN];
vi dp[maxN];
int c[maxN];
int add[maxN];
int ended[maxN];


void merge(int v, int u) {
    if (dp[u].size() > dp[v].size()) {
        swap(dp[u], dp[v]);
        swap(c[v], c[u]);
        swap(add[u], add[v]);
        swap(ended[u], ended[v]);
    }
    add[v] += ended[u];
    ended[v] += ended[u];
    rep(i, (int) dp[u].size()) {
        dp[v][i] += (dp[u][i] + c[u] * i + add[u]) - ended[u];
    }
}


vector<int> qq[maxN];
int k[maxN];
int ans[maxN];

void dfs(int v, int p) {
    for (auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        merge(v, u);
    }
    for (auto &i : qq[v]) {
        if (k[i] < dp[v].size()) {
            ans[i] = c[v] * k[i] + dp[v][k[i]] + add[v];
        } else {
            ans[i] = ended[v];
        }
    }
    while (dp[v].size() < (int) g[v].size() + 2) {
        // x + c[v] * (int)dp[v].size() + add[v] == ended[v]
        int x = ended[v] - (int) dp[v].size() * c[v] - add[v];
        dp[v].push_back(x);
    }
    c[v]--;
    int sz = dp[v].size();
    sz--;
    while(sz >= 0 && dp[v][sz] + add[v] + sz * c[v] <= 1) {
        dp[v].pop_back();
        sz--;
    }
    ended[v] = 1;
}

void solve() {
    int n;
    cin >> n;
    rep(_, n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int q;
    cin >> q;
    rep(i, q) {
        int v;
        cin >> v >> k[i];
        qq[v].push_back(i);
    }
    dfs(1, -1);
    rep(i, q) cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(_, t) {
        solve();
    }
    return 0;
}