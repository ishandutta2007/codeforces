#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			bad|=a[i]>d;
		}
		sort(a+1,a+n+1);
		if(!bad||a[1]+a[2]<=d)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}