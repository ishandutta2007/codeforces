#include <bits/stdc++.h>

using namespace std;

long long n,a[169][2];
map<array<long long,169>,bool> vtd;
map<array<long long,169>,long long> e;
array<long long,169> tmp;

int main()
{
	long long i,j,k,mn,mx;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		a[i][0]=k%(1<<15);
		a[i][1]=k/(1<<15);
	}
	for(i=0;i<1<<15;i++)
	{
		mn=1e18;
		for(j=0;j<n;j++)
		{
			tmp[j]=__builtin_popcount(a[j][0]^i);
			mn=min(mn,tmp[j]);
		}
		for(j=0;j<n;j++)
		{
			tmp[j]-=mn;
		}
		vtd[tmp]=1;
		e[tmp]=i;
	}
	for(i=0;i<1<<15;i++)
	{
		mx=-1e18;
		for(j=0;j<n;j++)
		{
			tmp[j]=__builtin_popcount(a[j][1]^i);
			mx=max(mx,tmp[j]);
		}
		for(j=0;j<n;j++)
		{
			tmp[j]=mx-tmp[j];
		}
		if(vtd[tmp])
		{
			printf("%lld\n",i*(1<<15)+e[tmp]);
			return 0;
		}
	}
	printf("-1\n");
}