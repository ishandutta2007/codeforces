#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[100069];

int main()
{
	long long t,rr,i,k,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&m,&d,&n);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			mx=max(mx,a[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			d-=a[i]*((k-1)/m+1);
		}
		if(d+mx>0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}