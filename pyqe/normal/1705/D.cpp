#include <bits/stdc++.h>

using namespace std;

long long n,nn[2],ex[2][200069];
bitset<200069> a[2];

int main()
{
	long long t,rr,i,ii,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
			for(i=1;i<=n;i++)
			{
				scanf(" %c",&ch);
				a[ii][i]=ch-'0';
				if(i>1&&a[ii][i]!=a[ii][i-1])
				{
					nn[ii]++;
					ex[ii][nn[ii]]=i;
				}
			}
		}
		if(nn[0]!=nn[1]||a[0][1]!=a[1][1]||a[0][n]!=a[1][n])
		{
			printf("-1\n");
			continue;
		}
		z=0;
		for(i=1;i<=nn[0];i++)
		{
			z+=abs(ex[0][i]-ex[1][i]);
		}
		printf("%lld\n",z);
	}
}