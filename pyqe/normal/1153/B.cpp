#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[2][1069];

int main()
{
	long long i,j,ii,k;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
		swap(n,m);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			printf("%lld%c",min(a[0][j],a[1][i])*k," \n"[j==m]);
		}
	}
}