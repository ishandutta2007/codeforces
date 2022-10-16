#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,nr[2][100069];
vector<pair<long long,long long>> al[2][100069];
priority_queue<pair<long long,pair<bool,long long>>> pq;

int main()
{
	long long i,ii,k,l,w,e,sz,ww,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[0][k].push_back({l,w});
		al[1][l].push_back({k,w});
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			nr[ii][i]=inf;
		}
	}
	pq.push({0,{0,1}});
	nr[0][1]=0;
	for(;!pq.empty();)
	{
		w=-pq.top().fr;
		e=pq.top().sc.fr;
		k=pq.top().sc.sc;
		pq.pop();
		if(w>nr[e][k])
		{
			continue;
		}
		if(!e&&w<nr[1][k])
		{
			pq.push({-w,{1,k}});
			nr[1][k]=w;
		}
		sz=al[e][k].size();
		for(i=0;i<sz;i++)
		{
			l=al[e][k][i].fr;
			ww=al[e][k][i].sc;
			if(w+ww<nr[e][l])
			{
				pq.push({-w-ww,{e,l}});
				nr[e][l]=w+ww;
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		z=nr[1][i];
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld%c",z," \n"[i==n]);
	}
}