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
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			bad|=a[i]==1;
		}
		sort(a+1,a+n+1);
		for(i=1;i<n;i++)
		{
			if(a[i+1]==a[i]+1)
			{
				break;
			}
		}
		if(!bad||i>=n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}