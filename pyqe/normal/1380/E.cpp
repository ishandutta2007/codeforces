#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[200069],cc[200069],z=0;
multiset<long long> ms[200069];
multiset<long long>::iterator it;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void jo(long long x,long long y)
{
	long long k,u;
	
	x=fd(x);
	y=fd(y);
	if(cc[x]<cc[y])
	{
		swap(x,y);
	}
	for(it=ms[y].begin();it!=ms[y].end();it++)
	{
		k=*it;
		for(u=-1;u<=1;u+=2)
		{
			z-=ms[x].find(k+u)!=ms[x].end();
		}
	}
	for(it=ms[y].begin();it!=ms[y].end();it++)
	{
		k=*it;
		ms[x].insert(k);
	}
	cc[x]+=cc[y];
	dsu[y]=x;
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ms[k].insert(i);
		z+=i-1&&k!=l;
		l=k;
	}
	for(i=1;i<=m;i++)
	{
		dsu[i]=i;
		cc[i]=1;
	}
	printf("%lld\n",z);
	for(i=0;i<m-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		jo(k,l);
		printf("%lld\n",z);
	}
}