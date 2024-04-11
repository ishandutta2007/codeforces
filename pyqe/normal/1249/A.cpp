#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

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
		sort(a+1,a+n+1);
		bad=0;
		for(i=2;i<=n;i++)
		{
			if(a[i]==a[i-1]+1)
			{
				bad=1;
				break;
			}
		}
		printf("%lld\n",1+bad);
	}
}