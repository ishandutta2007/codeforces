#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pst[10069],sq[10069],inf=1e18;

int main()
{
	long long i,ii,k,mx,e;
	pair<long long,long long> mxe;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		pst[i]=i;
	}
	for(i=2;i<=n;i++)
	{
		mxe={-inf,-1};
		for(ii=0;ii<2;ii++)
		{
			printf("? %lld %lld\n",pst[i-!ii],pst[i-ii]);
			fflush(stdout);
			scanf("%lld",&k);
			mxe=max(mxe,{k,ii});
		}
		mx=mxe.fr;
		e=mxe.sc;
		sq[pst[i-!e]]=mx;
		pst[i]=pst[i-e];
	}
	sq[pst[n]]=n;
	printf("!");
	for(i=1;i<=n;i++)
	{
		printf(" %lld",sq[i]);
	}
	printf("\n");
	fflush(stdout);
}