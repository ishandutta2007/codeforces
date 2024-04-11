#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000007
using namespace std;
long long a[MAXN];
long long fastpow(long long st,long long a)
{
	if(st==0) return 1;
	if(st&1) return (a*fastpow(st-1,a))%MOD;
	return fastpow(st/2,(a*a)%MOD);
}
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		int n; long long p,d=0,rez=0;
		scanf("%d%lld",&n,&p);
		for(int i=0;i<n;i++) scanf("%lld",&a[i]);
		sort(a,a+n,greater<long long>());
		for(int i=0;i<n;i++)
		{
			if(i!=0 && p!=1 && d!=0 && d<9000000000LL) for(int j=0;j<a[i-1]-a[i];j++) {d=d*p; if(d>10000000000LL) break;}
			if(d>10000000000LL) d=10000000000LL;
			if(d==0) {rez=(rez+fastpow(a[i],p))%MOD; d=1; continue;}
			d--;
			rez=(rez+MOD-fastpow(a[i],p))%MOD;
		}
		printf("%lld\n",rez);
	}
}