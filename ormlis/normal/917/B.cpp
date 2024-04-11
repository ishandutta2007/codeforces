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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 5e4 + 5;
const int LG = 19;

vector<pair<int, int>> g[maxN];
bool used[maxN];
vector<int> ts;

void dfs(int v) {
    used[v] = true;
    for (auto &[u, w] : g[v]) {
        if (used[u]) continue;
        dfs(u);
    }
    ts.push_back(v);
}

void solve() {
    int n, m;
    cin >> n >> m;
    rep(_, m) {
        int v, u;
        char c;
        cin >> v >> u >> c;
        g[v].emplace_back(u, c);
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;
        dfs(i);
    }
    vi ind(n + 1);
    rep(i, n) ind[ts[i]] = i;
    vec<vvi> dp(n, vvi(n, vi(26)));
    for (int sum = 0; sum < n * 2 - 1; ++sum) {
        for (int i = 0; i < n; ++i) {
            int j = sum - i;
            if (j < 0 || j >= n) continue;
            for (auto &[u, c] : g[ts[i]]) {
                int w = ind[u];
                if (dp[j][w][c - 'a'] != 0) continue;
                for(int d = 0; d <= (c - 'a'); ++d) dp[i][j][d] = 1;
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            if (dp[ind[i + 1]][ind[j + 1]][0]) cout << 'A';
            else cout << 'B';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}