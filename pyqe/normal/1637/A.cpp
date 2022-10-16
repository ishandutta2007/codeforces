#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				break;
			}
		}
		if(i<n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}