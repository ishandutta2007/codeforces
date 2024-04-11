#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[100069],sq[200069],zs=0;
vector<pair<long long,long long>> al[100069];
queue<long long> q;
bitset<100069> vtd;

int main()
{
	long long i,k,l,p,sz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",dg+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
		dg[k]--;
		dg[l]--;
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]>=0)
		{
			q.push(i);
		}
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		vtd[k]=1;
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			p=al[k][i].sc;
			if(!vtd[l])
			{
				zs++;
				sq[zs]=p;
				dg[l]++;
				if(!dg[l])
				{
					q.push(l);
				}
			}
		}
	}
	if(zs<m)
	{
		printf("DEAD\n");
	}
	else
	{
		printf("ALIVE\n");
		for(i=zs;i;i--)
		{
			printf("%lld%c",sq[i]," \n"[i==1]);
		}
	}
}