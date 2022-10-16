#include <bits/stdc++.h>

using namespace std;

long long n,nn=1e6,a[1000069];

int main()
{
	long long t,rr,i,j;
	
	for(i=1;i<=nn;i++)
	{
		a[i]=i*i*i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(j=nn,i=1;i<=nn;i++)
		{
			for(;j&&a[i]+a[j]>n;j--);
			if(!j)
			{
				break;
			}
			if(a[i]+a[j]==n)
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}