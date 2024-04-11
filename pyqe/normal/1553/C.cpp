#include <bits/stdc++.h>

using namespace std;

const long long n=10;
long long a[n];

int main()
{
	long long t,rr,i,ii,u,k,c,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			a[i]=(ch=='1')-(ch=='?');
		}
		z=n;
		for(ii=0;ii<2;ii++)
		{
			c=0;
			for(i=0;i<n;i++)
			{
				k=a[i];
				if(k==-1)
				{
					k=i%2==ii;
				}
				u=!(i%2)*2-1;
				c+=k*u;
				if(c-(n-i)/2>0||c+(n-1-i)/2<0)
				{
					break;
				}
			}
			z=min(z,i+1);
		}
		printf("%lld\n",z);
	}
}