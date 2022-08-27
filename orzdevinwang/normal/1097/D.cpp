#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int mod = 1e9 + 7;
ll n, p[99], num[99999], pnum[99999];
int m, ny[99], d[99], gl[99999], pl[99999], wss, cnt, dp[99], ans;
int main() {
    scanf("%lld%d", &n, &m);
    ny[1] = 1;
    L(i, 2, 90) ny[i] = 1ll * (mod - mod / i) * ny[mod % i] % mod;
    int maxn = sqrt(n);
    L(i, 2, maxn) if(n % i == 0) {
        d[++cnt] = 0, p[cnt] = i;
        while(n % i == 0) n /= i, d[cnt] ++;
    }
    if(n != 1) d[++cnt] = 1, p[cnt] = n;
    num[1] = pl[1] = 1, wss = 1;
    L(i, 1, cnt) {
        L(j, 0, d[i]) dp[j] = 0;
        dp[d[i]] = 1;
        L(t, 1, m) {
            int sum = 0;
            R(j, d[i], 0) (sum += 1ll * ny[j + 1] * dp[j] % mod) %= mod, dp[j] = sum;
        }
        L(j, 1, wss) gl[j] = pl[j], pnum[j] = num[j];
        int tot = 0; ll now;
        L(j, 1, wss) {
            now = 1;
            L(k, 0, d[i]) num[++tot] = now * pnum[j], pl[tot] = 1ll * dp[k] * gl[j] % mod, now *= p[i];
        }
        wss = tot;
    }
    L(i, 1, wss) (ans += num[i] % mod * pl[i] % mod) %= mod;
    printf("%d\n", ans);
    return 0;
}