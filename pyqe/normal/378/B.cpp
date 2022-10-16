#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[2][100069],p[2]={1,1},inf=1e18;
bitset<100069> sq[2];

int main()
{
	long long i,ii,e;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		a[ii][n+1]=inf;
	}
	for(i=0;i<n;i++)
	{
		e=a[1][p[1]]<a[0][p[0]];
		sq[e][p[e]]=1;
		p[e]++;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			sq[ii][i]=sq[ii][i]||i*2<=n;
			printf("%lld",(long long)sq[ii][i]);
		}
		printf("\n");
	}
}