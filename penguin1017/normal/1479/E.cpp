using namespace std;
#include <bits/stdc++.h>
#define N 1505
#define ll long long
#define mo 998244353
int m;
int a[N],n;
ll qpow(ll x,ll y=mo-2){
	ll r=1;
	for (;y;y>>=1,x=x*x%mo)
		if (y&1)
			r=r*x%mo;
	return r;
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d",&m);
	for (int i=1;i<=m;++i)
		scanf("%d",&a[i]),n+=a[i];
	sort(a+1,a+m+1);
	ll ans=0;
	register ll sp=0,sq=1,tp=1,tq=1;
	for (register int i=0,j=1;i<n;++i){
		tp=tp*((n<<1)-i)%mo;
		tq=tq*(n-i)%mo;
		sp=(sp*tq+sq*tp)%mo;
		sq=sq*tq%mo;
		for (;j<=m && a[j]==i+1;++j)
			(ans+=sp*qpow(sq))%=mo;
	}
	printf("%lld\n",(sp*qpow(sq)-ans+mo)%mo);
	return 0;
}