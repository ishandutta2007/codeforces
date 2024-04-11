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
const int V = 5100;
int a[V], n;
int dp[V][V];
int mi[V][V];
int dfs(int x, int y, int z) {
    //if (x == y) return 1;
    if (x == y) return min(a[x], 1);
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = y - x + 1;
    int tmp = mi[x][y] - z;
    int pre = x - 1;
    for (int i = x; i <= y; ++i) {
        if (a[i] == mi[x][y]) {
            if (pre + 1 <= i - 1) tmp += dfs(pre + 1, i - 1, mi[x][y]);
            pre = i;
        }
    }
    if (pre + 1 <= y) tmp += dfs(pre + 1, y, mi[x][y]);
    dp[x][y] = min(dp[x][y], tmp);
    //printf("D %d %d %d\n", x, y, dp[x][y]);
    return dp[x][y];
}
 
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) {
            mi[i][i] = a[i];
            for (int j = i + 1; j <= n; ++j) mi[i][j] = min(mi[i][j - 1], a[j]);
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(1, n, 0));
    }
    return 0;
}
 
/*
4
1 4 1 1
5
1 0 1 0 1
6
1 3 2 4 2 1
*/