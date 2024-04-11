#include <bits/stdc++.h>

using namespace std;

long long n,a[200069][2],pr[200069];

int main()
{
	long long i,ii,iii,p,c;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
		}
		pr[i]=i%n+1;
	}
	if(n>3)
	{
		for(i=1;i<=n;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				for(iii=0;iii<2;iii++)
				{
					if(a[a[i][ii]][iii]==a[i][!ii])
					{
						pr[i]=a[i][ii];
						ii=2;
						break;
					}
				}
			}
		}
	}
	for(c=1,p=1;c<=n;p=pr[p],c++)
	{
		printf("%lld%c",p," \n"[c==n]);
	}
}