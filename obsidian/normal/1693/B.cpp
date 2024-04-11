#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 200100;
vector<int> g[V];
int l[V], r[V], up[V], n, ans, _;
void dfs(int u) {
    LL s = 0;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        dfs(v);
        s += up[v];
    }
    if (s < l[u]) {++ans, up[u] = r[u];}
    else up[u] = min(s, (LL) r[u]);
}

int x;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &x);
            g[x].PB(i);
        }
        for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i], &r[i]);
        ans = 0;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
2
1
1 5
2 9
3
1 1
4 5
2 4
6 10
4
1 2 1
6 9
5 6
4 5
2 4
5
1 2 3 4
5 5
4 4
3 3
2 2
1 1
*/