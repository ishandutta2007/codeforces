#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = j; i <= k; i++) 
#define R(i, j, k) for(int i = j; i >= k; i--) 
#define ll long long 
#define db double 
#define pb(a) push_back(a)
#define sz(a) (int)(a.size())
const int N = 18;
int n;
db g[N + 10][N + 10], dp[1 << N];
int main() {
    scanf("%d", &n);
    L(i, 1, n) L(j, 1, n) scanf("%lf", &g[i][j]);
    dp[(1 << n) - 1] = 1;
    R(i, (1 << n) - 1, 1) {
        db now = 0;
        L(j, 1, n) if((1 << (j - 1)) & i) L(k, 1, n) if((1 << (k - 1)) & i) now += g[j][k];
        L(j, 1, n) if((1 << (j - 1)) & i) L(k, 1, n) if((1 << (k - 1)) & i) 
            dp[(1 << (k - 1)) ^ i] += dp[i] * g[j][k] / now;
    }
    L(i, 1, n) printf("%lf ", dp[1 << (i - 1)]);
    puts("");
    return 0;
}