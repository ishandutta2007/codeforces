#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,st[2],pst[20],dp[2][1ll<<20];
pair<long long,long long> a[1000069];

int main()
{
	long long i,ii,u,k,l,mk,c;
	pair<long long,pair<long long,long long>> z={-1,{-1,-1}};
	char ch;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<d;i++)
		{
			scanf(" %c",&ch);
			k=(ch-'0');
			st[ii]|=k<<i;
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		k--;
		l--;
		a[i]={k,l};
	}
	for(mk=0;mk<1ll<<d;mk++)
	{
		dp[0][mk]=n+1;
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		mk=st[ii];
		for(i=0;i<d;i++)
		{
			pst[i]=i;
		}
		for(i=n+1;i;i--)
		{
			if(i<=n)
			{
				k=a[i].fr;
				l=a[i].sc;
				mk=(mk&((1ll<<d)-1^1ll<<pst[k]^1ll<<pst[l]))|(mk>>pst[k]&1)<<pst[l]|(mk>>pst[l]&1)<<pst[k];
				swap(pst[k],pst[l]);
			}
			dp[ii][mk]=min(dp[ii][mk]*u,i*u)*u;
		}
		for(mk=(1ll<<d)-1;mk+1;mk--)
		{
			for(i=0;i<d;i++)
			{
				dp[ii][mk]=min(dp[ii][mk]*u,dp[ii][mk|1ll<<i]*u)*u;
			}
		}
	}
	for(mk=0;mk<1ll<<d;mk++)
	{
		if(dp[1][mk]-dp[0][mk]>=m)
		{
			c=0;
			for(i=0;i<d;i++)
			{
				c+=mk>>i&1;
			}
			z=max(z,{c,{dp[0][mk],dp[1][mk]-1}});
		}
	}
	z.fr=z.fr*2+d;
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<d;i++)
		{
			z.fr-=st[ii]>>i&1;
		}
	}
	printf("%lld\n%lld %lld\n",z.fr,z.sc.fr,z.sc.sc);
}