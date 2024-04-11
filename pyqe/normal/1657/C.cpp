#include <bits/stdc++.h>

using namespace std;

long long n,a[500069];

int main()
{
	long long t,rr,i,p,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch==')';
		}
		z=0;
		for(p=1;p<n;)
		{
			if(!a[p])
			{
				z++;
				p+=2;
			}
			else
			{
				for(i=p+1;i<=n;i++)
				{
					if(a[i])
					{
						break;
					}
				}
				if(i>n)
				{
					break;
				}
				z++;
				p=i+1;
			}
		}
		printf("%lld %lld\n",z,n+1-p);
	}
}