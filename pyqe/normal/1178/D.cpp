#include <bits/stdc++.h>

using namespace std;

long long n,nn;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(nn=n;1;nn++)
	{
		for(j=2;j*j<=nn;j++)
		{
			if(nn%j==0)
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			break;
		}
	}
	printf("%lld\n",nn);
	for(i=1;i<=n;i++)
	{
		printf("%lld %lld\n",i,i%n+1);
	}
	for(i=1;i<=nn-n;i++)
	{
		printf("%lld %lld\n",i,i+n/2);
	}
}