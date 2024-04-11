#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> vtd;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=2;i<=n+1;i++)
	{
		if(!vtd[i])
		{
			for(j=i*i;j<=n+1;j+=i)
			{
				vtd[j]=1;
			}
		}
	}
	printf("%lld\n",1ll+(n+1>=4));
	for(i=2;i<=n+1;i++)
	{
		printf("%lld%c",1ll+vtd[i]," \n"[i==n+1]);
	}
}