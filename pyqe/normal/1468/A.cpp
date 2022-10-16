#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[500069],sk[500069],lis[500069],sq[500069],inf=1e18;
vector<long long> cd[500069];

long long qr(long long x)
{
	return upper_bound(lis+1,lis+n+1,x)-lis-1;
}

int main()
{
	long long t,rr,i,j,l,sz,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			cd[i].clear();
			lis[i]=inf;
			sq[i]=0;
		}
		nn=0;
		for(i=n;i;i--)
		{
			for(;nn&&a[sk[nn]]<=a[i];nn--)
			{
				cd[i].push_back(sk[nn]);
			}
			nn++;
			sk[nn]=i;
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			sz=cd[i].size();
			for(j=0;j<sz;j++)
			{
				l=cd[i][j];
				sq[l]=max(sq[l],qr(a[l])+2);
			}
			sq[i]=max(sq[i],qr(a[i])+1);
			z=max(z,sq[i]);
			for(j=sq[i]-1;j<=sq[i];j++)
			{
				lis[j]=min(lis[j],a[i]);
			}
		}
		printf("%lld\n",z);
	}
}