#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath> 
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

int n;

map<ll,ll>c1,c2;

ll w[N],h[N],c[N],g;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&w[i],&h[i],&c[i]),g=__gcd(g,c[i]);
	ll tot=0;
	for(int i=1;i<=n;i++)
	{
		c[i]/=g;
		tot+=c[i];
		c1[w[i]]+=c[i];
		c2[h[i]]+=c[i];
	}
	double eps=1e-15;
	for(int i=1;i<=n;i++)
	{
		double p1=(double)c1[w[i]]/(double)tot;
		double p2=(double)c[i]/(double)c2[h[i]];
		if(abs(p1-p2)>eps)
		{
			puts("0");
			return 0;
		}
	}
	ll ans=0;
	for(ll i=1;i*i<=g;i++)
		if(g%i==0)
		{
			ans++;
			if(i*i!=g)
				ans++;
		}
	printf("%lld",ans);
}