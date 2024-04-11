#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nr[500069][2],inf=1e18;
vector<pair<long long,long long>> al[500069];
queue<long long> q;

int main()
{
	long long i,ii,k,l,w,sz,ww,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[l].push_back({k,w});
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			nr[i][ii]=inf;
		}
	}
	q.push(n);
	for(ii=0;ii<2;ii++)
	{
		nr[n][ii]=0;
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		w=max(nr[k][0],nr[k][1]);
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ww=al[k][i].sc;
			if(w+1<nr[l][ww])
			{
				nr[l][ww]=w+1;
				if(max(nr[l][0],nr[l][1])!=inf)
				{
					q.push(l);
				}
			}
		}
	}
	z=max(nr[1][0],nr[1][1]);
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		printf("%d",nr[i][1]>nr[i][0]);
	}
	printf("\n");
}