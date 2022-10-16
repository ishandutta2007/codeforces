#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069];

int main()
{
	long long t,rr,i,ii,mx[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
			mx[ii]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(a[0][i]>a[1][i])
			{
				swap(a[0][i],a[1][i]);
			}
			for(ii=0;ii<2;ii++)
			{
				mx[ii]=max(mx[ii],a[ii][i]);
			}
		}
		printf("%lld\n",mx[0]*mx[1]);
	}
}