#include <bits/stdc++.h>

using namespace std;

long long n[2],d[2],a[2][100069];

int main()
{
	long long i,ii;
	
	scanf("%lld%lld%lld%lld",n,n+1,d,d+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			scanf("%lld",&a[ii][i]);
		}
		sort(a[ii]+1,a[ii]+n[ii]+1);
	}
	if(a[0][d[0]]<a[1][n[1]+1-d[1]])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}