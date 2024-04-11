#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,wg[1069],nr[1069][1069],inf=1e18;
pair<long long,long long> ed[1069],qq[1069];
vector<pair<long long,long long>> al[1069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,j,k,l,w,sz,ww,kk,ll,sm,z=inf;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,wg+i);
		ed[i]={k,l};
		al[k].push_back({l,wg[i]});
		al[l].push_back({k,wg[i]});
	}
	for(i=1;i<=d;i++)
	{
		scanf("%lld%lld",&k,&l);
		qq[i]={k,l};
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			nr[i][j]=inf;
		}
		pq.push({0,i});
		nr[i][i]=0;
		for(;!pq.empty();)
		{
			w=-pq.top().fr;
			k=pq.top().sc;
			pq.pop();
			if(w>nr[i][k])
			{
				continue;
			}
			sz=al[k].size();
			for(j=0;j<sz;j++)
			{
				l=al[k][j].fr;
				ww=al[k][j].sc;
				if(w+ww<nr[i][l])
				{
					pq.push({-w-ww,l});
					nr[i][l]=w+ww;
				}
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		sm=0;
		for(j=1;j<=d;j++)
		{
			kk=qq[j].fr;
			ll=qq[j].sc;
			sm+=min(nr[kk][ll],min(nr[kk][k]+nr[l][ll],nr[kk][l]+nr[k][ll]));
		}
		z=min(z,sm);
	}
	printf("%lld\n",z);
}