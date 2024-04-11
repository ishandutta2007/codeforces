#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],fq[30];

int main()
{
	long long i,j,sm;
	pair<long long,long long> mxe={-1e18,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=0;j<30;j++)
		{
			fq[j]+=a[i]>>j&1;
		}
	}
	for(i=1;i<=n;i++)
	{
		sm=0;
		for(j=0;j<30;j++)
		{
			if((a[i]>>j&1)&&fq[j]==1)
			{
				sm+=1<<j;
			}
		}
		mxe=max(mxe,{sm,i});
	}
	swap(a[mxe.sc],a[1]);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",a[i]," \n"[i==n]);
	}
}