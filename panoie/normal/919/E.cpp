#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
using namespace std;
#define ll long long
#define rt register int
#define reep(i,x,y) for(rt i=(x);i<(y);++i)
#define per(i,x,y) for(rt i=(x);i>=(y);--i)
#define rep(i,x,y) for(rt i=(x);i<=(y);++i)
#define travel(i,x) for(rt i=h[x];i;i=pre[i])
int a, b, p;
ll x, ans;
inline ll Pow(ll x, rt y){
	ll ass=1;
	for(; y; y>>=1, x=x*x%p) if(y&1) ass=ass*x%p;
	return ass;
}
int main() {
	scanf("%d%d%d%lld", &a, &b, &p, &x);
	rep(i, 1, p-1){
		ll limit=(x-i)/(p-1), y=(b*Pow(Pow(a, i), p-2)-i+p)%p*Pow(p-1, p-2)%p;
		if(i+y*(p-1)<=x) ans+=(limit-y)/p+1;
	}
	printf("%lld", ans);
	return 0;
}