#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],as[100069];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			as[i]=a[i];
		}
		sort(as+1,as+n+1);
		for(i=1;i<=n;i++)
		{
			if(max(i-1,n-i)<d&&a[i]!=as[i])
			{
				break;
			}
		}
		if(i>n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}