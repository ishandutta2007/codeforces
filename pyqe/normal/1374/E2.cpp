#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn=0,ttl=0,fq[4],sm=0,dd,sq[200069],zs=0,inf=1e18;
pair<long long,long long> a[4][200069];
multiset<pair<long long,long long>> ms[2];
multiset<pair<long long,long long>>::iterator it;

void blc()
{
	for(;nn<dd&&!ms[1].empty();nn++)
	{
		it=ms[1].begin();
		ms[0].insert(*it);
		sm+=(*it).fr;
		ms[1].erase(it);
	}
	for(;nn>dd&&!ms[0].empty();nn--)
	{
		it=ms[0].end();
		it--;
		ms[1].insert(*it);
		sm-=(*it).fr;
		ms[0].erase(it);
	}
}

void ins(pair<long long,long long> x)
{
	ms[0].insert(x);
	nn++;
	sm+=x.fr;
	blc();
}

void ers(pair<long long,long long> x)
{
	it=ms[0].find(x);
	if(it!=ms[0].end())
	{
		ms[0].erase(it);
		nn--;
		sm-=x.fr;
	}
	else
	{
		ms[1].erase(ms[1].find(x));
	}
	blc();
}

int main()
{
	long long i,j,ii,k,w,mk,mn,e;
	pair<long long,long long> z={inf,-1};
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&w,&k);
		mk=k*2;
		scanf("%lld",&k);
		mk|=k;
		fq[mk]++;
		a[mk][fq[mk]]={w,i};
	}
	mn=min(min(fq[1],fq[2]),d);
	if(fq[3]+mn<d)
	{
		printf("-1\n");
		return 0;
	}
	for(i=0;i<4;i++)
	{
		sort(a[i]+1,a[i]+fq[i]+1);
	}
	dd=m-d-mn;
	for(i=0;i<4;i++)
	{
		k=(i<3?mn:d-mn)*!!i;
		for(j=1;j<=fq[i];j++)
		{
			if(j<=k)
			{
				ttl+=a[i][j].fr;
			}
			else
			{
				ins(a[i][j]);
			}
		}
	}
	for(i=d-mn;i<=min(d,fq[3]);i++)
	{
		if(dd>=0)
		{
			z=min(z,{ttl+sm,i});
		}
		if(i<min(d,fq[3]))
		{
			dd++;
			blc();
			for(ii=1;ii<=2;ii++)
			{
				ttl-=a[ii][d-i].fr;
				ins(a[ii][d-i]);
			}
			ttl+=a[3][i+1].fr;
			ers(a[3][i+1]);
		}
	}
	if(z.fr==inf)
	{
		printf("-1\n");
		return 0;
	}
	e=z.sc;
	ttl=0;
	for(ii=0;ii<2;ii++)
	{
		ms[ii].clear();
	}
	nn=0;
	sm=0;
	dd=m-(d*2-e);
	for(i=0;i<4;i++)
	{
		k=(i<3?d-e:e)*!!i;
		for(j=1;j<=fq[i];j++)
		{
			if(j<=k)
			{
				zs++;
				sq[zs]=a[i][j].sc;
			}
			else
			{
				ins(a[i][j]);
			}
		}
	}
	for(;!ms[0].empty();ms[0].erase(it))
	{
		it=ms[0].begin();
		zs++;
		sq[zs]=(*it).sc;
	}
	printf("%lld\n",z.fr);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}