#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[100069],cd[100069];
queue<long long> al[100069];

int main()
{
	long long t,rr,i,k,l,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		al[k].push(l);
		dg[k]++;
		dg[l]++;
		cd[l]++;
	}
	for(i=1;i<=n;i++)
	{
		z+=cd[i]*(dg[i]-cd[i]);
	}
	printf("%lld\n",z);
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&k);
		z-=cd[k]*(dg[k]-cd[k]);
		for(;!al[k].empty();)
		{
			l=al[k].front();
			al[k].pop();
			z-=dg[l]-cd[l];
			al[l].push(k);
			cd[l]--;
			z+=cd[l];
		}
		cd[k]=dg[k];
		printf("%lld\n",z);
	}
}