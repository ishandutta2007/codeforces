#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int N = 1e3 + 7;
const int M = 33;
const int mod = 7340033;
int n, m, q, dp[M][N];
int find(int x) { return (x % 2 == 0 || x == 1) ? 1 : find((x - 1) / 2) + 1; }
int main() {
    scanf("%d", &q);
    dp[1][0] = 1;
    L(i, 2, 30) {
        dp[i][1] = 1;
        L(t, 1, 4) R(j, 1000, 1) R(k, j, 1) (dp[i][j] += 1ll * dp[i - 1][k] * dp[i][j - k] % mod) %= mod;
        dp[i][0] = 1;
    }
    while(q--) {
        scanf("%d%d", &n, &m);
        printf("%d\n", dp[find(n)][m]);
    }
    return 0;
}