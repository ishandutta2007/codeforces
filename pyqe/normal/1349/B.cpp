#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i,ii,u,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			a[i]=(a[i]>d)-(a[i]<d);
		}
		for(i=2;i<=n-1;i++)
		{
			if(a[i]==-1&&a[i-1]+1&&a[i+1]+1)
			{
				a[i]=1;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(i=3+(n-5)*ii;i>0&&i<=n;i+=u)
			{
				if(a[i]==-1&&a[i-u]+1&&a[i-u*2]+1)
				{
					a[i]=1;
				}
			}
		}
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(i=2+(n-3)*ii;i>0&&i<=n;i+=u)
			{
				if(a[i]==1&&!a[i-u])
				{
					a[i]=0;
				}
			}
		}
		c=0;
		for(i=1;i<=n;i++)
		{
			c+=!a[i];
		}
		if(c==n)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}