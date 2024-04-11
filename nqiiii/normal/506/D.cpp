#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000, blksz = 500;
int n, m, q;
vector<pair<int, int> > co[maxn + 10];
vector<int> vec, g[maxn + 10], tot;
map<int, int> mp[maxn + 10];
bool vis[maxn + 10];
int fa[maxn / blksz + 10][maxn + 10], cocnt;

void addeg(int l, int r) {
    if (g[l].empty()) vec.push_back(l);
    g[l].push_back(r);
}

void dfs(int p) {
    vis[p] = 1; tot.push_back(p);
    for (int i = 0; i < (int)g[p].size(); ++i) {
        int e = g[p][i];
        if (!vis[e]) dfs(e);
    }
}

int getf(int co, int x) {
    return fa[co][x] == x ? x : fa[co][x] = getf(co, fa[co][x]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int l, r, w; scanf("%d%d%d", &l, &r, &w);
        co[w].push_back(make_pair(l, r));
    }
    for (int i = 1; i <= m; ++i)
        if (co[i].size() < blksz) {
            vec.clear();
            for (int j = 0; j < (int)co[i].size(); ++j) {
                addeg(co[i][j].first, co[i][j].second);
                addeg(co[i][j].second, co[i][j].first);
            }
            for (int j = 0; j < (int)vec.size(); ++j) {
                int p = vec[j];
                if (!vis[p]) {
                    tot.clear(); dfs(p);
                    for (int k = 0; k < (int)tot.size(); ++k)
                        for (int l = 0; l < (int)tot.size(); ++l)
                            if (k != l) ++mp[tot[k]][tot[l]];
                }
            }
            for (int j = 0; j < (int)vec.size(); ++j) {
                int p = vec[j]; g[p].clear(); vis[p] = 0;
            }
        } else {
            ++cocnt;
            for (int j = 1; j <= n; ++j) fa[cocnt][j] = j;
            for (int j = 0; j < (int)co[i].size(); ++j)
                fa[cocnt][getf(cocnt, co[i][j].first)] = getf(cocnt, co[i][j].second);
        }
    scanf("%d", &q);
    while (q--) {
        int x, y, ans = 0; scanf("%d%d", &x, &y);
        for (int i = 1; i <= cocnt; ++i)
            ans += getf(i, x) == getf(i, y);
        printf("%d\n", ans + mp[x][y]);
    }
}