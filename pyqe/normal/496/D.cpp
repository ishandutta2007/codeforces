#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ps[2][100069],zs=0,inf=1e18;
pair<long long,long long> sq[100069];

int main()
{
	long long i,ii,k,p,c[2],mn,e;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(ii=0;ii<2;ii++)
		{
			ps[ii][i]=ps[ii][i-1];
		}
		ps[k-1][i]++;
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			c[ii]=0;
		}
		for(p=0;p<n;p=mn)
		{
			mn=inf;
			for(ii=0;ii<2;ii++)
			{
				mn=min(mn,(long long)(lower_bound(ps[ii]+1,ps[ii]+n+1,ps[ii][p]+i)-ps[ii]));
			}
			if(mn>n)
			{
				p=-1;
				break;
			}
			e=ps[1][mn]-ps[1][mn-1];
			c[e]++;
		}
		if(p==-1||c[e]<=c[!e])
		{
			continue;
		}
		zs++;
		sq[zs]={c[e],i};
	}
	sort(sq+1,sq+zs+1);
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}