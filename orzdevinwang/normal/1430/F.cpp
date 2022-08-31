#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--) 
#define ll long long 
#define db double 
using namespace std;
const int N = 3007;
int n;
ll m, l[N], r[N], a[N], dp[N], now, ans;
int main() {
    scanf("%d%lld", &n, &m);
    L(i, 1, n) scanf("%lld%lld%lld", &l[i], &r[i], &a[i]);
    R(i, n, 1) {
        int toadd = a[i] + ((r[i] != l[i + 1]) ? 0 : dp[i + 1]);
        if(toadd > (r[i] - l[i] + 1) * m) return puts("-1"), 0;
        dp[i] = max(0ll, toadd - (r[i] - l[i]) * m);
    }
    L(i, 1, n) {
        if(m - now < dp[i]) ans += m - now, now = 0;
        ans += a[i], now = (now + a[i]) % m;
    }
    printf("%lld\n", ans);
    return 0;
}