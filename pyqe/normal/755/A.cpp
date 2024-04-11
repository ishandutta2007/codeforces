#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	for(i=1;1;i++)
	{
		k=n*i+1;
		for(j=2;j*j<=k;j++)
		{
			if(k%j==0)
			{
				j=-1;
				break;
			}
		}
		if(j==-1)
		{
			printf("%lld\n",i);
			break;
		}
	}
}