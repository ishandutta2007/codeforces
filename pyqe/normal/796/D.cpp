#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,sr[300069],sq[300069],zs=0,inf=1e18;
pair<long long,long long> ed[300069];
vector<long long> al[300069];
queue<long long> q;
bitset<300069> vtd;

int main()
{
	long long i,k,l,sz;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		q.push(k);
		vtd[k]=1;
		sr[k]=k;
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(!vtd[l])
			{
				q.push(l);
				vtd[l]=1;
				sr[l]=sr[k];
			}
		}
	}
	for(i=1;i<=n-1;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(sr[k]!=sr[l])
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}