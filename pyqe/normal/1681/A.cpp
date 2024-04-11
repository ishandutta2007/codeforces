#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][100069];

int main()
{
	long long t,rr,i,ii,mx[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",n+ii);
			mx[ii]=0;
			for(i=1;i<=n[ii];i++)
			{
				scanf("%lld",&a[ii][i]);
				mx[ii]=max(mx[ii],a[ii][i]);
			}
		}
		if(mx[0]>=mx[1])
		{
			printf("Alice\n");
		}
		else
		{
			printf("Bob\n");
		}
		if(mx[0]>mx[1])
		{
			printf("Alice\n");
		}
		else
		{
			printf("Bob\n");
		}
	}
}