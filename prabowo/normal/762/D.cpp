#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long INF = 1e18;

int n;
int a[3][N];

long long dp[3][N][2];
long long f(int x, int y, int z) {
    if (y == n-1) {
        if (z) {
            if (x == 0) return 1LL * a[0][y] + a[1][y] + a[2][y];
            return -INF;
        }
        
        if (x == 0) return 1LL * a[0][y] + a[1][y] + a[2][y];
        if (x == 1) return a[1][y] + a[2][y];
        return a[2][y];
    }
    
    if (~dp[x][y][z]) return dp[x][y][z];
    
    if (z) return dp[x][y][z] = max(f(x, y+1, 1), f(2-x, y+1, 0)) + a[0][y] + a[1][y] + a[2][y];
    
    if (x == 0 || x == 2) return dp[x][y][z] = a[x][y] + 
        max( max(f(x, y+1, 1), f(2-x, y+1, 0)) + a[1][y] + a[2-x][y], 
             max(f(x, y+1, 0), f(1, y+1, 0) + a[1][y]) );
             
    return dp[x][y][z] = a[1][y] + max(f(x, y+1, 0), max(f(0, y+1, 0) + a[0][y], f(2, y+1, 0) + a[2][y]));
}

int main() {
    memset(dp, -1, sizeof dp);
    
    scanf("%d", &n);
    for (int i=0; i<3; i++) for (int j=0; j<n; j++) scanf("%d", &a[i][j]);
    
    printf("%lld\n", f(0, 0, 0));
    return 0;
}