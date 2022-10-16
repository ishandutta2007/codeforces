#include <bits/stdc++.h>

using namespace std;

long long n,m,dg[100069];

int main()
{
	long long i,k,l,c=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		dg[k]++;
		dg[l]++;
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]==n-1&&m==n-1)
		{
			printf("star topology\n");
			return 0;
		}
		if(dg[i]>2)
		{
			printf("unknown topology\n");
			return 0;
		}
		c+=dg[i]==1;
	}
	if(!c)
	{
		printf("ring topology\n");
	}
	else if(c==2)
	{
		printf("bus topology\n");
	}
	else
	{
		printf("unknown topology\n");
	}
}