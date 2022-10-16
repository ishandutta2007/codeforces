#include <bits/stdc++.h>

using namespace std;

long long n[2],m,a[2][100069];

int main()
{
	long long i,ii;
	
	scanf("%lld%lld%lld",n,n+1,&m);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			scanf("%lld",&a[ii][i]);
		}
		sort(a[ii]+1,a[ii]+max(n[0],n[1])+1);
	}
	for(i=1;i<=max(n[0],n[1]);i++)
	{
		if(a[0][i]>a[1][i])
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}