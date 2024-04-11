#include <bits/stdc++.h>

using namespace std;

long long ln,n,d,d2,a[200069];

int main()
{
	long long t,rr,i,j;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&ln,&n,&d,&d2);
		if(d>d2)
		{
			d=ln+1-d;
			d2=ln+1-d2;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1,greater<long long>());
		for(j=0,i=1;i<=d2-d-1;i++)
		{
			for(j++;j<=n&&a[j]+i>d2-1;j++);
			if(j>n)
			{
				break;
			}
		}
		printf("%lld\n",i-1);
	}
}