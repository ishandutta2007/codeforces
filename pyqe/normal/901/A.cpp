#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,a[200069];

int main()
{
	long long i,j,l,ls,c;
	
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i-1]>1&&a[i]>1)
		{
			i=-1;
			break;
		}
	}
	if(i!=-1)
	{
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");
	ls=0;
	c=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<a[i];j++)
		{
			c++;
			printf("%lld%c",ls," \n"[c==ttl]);
		}
		ls=c;
	}
	l=1;
	ls=0;
	c=0;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<a[i];j++)
		{
			c++;
			printf("%lld%c",ls-j%l," \n"[c==ttl]);
		}
		ls=c;
		l=a[i];
	}
}