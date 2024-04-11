#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair 
const int N = 1e3 + 7;
const db eps = 1e-14;
db dp[N][N];
db F(int n, int m) {
    if(dp[n][m] > eps) return dp[n][m];
    if(m == 0) return dp[n][m] = 1;
    if(n == 0) return dp[n][m] = 1. / (m + 1);
    db x = 1. / (m + 2 - (1. - F(m, n - 1)) * (m + 1));
    return dp[n][m] = max(1. / (m + 1), x + (1 - x) * ((1 - F(m - 1, n)) * m / (m + 1)));
}
int x, y;
int main() {
    scanf("%d%d", &x, &y);
    db ans = F(x, y);
    printf("%.10lf %.10lf\n", ans, 1. - ans);
	return 0;
}