#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 55;
int n, m, a[N], sum;
db dp[N][N], C[N][N], ans, dd;
db qpow(db x, int y) {
    db res = 1;
    L(i, 1, y) res = res * x;
    return res;
}
db solve(int x) {
    db res = 1;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    L(i, 1, m) L(j, 0, n) L(k, 0, min(a[i] * x, j)) 
        dp[i][j] += dp[i - 1][j - k] * C[j][k];
    return dp[m][n];
}
int main() {
    scanf("%d%d", &n, &m);
    dd = 1.0 / qpow(m, n);
    L(i, 0, n) C[i][0] = 1;
    L(i, 1, n) L(j, 1, i) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    L(i, 1, m) scanf("%d", &a[i]), sum += a[i];
    L(i, 0, n) ans += solve(i);
    printf("%.12lf\n", n + 1 - dd * ans);
    return 0;
}