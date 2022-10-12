#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 105;
const LL INF = 1000000000000000LL;

int n, m, k;
int c[N];
int a[N][N];

LL dp[N][N][N];
LL f(int x, int prev, int left) {
    if (left < 0) return INF;
    if (x == n) return left == 0 ? 0 : INF;
    
    LL &ret = dp[x][prev][left];
    if (~ret) return ret;
        
    if (c[x]) return ret = f(x+1, c[x], left - (c[x] != prev));
    
    ret = INF;
    for (int i=0; i<m; i++)
        ret = min(ret, f(x+1, i+1, left - (i+1 != prev)) + a[x][i]);
        
    return ret;
}

int main() {
    scanf ("%d %d %d", &n, &m, &k);
    for (int i=0; i<n; i++) scanf ("%d", c + i);
    
    for (int i=0; i<n; i++) 
        for (int j=0; j<m; j++) scanf ("%d", &a[i][j]);
        
    memset (dp, -1, sizeof dp);
    if (f(0, 0, k) >= INF) return 0 * printf ("-1\n");
    printf ("%I64d\n", f(0, 0, k));
    return 0;
}