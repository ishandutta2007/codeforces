#include <bits/stdc++.h>

using namespace std;

long long n,pr[1069],ex[1069];
vector<long long> al[1069];
bitset<1069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	n++;
	ex[n]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			dfs(l);
		}
	}
}

long long qr(long long x)
{
	long long i,k;
	
	printf("? %lld",x);
	for(i=1;i<=x;i++)
	{
		printf(" %lld",ex[i]);
	}
	printf("\n");
	fflush(stdout);
	scanf("%lld",&k);
	return k;
}

int main()
{
	long long i,k,l,lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	n=0;
	dfs(1);
	k=qr(n);
	for(zz=n,lh=2,rh=n-1;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(qr(md)==k)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("! %lld %lld\n",pr[ex[zz]],ex[zz]);
}