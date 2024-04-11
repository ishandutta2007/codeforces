#include <bits/stdc++.h>

using namespace std;

long long n,d,ttl,a[300069];

int main()
{
	long long t,rr,i,j,c;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld %c",&n,&ch);
		d=ch-'a';
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
			ttl+=a[i]==d;
		}
		if(ttl==n)
		{
			printf("0\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			c=0;
			for(j=i;j<=n;j+=i)
			{
				c+=a[j]==d;
			}
			if(c==n/i)
			{
				printf("1\n%lld\n",i);
				break;
			}
		}
		if(i>n)
		{
			printf("2\n%lld %lld\n",n-1,n);
		}
	}
}