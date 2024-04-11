#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,z[200069],ttl=0;
unsigned long long zz[2];
map<long long,long long> fq;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ttl+=k;
		fq[k]++;
		z[i]=k*i-(ttl+fq[k-1]-fq[k+1]);
	}
	for(i=1;i<=n;i++)
	{
		if(z[i]>=0)
		{
			zz[0]+=z[i];
		}
		else
		{
			zz[1]-=z[i];
		}
	}
	if(zz[1]>zz[0])
	{
		printf("-");
	}
	printf("%llu\n",max(zz[0],zz[1])-min(zz[0],zz[1]));
}