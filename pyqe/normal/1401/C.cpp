#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],as[100069];

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
			as[i]=a[i];
		}
		sort(as+1,as+n+1);
		for(i=1;i<=n;i++)
		{
			if(a[i]!=as[i]&&a[i]%as[1])
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}