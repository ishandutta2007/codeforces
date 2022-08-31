#include <bits/stdc++.h>
 
#define nmax 100005
 
typedef long long ll;
 
 
ll m, n, l, r, p, num[nmax], d[nmax][6], ans, ii;
 
ll tt(ll ql, ll qh, ll mm) {
	qh = qh / mm; ql = (ql + mm - 1) / mm;
	return ((qh - ql + 1) * (n + 1) - mm * ((qh * (qh + 1) - (ql - 1) * ql) / 2)) % p;
}
 
int main() {
 
	scanf("%lld%lld", &n, &m);
	scanf("%lld%lld%lld", &l, &r, &p);
 
	for(int i = 2; i <= m; i++)
		if(num[i] == 0)
			for(int j = i; j <= m; j += i)
				d[j][num[j]++] = i;
 
    ll lo = l;
	ll hi = r;
    ll minn = (m < r ? m : r);
	for(ll w = 1; w <= minn; w++) {
		while(lo > 1 && l*l - w*w <= (lo-1)*(lo-1))
			lo--;
		while(r*r - w*w < hi*hi)
			hi--;
		if(lo <= hi && lo <= n) {
			ll a = 0;
			int t = (1 << num[w]);
			for(int i = 0; i < t; i++) {
				ii = i;
				ll p1 = 1;
				ll p2 = 1;
				for(int j = 0; j < num[w]; j++) {
					if(ii & 1) {
						p1 *= d[w][j];
						p2 *= -1;
					}
					ii >>= 1;
				}
				a += p2 * tt(lo, hi < n ? hi : n, p1);
			}
			ans = (ans + a*(m-w+1)) % p;
			if(ans < 0) ans += p;
		}
	}
 
	if(l <= 1 && r >= 1) ans = (2 * ans + m * (n + 1) + n * (m + 1)) % p;
	else ans = (2 * ans) % p;
	printf("%d\n", ans);
}