#include <bits/stdc++.h>

using namespace std;

long long n,a[2][50069];

int main()
{
	long long t,rr,i,ii,mx[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			mx[ii]=0;
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
				mx[ii]=max(mx[ii],a[ii][i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(max(a[0][i]-(mx[0]-mx[1]),0ll)!=a[1][i])
			{
				break;
			}
		}
		if(mx[0]<mx[1]||i<=n)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}