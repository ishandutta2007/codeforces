#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ub=30;
long long n,m,d,nn,a[200069],pc[1ll<<15],ex[15],dp[1ll<<15];

long long rand2()
{
	return (long long)rand()<<15|rand();
}

int main()
{
	long long rr,i,j,p,mk,e;
	pair<long long,long long> mxe,z={-1,-1};
	char ch;
	
	srand(time(NULL));
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf(" %c",&ch);
			a[i]|=(long long)(ch-'0')<<j;
		}
	}
	for(mk=0;mk<1ll<<d;mk++)
	{
		pc[mk]=__builtin_popcount(mk);
	}
	for(rr=0;rr<ub;rr++)
	{
		p=rand2()%n+1;
		nn=0;
		for(i=0;i<m;i++)
		{
			if(a[p]>>i&1)
			{
				ex[nn]=i;
				nn++;
			}
		}
		for(mk=0;mk<1ll<<nn;mk++)
		{
			dp[mk]=0;
		}
		for(i=1;i<=n;i++)
		{
			mk=0;
			for(j=0;j<nn;j++)
			{
				mk|=(a[i]>>ex[j]&1)<<j;
			}
			dp[mk]++;
		}
		for(i=0;i<nn;i++)
		{
			for(mk=0;mk<1ll<<nn;mk++)
			{
				if(!(mk>>i&1))
				{
					dp[mk]+=dp[mk|1ll<<i];
				}
			}
		}
		mxe={-1,-1};
		for(mk=0;mk<1ll<<nn;mk++)
		{
			if(dp[mk]>=(n+1)/2)
			{
				mxe=max(mxe,{pc[mk],mk});
			}
		}
		e=mxe.sc;
		mk=0;
		for(i=0;i<nn;i++)
		{
			mk|=(e>>i&1)<<ex[i];
		}
		z=max(z,{mxe.fr,mk});
	}
	e=z.sc;
	for(i=0;i<m;i++)
	{
		printf("%lld",e>>i&1);
	}
	printf("\n");
}