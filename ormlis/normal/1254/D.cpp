#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int mid = binpow(a, b / 2);
    return mul(mid, mid);
}

int rev(int a) {
    return binpow(a, md - 2);
}

int fenw[maxN];
int q;

void upd(int i, int x) {
    for (; i < maxN; i = i | (i + 1)) fenw[i] = add(fenw[i], x);
}

int get(int i) {
    int res = 0;
    for (; ~i; i = ((i + 1) & i) - 1) res = add(res, fenw[i]);
    return res;
}

int dp[maxN];
vector<pair<int, int>> req1[maxN];
vector<int> req2[maxN];
int ans[maxN];

vector<int> g[maxN];

void dfs(int v, int p) {
    dp[v] = 1;
    for (auto &u: g[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v] += dp[u];
    }
}

void dfs_calc(int v, int p) {
    for (auto &req: req1[v]) {
        upd(req.first, mul(req.second, dp[v]));
    }
    for (auto &u: g[v]) {
        if (u == p) continue;
        dfs_calc(u, v);
    }
}

bool cmp(int &a, int &b) {
    return dp[a] < dp[b];
}

int n;
void re_root(int v, int p) {
    for(auto &req: req1[v]) {
        upd(req.first, mul(req.second, sub(n, dp[v])));
    }
    for(auto &req: req2[v]) {
        ans[req] = mul(get(req), rev(n));
    }
    int prev = n;
    sort(all(g[v]), cmp);
    for(auto &u: g[v]) {
        if (u == p) continue;
        int cur = n - dp[u];
        if (cur != prev) {
            for(auto &req: req1[v]) {
                upd(req.first, mul(req.second, sub(cur, prev)));
            }
            prev = cur;
        }
        re_root(u, v);
    }
    for(auto &req: req1[v]) {
        upd(req.first, mul(req.second, sub(dp[v], prev)));
    }
}

void solve() {
    cin >> n >> q;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> qw;
    range(i, q) {
        int t, v; cin >> t >> v;
        if (t == 1) {
            int d; cin >> d;
            req1[v].emplace_back(i, d);
        } else {
            qw.push_back(i);
            req2[v].push_back(i);
        }
    }

    dfs(1, -1);
    dfs_calc(1, -1);
    re_root(1, -1);

    for(auto &i: qw) cout << ans[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}