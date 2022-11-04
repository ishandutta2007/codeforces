#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005;
int n, cnt, ans[N];
ll x[N], y[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%lld%lld", x+i, y+i);
	for(int i=n; i; --i) x[i]=(ll)(x[i]-x[1])*(x[i]-x[1])+(ll)(y[i]-y[1])*(y[i]-y[1]);
	ll t=0;
	for(int i=2; i<=n; ++i) t=__gcd(t, x[i]);
	for(int i=1; i<=n; ++i) if(x[i]/t%2) ans[++cnt]=i;
	printf("%d\n", cnt);
	for(int i=1; i<=cnt; ++i) printf("%d%c", ans[i], " \n"[i==cnt]);
	return 0;
}