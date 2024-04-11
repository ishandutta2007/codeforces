#include <bits/stdc++.h>

using namespace std;

long long n,a[2][200069];

int main()
{
	long long t,rr,i,ii;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
		}
		bad=0;
		for(i=0;i<n;i++)
		{
			bad|=a[1][i]<a[0][i];
			bad|=a[1][i]>a[0][i]&&(a[1][i]-a[1][(i+1)%n]>1);
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}