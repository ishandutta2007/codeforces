#include <bits/stdc++.h>

using namespace std;

long long n,nn[2],ex[2][100069];
bitset<100069> sq;

int main()
{
	long long i,ii,k,e,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		e=k*k%3;
		nn[e]++;
		ex[e][nn[e]]=i;
	}
	e=nn[1]>nn[0];
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=nn[ii];i++)
		{
			c++;
			sq[ex[ii][i]]=c>n/2;
		}
	}
	printf("%lld\n",2ll*!e);
	for(i=1;i<=n;i++)
	{
		printf("%lld",(long long)sq[i]);
	}
	printf("\n");
}