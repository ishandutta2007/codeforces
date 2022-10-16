#include <bits/stdc++.h>

using namespace std;

long long n,a[50069][5];

int main()
{
	long long t,rr,i,j,p,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<5;j++)
			{
				scanf("%lld",&a[i][j]);
			}
			if(i==1)
			{
				p=i;
			}
			else
			{
				c=0;
				for(j=0;j<5;j++)
				{
					c+=a[i][j]<a[p][j];
				}
				if(c>=3)
				{
					p=i;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(i==p)
			{
				continue;
			}
			c=0;
			for(j=0;j<5;j++)
			{
				c+=a[p][j]<a[i][j];
			}
			if(c<3)
			{
				p=-1;
				break;
			}
		}
		printf("%lld\n",p);
	}
}