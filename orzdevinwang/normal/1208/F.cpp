#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long
#define db double
#define mp make_pair
const int N = 2.2e6 + 7;
int n, m, dp[22][N], a[N], ans;
void dfs(int x, int k) {
    if(k > 20) return;
    if(dp[k][x] >= 2) return;
    dp[k][x]++;
    dfs(x, k + 1);
    if((x >> k) & 1) dfs(x ^ (1 << k), k + 1);
}
int main() {
    scanf("%d", &n);
    L(i, 1, n) scanf("%d", &a[i]);
    R(i, n, 1) {
        int now = 0;
        R(j, 20, 0) if(!((a[i] >> j) & 1)) 
            if(dp[20][now | (1 << j)] >= 2) 
                now |= (1 << j);
        if(i <= n - 2) ans = max(ans, now | a[i]);
        dfs(a[i], 0);
    }
    printf("%d\n", ans);
    return 0;
}