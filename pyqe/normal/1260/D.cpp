#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ln,m,d,a[200069];
pair<pair<long long,long long>,long long> rg[200069];

int main()
{
	long long i,lh,rh,md,zz,k,l,w,sm,ls,mx;
	
	scanf("%lld%lld%lld%lld",&n,&ln,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,greater<long long>());
	a[0]=1e18;
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		rg[i]={{k-1,l},w};
	}
	sort(rg,rg+m);
	lh=0;
	rh=n;
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=ln+1;
		ls=-1;
		mx=-1;
		for(i=0;i<m;i++)
		{
			k=rg[i].fr.fr;
			l=rg[i].fr.sc;
			w=rg[i].sc;
			if(w>a[md])
			{
				if(k>mx)
				{
					sm+=(mx-ls)*2;
					ls=k;
				}
				mx=max(mx,l);
			}
		}
		sm+=(mx-ls)*2;
		if(sm<=d)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz);
}