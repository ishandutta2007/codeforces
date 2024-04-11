#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nr[200069];
vector<pair<long long,long long>> al[200069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,l,w,sz,ww;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w*2});
		al[l].push_back({k,w*2});
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",nr+i);
		pq.push({-nr[i],i});
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
				nr[l]=w+ww;
				pq.push({-nr[l],l});
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",nr[i]," \n"[i==n]);
	}
}