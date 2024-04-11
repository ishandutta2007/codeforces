#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dsu[200069];
pair<long long,long long> ed[200069],as[200069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,k,l,w,p,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={k,l};
		as[i]={w,i};
	}
	sort(as+1,as+m+1);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(j=0,i=1;i<=m;i++)
	{
		w=as[i].fr;
		p=as[i].sc;
		k=ed[p].fr;
		l=ed[p].sc;
		z-=fd(k)==fd(l);
		if(i==m||w!=as[i+1].fr)
		{
			for(;j<i;)
			{
				j++;
				p=as[j].sc;
				k=ed[p].fr;
				l=ed[p].sc;
				z+=fd(k)==fd(l);
				dsu[fd(l)]=fd(k);
			}
		}
	}
	printf("%lld\n",z);
}