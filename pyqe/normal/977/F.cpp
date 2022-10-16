#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[200069],sq[200069],zs=0;
map<long long,long long> dp,ls;

int main()
{
	long long i,k,e;
	pair<long long,long long> mxe={0,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pr[i]=ls[k-1];
		dp[k]=dp[k-1]+1;
		ls[k]=i;
		mxe=max(mxe,{dp[k],i});
	}
	e=mxe.sc;
	for(k=e;k;k=pr[k])
	{
		zs++;
		sq[zs]=k;
	}
	printf("%lld\n",zs);
	for(i=zs;i;i--)
	{
		printf("%lld%c",sq[i]," \n"[i==1]);
	}
}