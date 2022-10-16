#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nr[200069],zs=0,inf=1e18;
vector<pair<long long,long long>> al[200069];
queue<long long> q;
vector<long long> cd[200069];
bitset<200069> spc;
bitset<1000069> sq;

void rk(long long x)
{
	if(x<=n)
	{
		long long i,sz=cd[x].size(),p;
		
		for(i=0;i<sz;i++)
		{
			p=cd[x][i];
			spc[p]=1;
			rk(x+1);
			spc[p]=0;
			if(zs==d)
			{
				return;
			}
		}
	}
	else
	{
		long long i;
		
		zs++;
		for(i=1;i<=m;i++)
		{
			sq[m*(zs-1)+i]=spc[i];
		}
	}
}

int main()
{
	long long i,k,l,sz,p;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=inf;
	}
	q.push(1);
	nr[1]=0;
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			p=al[k][i].sc;
			if(nr[k]+1<nr[l])
			{
				q.push(l);
				nr[l]=nr[k]+1;
			}
			if(nr[k]+1==nr[l])
			{
				cd[l].push_back(p);
			}
		}
	}
	rk(2);
	printf("%lld\n",zs);
	for(i=1;i<=zs*m;i++)
	{
		printf("%lld",(long long)sq[i]);
		if(i%m==0)
		{
			printf("\n");
		}
	}
}