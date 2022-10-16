#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n/2;j++)
		{
			printf("%lld %lld%c",(j-1)*n*2+i,(j-1)*n*2+n*2+1-i," \n"[j==n/2]);
		}
	}
}