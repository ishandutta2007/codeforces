#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db long double
#define mp make_pair
const int N = 2010;
const int M = 13;
int n, m, cN, a[M][N], dp[1 << M], sum[1 << M], dd[1 << M];
void mian() {
    scanf("%d%d", &n, &m), cN = (1 << n);
    fill(dp, dp + cN, 0);
    L(i, 1, n) L(j, 1, m) scanf("%d", &a[i][j]);
    L(d, 1, m) {
        L(i, 1, n) sum[1 << (i - 1)] = a[i][d];
        L(i, 1, cN - 1) sum[i] = sum[i & -i] + sum[i ^ (i & -i)];
        L(t, 1, n) L(i, 0, cN - 1) sum[i] = max(sum[i], sum[(i >> 1) | ((i & 1) * (cN >> 1))]);
        R(i, cN - 1, 1) for(int j = i; j; j = ((j - 1) & i)) 
            dp[i] = max(dp[i], dp[i ^ j] + sum[j]);
    }
    printf("%d\n", dp[cN - 1]);
}
int main() {
    int T; scanf("%d", &T);
    while(T--) mian();
    return 0;
}