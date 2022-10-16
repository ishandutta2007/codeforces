#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,j,c=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;c<n*m&&i<=n;i++)
	{
		for(j=1;c<n*m&&j<=m;j++)
		{
			printf("%lld %lld\n",i,j);
			c++;
			if(c==n*m)
			{
				break;
			}
			printf("%lld %lld\n",n+1-i,m+1-j);
			c++;
		}
	}
}