#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

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
		}
		c=0;
		for(i=2;i<n;i++)
		{
			c+=a[i]>a[i-1]+a[i+1];
		}
		if(d==1)
		{
			printf("%lld\n",(n-1)/2);
		}
		else
		{
			printf("%lld\n",c);
		}
	}
}