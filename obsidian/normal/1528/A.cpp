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
const int V = 100100;
vector<int> g[V];
LL dp[V][2];
int l[V], r[V];

void dfs(int u, int fa) {
    dp[u][0] = dp[u][1] = 0;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        dp[u][0] = dp[u][0] + max(dp[v][0] + abs(l[v] - l[u]), dp[v][1] + abs(r[v] - l[u]));
        dp[u][1] = dp[u][1] + max(dp[v][0] + abs(l[v] - r[u]), dp[v][1] + abs(r[v] - r[u]));
    }
}
int _, n, u, v;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i], &r[i]);
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g[v].PB(u);
        }
        dfs(1, -1);
        printf("%I64d\n", max(dp[1][0], dp[1][1]));
    }
    return 0;
}

/*
3
2
1 6
3 8
1 2
3
1 3
4 6
7 9
1 2
2 3
6
3 14
12 20
12 19
2 12
10 17
3 17
3 2
6 5
1 5
2 6
4 6
*/