#include <bits/stdc++.h>

using namespace std;

long long n,m,zs,pst[200069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		zs=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k%2)
			{
				zs++;
				pst[zs]=i;
			}
		}
		if(zs<m||zs%2!=m%2)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=1;i<m;i++)
			{
				printf("%lld ",pst[i]);
			}
			printf("%lld\n",n);
		}
	}
}