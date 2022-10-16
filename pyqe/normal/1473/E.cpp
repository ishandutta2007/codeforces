#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nr[4][200069],inf=1e18;
vector<pair<long long,long long>> al[200069];
priority_queue<pair<long long,pair<long long,long long>>> pq;

int main()
{
	long long i,k,l,w,sz,ww,mk,mkk,mkkk,www;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	for(mk=0;mk<4;mk++)
	{
		for(i=1;i<=n;i++)
		{
			nr[mk][i]=inf;
		}
	}
	pq.push({0,{0,1}});
	nr[0][1]=0;
	for(;!pq.empty();)
	{
		w=-pq.top().fr;
		mk=pq.top().sc.fr;
		k=pq.top().sc.sc;
		pq.pop();
		if(w>nr[mk][k])
		{
			continue;
		}
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ww=al[k][i].sc;
			for(mkk=0;mkk<4;mkk++)
			{
				if((mkk&mk)==mk)
				{
					mkkk=mkk^mk;
					www=ww*(1+(mkkk&1)-(mkkk>>1&1));
					if(w+www<nr[mkk][l])
					{
						pq.push({-w-www,{mkk,l}});
						nr[mkk][l]=w+www;
					}
				}
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		printf("%lld%c",nr[3][i]," \n"[i==n]);
	}
}