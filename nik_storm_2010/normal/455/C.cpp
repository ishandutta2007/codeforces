#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
const int N = 4e5;

vector <int> edges[N];
int parent[N], minpath[N], maxpath[N], best1[N], best2[N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void dfs(int x, int prev) {
    for (int i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (to == prev) continue;
        dfs(to, x);
        if (best1[to] + 1 > best1[x]) {
            swap(best1[x], best2[x]);
            best1[x] = best1[to] + 1;
        }
        else
        if (best1[to] + 1 > best2[x]) best2[x] = best1[to] + 1;
    }
}

void solve(int x, int prev, int father, int leng) {
    int cur = max(leng, best1[x]);
    minpath[father] = min(minpath[father], cur);
    maxpath[father] = max(maxpath[father], cur);
    parent[x] = father;
    for (int i = 0; i < edges[x].size(); i++) {
        int to = edges[x][i];
        if (to == prev) continue;
        int add;
        if (best1[x] == best1[to] + 1) add = best2[x]; else add = best1[x];
        add = max(leng + 1, add + 1);
        solve(to, x, father, add);
    }
}

int main() {
    srand(time(NULL));
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (parent[i] != 0) continue;
        dfs(i, i);
        minpath[i] = +2e9;
        maxpath[i] = -2e9;
        solve(i, i, i, 0);
    }
    for (int i = 1; i <= q; i++) {
        int type, x, y;
        scanf("%d %d", &type, &x);
        if (type == 1) printf("%d\n", maxpath[find(x)]); else {
            scanf("%d", &y);
            x = find(x), y = find(y);
            if (x == y) continue;
            if (rand() % 2) swap(x, y);
            parent[x] = y;
            maxpath[y] = max(minpath[x] + minpath[y] + 1, max(maxpath[x], maxpath[y]));
            minpath[y] = min(max(minpath[x], minpath[y] + 1), max(minpath[y], minpath[x] + 1));
        }
    }
    return 0;
}