#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 112345;
const int maxm = 312;
const ll MOD = 1e9 + 7;

int n, q;
int st[maxn << 1][19], dep[maxn], in[maxn], out[maxn], h[maxn], a[maxn], clk, fen[maxn << 1];
int dp[maxn][maxm];
bool vis[maxn];

vector<int> G[maxn];

void dfs(int u, int par) {
    in[u] = ++clk;
    st[clk][0] = u;
    for (int v : G[u]) if (v != par) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
            st[++clk][0] = u;
        }
    out[u] = clk;
}

void rmq_init() {
    FOR(i, 1, clk) FOR(j, 1, 18) {
            st[i][j] = st[i][j - 1];
            int val = i - (1 << j - 1);
            if (val > 0 && dep[st[val][j - 1]] < dep[st[i][j]])
                st[i][j] = st[val][j - 1];
        }
}

int rmq(int l, int r) {
    int val = floor(log(r - l + 1) / log(2));
    int u = st[l + (1 << val) - 1][val], v = st[r][val];
    return dep[u] < dep[v] ? u : v;
}

int lca(int u, int v) {
    if (in[u] > in[v]) swap(u, v);
    return rmq(in[u], in[v]);
}

inline int lowbit(int x) {
    return x & -x;
}

void update(int x, int d) {
    while (x < 2 * maxn) {
        fen[x] += d;
        x += lowbit(x);
    }
}

int query(int x) {
    int ret = 0;
    while (x > 0) {
        ret += fen[x];
        x -= lowbit(x);
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &q);
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].eb(v);
        G[v].eb(u);
    }
    dfs(1, 0);
    dp[0][0] = 1;
    rmq_init();
    while (q--) {
        int k, m, r;
        scanf("%d%d%d", &k, &m, &r);
        FOR(i, 1, k) {
            scanf("%d", a + i);
            vis[a[i]] = true;
            update(in[a[i]], 1);
            update(out[a[i]] + 1, -1);
        }
        FOR(i, 1, k) {
            int now = a[i], par = lca(r, now);
            h[now] = query(in[now]) + query(in[r]) - 2 * query(in[par]) - (!vis[par]);
        }
        sort(a + 1, a + k + 1, [](int a, int b) { return h[a] < h[b]; });
        reset(dp[1], 0);
        FOR(i, 1, k) FOR(j, 1, m) dp[i][j] = (ll(dp[i - 1][j]) * (j - h[a[i]]) + dp[i - 1][j - 1]) % MOD;
        ll ans = 0;
        FOR(i, 1, m) ans = (ans + dp[k][i]) % MOD;
        printf("%lld\n", ans);
        FOR(i, 1, k) {
            update(in[a[i]], -1);
            update(out[a[i]] + 1, 1);
            vis[a[i]] = false;
        }
    }
}