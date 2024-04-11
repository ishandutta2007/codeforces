#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn,dg[100069],ex[100069],sq[100069],zs;
vector<long long> al[100069];
priority_queue<pair<long long,long long>> pq;
bitset<100069> vtd;

int main()
{
	long long t,rr,i,j,ii,k,l,sz,p;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			dg[i]=0;
			vtd[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			for(ii=0;ii<2;ii++)
			{
				al[k].push_back(l);
				dg[k]++;
				swap(k,l);
			}
		}
		if(d*(d-1)/2>m)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			sort(al[i].begin(),al[i].end());
			pq.push({-dg[i],i});
		}
		bad=0;
		for(;!pq.empty();)
		{
			k=pq.top().sc;
			pq.pop();
			if(vtd[k])
			{
				continue;
			}
			if(dg[k]>=d)
			{
				zs=0;
				for(i=1;i<=n;i++)
				{
					if(!vtd[i])
					{
						zs++;
						sq[zs]=i;
					}
				}
				printf("1 %lld\n",zs);
				for(i=1;i<=zs;i++)
				{
					printf("%lld%c",sq[i]," \n"[i==zs]);
				}
				bad=1;
				break;
			}
			if(dg[k]==d-1)
			{
				nn=1;
				ex[1]=k;
				sz=al[k].size();
				for(i=0;i<sz;i++)
				{
					l=al[k][i];
					if(!vtd[l])
					{
						nn++;
						ex[nn]=l;
					}
				}
				for(i=1;i<=nn&&i;i++)
				{
					for(j=i+1;j<=nn;j++)
					{
						p=lower_bound(al[ex[i]].begin(),al[ex[i]].end(),ex[j])-al[ex[i]].begin();
						if(p>=(long long)al[ex[i]].size()||al[ex[i]][p]!=ex[j])
						{
							i=-1;
							break;
						}
					}
				}
				if(i)
				{
					printf("2\n");
					for(i=1;i<=nn;i++)
					{
						printf("%lld%c",ex[i]," \n"[i==nn]);
					}
					bad=1;
					break;
				}
			}
			vtd[k]=1;
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(!vtd[l])
				{
					dg[l]--;
					pq.push({-dg[l],l});
				}
			}
		}
		for(;!pq.empty();pq.pop());
		if(!bad)
		{
			printf("-1\n");
		}
	}
}