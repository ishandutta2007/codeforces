#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],fq[10000069];

int main()
{
	long long i,j,k,mn=1e18,c,e1,e2,z,p1,p2;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		fq[a[i]]++;
	}
	for(i=1;i<=10000000;i++)
	{
		c=0;
		for(j=i;j<=10000000;j+=i)
		{
			if(!c&&fq[j])
			{
				k=j;
				c++;
				if(fq[j]>1)
				{
					c++;
				}
			}
			else if(c&&fq[j])
			{
				c++;
			}
			if(c==2)
			{
				z=k/i*j;
				if(z<mn)
				{
					mn=z;
					e1=k;
					e2=j;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==e1)
		{
			p1=i;
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==e2&&i!=p1)
		{
			p2=i;
			break;
		}
	}
	if(p1>p2)
	{
		swap(p1,p2);
	}
	printf("%lld %lld\n",p1,p2);
}