#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,inf=1e18;
pair<long long,long long> a[200069];

int main()
{
	long long t,rr,i,k,c,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			a[i]={k,i};
		}
		sort(a+1,a+n+1);
		c=0;
		mx=-inf;
		for(i=1;i<=n;i++)
		{
			if(a[i].sc<a[i-1].sc)
			{
				c=0;
			}
			c++;
			mx=max(mx,c);
		}
		printf("%lld\n",n-mx);
	}
}