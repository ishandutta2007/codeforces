#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,sm;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n*2;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n*2+1);
		bad=0;
		for(i=2;i<=n*2;i+=2)
		{
			if(a[i]!=a[i-1]||(i<n*2&&a[i]==a[i+1]))
			{
				bad=1;
				break;
			}
		}
		if(!bad)
		{
			sm=0;
			for(i=1;i<n;i++)
			{
				if((a[i*2+1]-a[i*2])%(i*2))
				{
					bad=1;
					break;
				}
				sm+=(a[i*2+1]-a[i*2])/i*(n-i);
			}
		}
		if(!bad)
		{
			bad|=a[1]<=sm||(a[1]-sm)%(n*2);
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}