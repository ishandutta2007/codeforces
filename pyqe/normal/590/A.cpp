#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
bitset<500069> a;
pair<long long,long long> nr[500069];

int main()
{
	long long i,ii,u,k,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
		nr[i]={1e18,-1};
	}
	a[0]=a[1];
	a[n+1]=a[n];
	for(i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]||a[i]==a[i+1])
		{
			nr[i]={0,a[i]};
		}
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1+(n-1)*ii;i!=(n+1)*!ii;i+=u)
		{
			nr[i]=min(nr[i],{nr[i-u].fr+1,nr[i-u].sc});
		}
	}
	for(i=1;i<=n;i++)
	{
		mx=max(mx,nr[i].fr);
	}
	printf("%lld\n",mx);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",nr[i].sc," \n"[i==n]);
	}
}