#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300000 + 5;

int T, N, ans;
vector<int> ea[MAX_N];
vector<int> eb[MAX_N];

int fath[MAX_N], siz[MAX_N], dep[MAX_N], son[MAX_N], anc[MAX_N];
int dfn[MAX_N], dfn_, id[MAX_N];
set<int> s;

void dfs_tcp_1(int u, int fa) {
    fath[u] = fa;
    siz[u] = 1;
    dep[u] = dep[fa] + 1;
    for (int v: eb[u]) {
        dfs_tcp_1(v, u);
        siz[u] += siz[v];
        son[u] = siz[son[u]] < siz[v] ? v : son[u];
    }
}
void dfs_tcp_2(int u, int anc_) {
    anc[u] = anc_;
    dfn[u] = ++ dfn_;
    id[dfn_] = u;
    if (son[u]) {
        dfs_tcp_2(son[u], anc_);
    }
    for (int v: eb[u]) {
        if (v != son[u]) {
            dfs_tcp_2(v, v);
        }
    }
}
int find_insert_erase_anc(int u) {
    s.insert(dfn[u]);
    for (int v = fath[u]; v; v = fath[anc[v]]) {
        int tv = anc[v];
        auto it = s.lower_bound(dfn[tv]);
        if (it != s.end() && *it <= dfn[v]) {
            int x = id[*it];
            s.erase(it);
            return x;
        }
    }
    return 0;
}
void dfs(int u) {
    int x = find_insert_erase_anc(u);
    // printf("u=%d, x=%d\n", u, x);
    ans = max(ans, (int)s.size());
    for (int v: ea[u]) dfs(v);
    s.erase(dfn[u]);
    if (x) s.insert(dfn[x]);
}

int main() {
    scanf("%d", &T);
    for (; T --; ) {
        scanf("%d", &N);
        for (int i = 2, x; i <= N; i ++) {
            scanf("%d", &x), ea[x].push_back(i);
        }
        for (int i = 2, x; i <= N; i ++) {
            scanf("%d", &x), eb[x].push_back(i);
        }
        dfs_tcp_1(1, 0);
        dfs_tcp_2(1, 1);
        dfs(1);
        printf("%d\n", ans);

        for (int i = 1; i <= N; i ++) {
            ea[i].clear();
            eb[i].clear();
            fath[i] = siz[i] = dep[i] = anc[i] = son[i] = dfn[i] = id[i] = 0;
        }
        ans = dfn_ = 0;
    }
    return 0;
}