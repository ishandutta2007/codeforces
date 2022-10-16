#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,ma=50,nr[100069][69],inf=1e18;
vector<pair<long long,long long>> al[100069];
priority_queue<pair<long long,pair<long long,long long>>> pq;

int main()
{
	long long i,j,k,kk,l,w,sz,ww,www,tg,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=ma;j++)
		{
			nr[i][j]=inf;
		}
	}
	pq.push({0,{1,0}});
	nr[1][0]=0;
	for(;!pq.empty();)
	{
		w=-pq.top().fr;
		k=pq.top().sc.fr;
		kk=pq.top().sc.sc;
		pq.pop();
		if(w>nr[k][kk])
		{
			continue;
		}
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ww=al[k][i].sc;
			if(!kk)
			{
				www=w+ww*ww;
				tg=ww;
			}
			else
			{
				www=w+ww*ww+kk*ww*2;
				tg=0;
			}
			if(www<nr[l][tg])
			{
				pq.push({-www,{l,tg}});
				nr[l][tg]=www;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		z=nr[i][0];
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld%c",z," \n"[i==n]);
	}
}