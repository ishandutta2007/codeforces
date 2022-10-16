#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	printf("%lld\n",n*3+4);
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<3;j++)
		{
			if(!(!i&&!j)&&!(i==n+1&&j==2))
			{
				printf("%lld %lld\n",i,i+j);
			}
		}
	}
}