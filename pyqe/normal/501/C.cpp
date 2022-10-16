#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dg[100069],xr[100069],zs=0;
pair<long long,long long> sq[100069];
queue<long long> q;

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",dg+i,xr+i);
		if(dg[i]==1)
		{
			q.push(i);
		}
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		if(!dg[k])
		{
			continue;
		}
		l=xr[k];
		zs++;
		sq[zs]={k,l};
		dg[k]=0;
		xr[k]=0;
		dg[l]--;
		xr[l]^=k;
		if(dg[l]==1)
		{
			q.push(l);
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}