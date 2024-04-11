#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,j,c,sm=0,z=0;
	char ch;
	
	scanf("%lld%lld",&d,&n);
	for(i=1;i<=n;i++)
	{
		c=0;
		for(j=0;j<d;j++)
		{
			scanf(" %c",&ch);
			c+=ch-'0';
		}
		sm=(sm+1)*(c<d);
		z=max(z,sm);
	}
	printf("%lld\n",z);
}