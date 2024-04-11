#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn=0,as[200069],pst[200069],dp[256],mx[256];
pair<long long,long long> a[2][200069];
map<long long,long long> com;

int main()
{
	long long i,j,ii,k,p[2],mk,cm=0,cr=0,z=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	com[0]=1;
	nn++;
	as[nn]=m;
	com[m]=1;
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",p+ii);
			p[ii]-=!ii;
			a[ii][i]={p[ii],i};
			if(!com[p[ii]])
			{
				nn++;
				as[nn]=p[ii];
				com[p[ii]]=1;
			}
		}
	}
	sort(as,as+nn+1);
	for(i=0;i<=nn;i++)
	{
		com[as[i]]=i;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			a[ii][i].fr=com[a[ii][i].fr]+!ii;
		}
		sort(a[ii]+1,a[ii]+n+1);
	}
	for(p[0]=1,p[1]=1,i=1;i<=nn;i++)
	{
		for(;p[0]<=n&&a[0][p[0]].fr<=i;p[0]++)
		{
			for(j=0;cr>>j&1;j++);
			cr|=1<<j;
			pst[a[0][p[0]].sc]=j;
		}
		for(mk=0;mk<1<<d;mk++)
		{
			dp[mk]=-1e18;
			if((mk&cr)==mk)
			{
				k=__builtin_popcount(mk);
				dp[mk]=mx[mk&cm]+(as[i]-as[i-1])*(k%2);
			}
		}
		for(;p[1]<=n&&a[1][p[1]].fr<=i;p[1]++)
		{
			cr^=1<<pst[a[1][p[1]].sc];
		}
		cm=cr;
		for(mk=0;mk<1<<d;mk++)
		{
			mx[mk]=-1e18;
			mx[mk&cm]=max(mx[mk&cm],dp[mk]);
			if(i==nn)
			{
				z=max(z,dp[mk]);
			}
		}
	}
	printf("%lld\n",z);
}