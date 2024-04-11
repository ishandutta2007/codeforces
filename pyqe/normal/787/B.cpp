#include <bits/stdc++.h>

using namespace std;

long long n,m,ls[2][10069];

int main()
{
	long long i,j,dd,u,k;
	bool bad;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&dd);
		bad=1;
		for(j=0;j<dd;j++)
		{
			scanf("%lld",&k);
			u=k<0;
			k=abs(k);
			bad&=ls[!u][k]<i;
			ls[u][k]=i;
		}
		if(bad)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}