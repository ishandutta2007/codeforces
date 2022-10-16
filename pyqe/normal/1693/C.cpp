#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,dg[200069],nr[200069];
vector<long long> al[200069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,l,w,sz,ww;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[l].push_back(k);
		dg[k]++;
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=inf;
	}
	pq.push({0,n});
	nr[n]=0;
	for(;!pq.empty();)
	{
		w=-pq.top().fr;
		k=pq.top().sc;
		pq.pop();
		if(w>nr[k])
		{
			continue;
		}
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			dg[l]--;
			ww=w+1+dg[l];
			if(ww<nr[l])
			{
				pq.push({-ww,l});
				nr[l]=ww;
			}
		}
	}
	printf("%lld\n",nr[1]);
}