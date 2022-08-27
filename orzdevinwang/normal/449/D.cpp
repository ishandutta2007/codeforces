#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long
#define db double
#define mp make_pair
const int N = 1048575;
const int P = 1e6 + 7;
const int mod = 1e9 + 7;
int n, m, a[N], tpow[N], cnt[N + 3], dp[N + 3], ans;
int main() {
    scanf("%d", &n);
    tpow[0] = 1;
    L(i, 1, n) tpow[i] = 2 * tpow[i - 1] % mod;
    L(i, 1, n) scanf("%d", &a[i]), dp[a[i]]++;
    L(i, 0, 19) L(j, 0, N) if(!(j & (1 << i))) dp[j] += dp[j ^ (1 << i)];
    L(i, 0, N) dp[i] = tpow[dp[i]];
    L(i, 0, N) {
        cnt[i] = cnt[i >> 1] + (i & 1);
        if(cnt[i] % 2) (ans += mod - dp[i]) %= mod;
        else (ans += dp[i]) %= mod;
    }
    printf("%d\n", ans);
    return 0;
}