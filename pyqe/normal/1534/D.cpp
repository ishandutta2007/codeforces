#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,zs=0;
bitset<100069> kd;
pair<long long,long long> sq[100069];

int main()
{
	long long i,j,k,l,c[2]={0,0},e;
	
	scanf("%lld",&n);
	printf("? 1\n");
	fflush(stdout);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(i-1)
		{
			if(k==1)
			{
				zs++;
				sq[zs]={1,i};
			}
			kd[i]=k%2;
			c[k%2]++;
		}
	}
	e=c[1]<c[0];
	for(i=2;i<=n;i++)
	{
		if(kd[i]==e)
		{
			printf("? %lld\n",i);
			fflush(stdout);
			for(j=1;j<=n;j++)
			{
				scanf("%lld",&k);
				if(j-1)
				{
					if(k==1)
					{
						zs++;
						sq[zs]={i,j};
					}
				}
			}
		}
	}
	printf("!\n");
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
	fflush(stdout);
}