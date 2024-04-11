#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn=0,dd,pr[100069],nr[100069],ev[100069],lh[300069],rh[300069],sq[300069];
vector<pair<long long,long long>> al[100069];
priority_queue<pair<long long,long long>> pq;
pair<long long,pair<long long,long long>> ed[2000069],mst[100069];
pair<long long,long long> qq[300069];
pair<long long,long long> pb[300069];

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
	long long t,rr,i,ii,j,k,l,w,sz,ww,pz,md;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&t);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=1e18;
	}
	for(i=1;i<=d;i++)
	{
		pq.push({0,i});
		nr[i]=0;
		ev[i]=i;
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
		pr[i]=i;
	}
	dd=0;
	for(i=1;i<=nn;i++)
	{
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		if(fd(k)!=fd(l))
		{
			dd++;
			mst[dd]=ed[i];
			pr[fd(l)]=fd(k);
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&qq[rr].fr,&qq[rr].sc);
		lh[rr]=1;
		rh[rr]=d-1;
		pb[rr]={(lh[rr]+rh[rr])/2,rr};
	}
	for(dd=t;dd;)
	{
		for(i=1;i<=d;i++)
		{
			pr[i]=i;
		}
		sort(pb+1,pb+dd+1);
		for(j=1,i=1;i<=t;i++)
		{
			md=pb[i].fr;
			pz=pb[i].sc;
			if(pb[i].fr>d-1)
			{
				break;
			}
			for(;j<=md;j++)
			{
				k=mst[j].sc.fr;
				l=mst[j].sc.sc;
				pr[fd(l)]=fd(k);
			}
			k=qq[pz].fr;
			l=qq[pz].sc;
			if(fd(k)==fd(l))
			{
				sq[pz]=mst[md].fr;
				rh[pz]=md-1;
			}
			else
			{
				lh[pz]=md+1;
			}
			if(lh[pz]<=rh[pz])
			{
				pb[i].fr=(lh[pz]+rh[pz])/2;
			}
			else
			{
				pb[i].fr=1e18;
			}
		}
		dd=i-1;
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}