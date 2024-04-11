#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];
map<long long,long long> ls;

int main()
{
	long long t,rr,i,sm,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=-n;i<=n;i++)
		{
			ls[i]=-1e18;
		}
		for(i=1;i<=n*2;i++)
		{
			scanf("%lld",a+i);
			a[i]=a[i]*2-3;
		}
		a[n*2+1]=0;
		sm=0;
		for(i=0;i<=n;i++)
		{
			sm+=a[i];
			ls[sm]=i;
		}
		mn=1e18;
		sm=0;
		for(i=n*2+1;i>n;i--)
		{
			sm+=a[i];
			mn=min(mn,i-ls[-sm]-1);
		}
		printf("%lld\n",mn);
	}
}