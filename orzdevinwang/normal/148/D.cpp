#include<bits/stdc++.h>
#define N 1010
#define db double
using namespace std;
int n, m;
bool used[N][N];
db dp[N][N]; // A 
db dfs(int x, int y, int who) { // 0 : A  1: B
    if(used[x][y]) return dp[x][y];
    if(x == 0) return 0.0;
    if(y <= 0) return 1.0 - who;
    db gl = 1.0 * y / (x + y);
    used[x][y] = 1;
    if(who == 0) return dp[x][y] = gl * dfs(x, y - 1, 1) + (1 - gl);
    else return dp[x][y] = gl * ((y - 1) * dfs(x, y - 2, 0) + x * dfs(x - 1, y - 1, 0)) / (x + y - 1);
}
int main() {
    scanf("%d%d", &n, &m);
    printf("%.15lf\n", dfs(n, m, 0));
    return 0;
}