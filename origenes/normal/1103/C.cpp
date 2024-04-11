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

const int maxn = 251234;

bool path;
int n, k, m, dep[maxn], f[maxn], lim;
vector<int> G[maxn], back[maxn], leaves;

void dfs(int u, int p) {
    bool lv = true;
    f[u] = p;
    dep[u] = dep[p] + 1;
    if (dep[u] >= lim) {
        path = true;
        puts("PATH");
        printf("%d\n", dep[u]);
        printf("%d ", u);
        return;
    }
    for (int v : G[u]) {
        if (dep[v]) {
            if (v != p) back[u].eb(v);
            continue;
        }
        lv = false;
        dfs(v, u);
        if (path) {
            printf("%d ", u);
            return;
        }
    }
    if (lv) leaves.eb(u);
}

bool check(int lv, int par) {
    if ((dep[lv] - dep[par] + 1) % 3 == 0) return false;
    printf("%d\n", dep[lv] - dep[par] + 1);
    for (int u = lv; u != par; u = f[u]) printf("%d ", u);
    printf("%d\n", par);
    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    lim = n / k + (n % k > 0);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].eb(v);
        G[v].eb(u);
    }
    dfs(1, 0);
    if (path) return 0;
    puts("CYCLES");
    assert(leaves.size() >= k);
    REP(i, k) {
        int u = leaves[i];
        assert(back[u].size() >= 2);
        int p = back[u][0], q = back[u][1];
        if (dep[p] > dep[q]) swap(p, q);
        if (check(u, p)) continue;
        if (check(u, q)) continue;
        printf("%d\n", dep[q] - dep[p] + 2);
        printf("%d ", u);
        for (int v = q; v != p; v = f[v]) printf("%d ", v);
        printf("%d\n", p);
    }
}