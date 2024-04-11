#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		bad=0;
		for(i=n-1;i;i--)
		{
			if(!bad)
			{
				bad|=a[i]<a[i+1];
			}
			else if(a[i]>a[i+1])
			{
				break;
			}
		}
		printf("%lld\n",i);
	}
}