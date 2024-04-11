#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069];

int main()
{
	long long t,rr,i,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
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
			sort(a[ii]+1,a[ii]+n+1);
		}
		printf("%lld\n",(a[0][n/2+1]-a[0][(n+1)/2]+1)*(a[1][n/2+1]-a[1][(n+1)/2]+1));
	}
}