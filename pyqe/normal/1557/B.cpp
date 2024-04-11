#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],as[100069];

int main()
{
	long long t,rr,i,c;
	
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
		c=0;
		for(i=1;i<=n;i++)
		{
			a[i]=lower_bound(as+1,as+n+1,a[i])-as;
			c+=i==1||a[i]!=a[i-1]+1;
		}
		if(c<=d)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}