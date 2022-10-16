#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,lb,rb;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(lb=1;lb<=n&&a[lb]==lb;lb++);
		for(rb=n;rb&&a[rb]==rb;rb--);
		for(i=lb;i<=rb;i++)
		{
			if(a[i]==i)
			{
				i=-1;
				break;
			}
		}
		printf("%lld\n",(long long)(lb<=rb)+(i==-1));
	}
}