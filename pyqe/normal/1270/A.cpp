#include <bits/stdc++.h>

using namespace std;

long long n,m[2],mx[2];

int main()
{
	long long t,rr,ii,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",m+ii);
		}
		for(ii=0;ii<2;ii++)
		{
			mx[ii]=0;
			for(i=0;i<m[ii];i++)
			{
				scanf("%lld",&k);
				mx[ii]=max(mx[ii],k);
			}
		}
		if(mx[0]>mx[1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}