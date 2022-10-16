#include <bits/stdc++.h>

using namespace std;

const long long ma=100;
long long n,a[1069];
bitset<169> spc;

int main()
{
	long long t,rr,i,j;
	char ch;
	
	for(i=2;i<=ma;i++)
	{
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				break;
			}
		}
		spc[i]=j*j>i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
		}
		for(i=1;i<=n;i++)
		{
			if(!spc[a[i]])
			{
				break;
			}
		}
		if(i<=n)
		{
			printf("1\n%lld\n",a[i]);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(!spc[a[i]*10+a[j]])
				{
					break;
				}
			}
			if(j<=n)
			{
				break;
			}
		}
		printf("2\n%lld%lld\n",a[i],a[j]);
	}
}