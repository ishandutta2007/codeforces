#include <bits/stdc++.h>

using namespace std;

long long n,a[5];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<5;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<2;i++)
		{
			k=min(a[i],a[i+3]);
			a[i+3]-=k;
		}
		if(a[3]+a[4]<=a[2])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}