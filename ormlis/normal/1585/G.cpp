#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

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


const int maxN = 5e5 + 5;
vector<int> g[maxN];
vector<int> dp[maxN];

void merge(int v, int u) {
    if (dp[v].empty()) {
        swap(dp[v], dp[u]);
        return;
    }
    if (dp[u].size() < dp[v].size()) swap(dp[u], dp[v]);
    for (int i = 0; i < (int) dp[v].size(); ++i) {
        dp[v][(int) dp[v].size() - 1 - i] ^= dp[u][(int) dp[u].size() - 1 - i];
    }
    dp[u].clear();
}

vector<int> path;

void dfs(int v) {
    dp[v] = {};
    if (g[v].empty()) {
        dp[v].push_back(0);
        dp[v].push_back(1);
        if (!path.empty()) {
            int u = path.front();
            rep(i, (int) path.size()) {
                dp[v].push_back(i + 2);
            }
            swap(dp[u], dp[v]);
            path.clear();
        }
        return;
    }
    if (g[v].size() == 1) {
        int u = g[v][0];
        path.push_back(v);
        dfs(u);
        return;
    }
    auto cur = path;
    path.clear();
    for (auto &u : g[v]) {
        dfs(u);
        merge(v, u);
    }
    vector<bool> have(dp[v].size() + 2 + cur.size(), false);
    rep(i, (int) dp[v].size()) {
        if (dp[v][i] < (int) have.size()) have[dp[v][i]] = true;
    }
    int sz = cur.size() + 1;
    for (int i = 0; i < (int) have.size(); ++i) {
        if (!have[i]) {
            dp[v].push_back(i);
            sz--;
            if (sz == 0) break;
        }
    }
    assert(sz == 0);
    if (!cur.empty()) {
        swap(dp[v], dp[cur.front()]);
        cur.clear();
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        g[i].clear();
        dp[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    int res = 0;
    for (auto &v : g[0]) {
        dfs(v);
        res ^= dp[v].back();
    }
    cout << (res != 0 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}