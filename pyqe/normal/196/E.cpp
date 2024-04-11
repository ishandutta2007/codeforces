#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn=0,a[100069],pr[100069],nr[100069],ev[100069];
vector<pair<long long,long long>> al[100069];
bitset<100069> spc;
priority_queue<pair<long long,long long>> pq;
pair<long long,pair<long long,long long>> ed[100069];

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

int main()
{
	long long i,j,k,l,w,sz,ww,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	scanf("%lld",&d);
	for(i=1;i<=d;i++)
	{
		scanf("%lld",a+i);
		spc[a[i]]=1;
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=1e18;
	}
	pq.push({0,1});
	nr[1]=0;
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		w=-pq.top().fr;
		pq.pop();
		if(spc[k])
		{
			z+=w;
			break;
		}
		if(w>nr[k])
		{
			continue;
		}
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ww=al[k][i].sc;
			if(w+ww<nr[l])
			{
				pq.push({-w-ww,l});
				nr[l]=w+ww;
			}
		}
	}
	for(;!pq.empty();pq.pop());
	for(i=1;i<=n;i++)
	{
		nr[i]=1e18;
	}
	for(i=1;i<=d;i++)
	{
		pq.push({0,a[i]});
		nr[a[i]]=0;
		ev[a[i]]=a[i];
	}
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		w=-pq.top().fr;
		pq.pop();
		if(w>nr[k])
		{
			continue;
		}
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ww=al[k][i].sc;
			if(w+ww<nr[l])
			{
				pq.push({-w-ww,l});
				nr[l]=w+ww;
				ev[l]=ev[k];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j].fr;
			ww=al[i][j].sc;
			if(l>i&&ev[i]!=ev[l])
			{
				nn++;
				ed[nn]={nr[i]+nr[l]+ww,{ev[i],ev[l]}};
			}
		}
	}
	sort(ed+1,ed+nn+1);
	for(i=1;i<=d;i++)
	{
		pr[a[i]]=a[i];
	}
	for(i=1;i<=nn;i++)
	{
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		w=ed[i].fr;
		if(fd(k)!=fd(l))
		{
			z+=w;
			pr[fd(l)]=fd(k);
		}
	}
	printf("%lld\n",z);
}