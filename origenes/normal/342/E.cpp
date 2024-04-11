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

int n, m, dis[maxn], st[maxn << 1][18], dep[maxn], in[maxn], clk;
vector<int> G[maxn], lis;

void bfs() {
    queue<pii> q;
    for (int v : lis) q.push(mp(v, 0));
    while (!q.empty()) {
        auto now = q.front(); q.pop();
        int u = now._1, d = now._2;
        if (dis[u] > d) {
            dis[u] = d;
            for (int v : G[u]) q.push(mp(v, d + 1));
        }
    }
}

void dfs(int u, int par) {
    in[u] = ++clk;
    st[clk][0] = u;
    for (int v : G[u]) if (v != par) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
            st[++clk][0] = u;
        }
}

void rmq_init() {
    FOR(i, 1, clk) FOR(j, 1, 17) {
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

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].eb(v);
        G[v].eb(u);
    }
    lis.eb(1);
    int b = sqrt(m) + 0.5;
    vector<pii> qry;
    REP(i, m) {
        int op, u;
        scanf("%d%d", &op, &u);
        qry.eb(op, u);
    }
    dfs(1, 0);
    rmq_init();
    reset(dis, 0x3f);
    for (int i = 0; i * b < m; i++) {
        bfs();
        lis.clear();
        REP(j, b) {
            int idx = i * b + j;
            if (idx >= m) break;
            if (qry[idx]._1 == 1) lis.eb(qry[idx]._2);
            else {
                int u = qry[idx]._2, ans = dis[u];
                for (int v : lis)
                    ans = min(ans, dep[u] + dep[v] - 2 * dep[lca(u, v)]);
                printf("%d\n", ans);
            }
        }
    }
}