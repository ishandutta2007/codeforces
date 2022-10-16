#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,dg[200069],dgg[200069],sq[200069];
pair<long long,long long> ed[200069];
vector<long long> al[200069];
queue<long long> q;
bitset<200069> vtd;

void ers(long long x)
{
	dgg[x]--;
	if(dgg[x]==d-1)
	{
		q.push(x);
	}
}

int main()
{
	long long i,j,k,l,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		al[k].push_back(l);
		al[l].push_back(k);
		dg[k]++;
		dg[l]++;
	}
	for(i=1;i<=n;i++)
	{
		dgg[i]=dg[i];
		if(dg[i]<d)
		{
			q.push(i);
		}
	}
	z=n;
	for(i=m;i;i--)
	{
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			vtd[k]=1;
			z--;
			for(j=0;j<dg[k];j++)
			{
				l=al[k][j];
				if(!vtd[l])
				{
					ers(l);
				}
			}
		}
		sq[i]=z;
		k=ed[i].fr;
		l=ed[i].sc;
		dg[k]--;
		dg[l]--;
		if(!vtd[k]&&!vtd[l])
		{
			ers(k);
			ers(l);
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%lld\n",sq[i]);
	}
}