#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[200069],zs=0;
vector<long long> al[200069];
queue<long long> q;
bitset<200069> vtd;
pair<long long,long long> sq[200069];

int main()
{
	long long i,j,ii,k,l,sz,mx=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			al[k].push_back(l);
			dg[k]++;
			mx=max(mx,dg[k]);
			swap(k,l);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]==mx)
		{
			q.push(i);
			vtd[i]=1;
			for(;!q.empty();)
			{
				k=q.front();
				q.pop();
				sz=al[k].size();
				for(j=0;j<sz;j++)
				{
					l=al[k][j];
					if(!vtd[l])
					{
						zs++;
						sq[zs]={k,l};
						q.push(l);
						vtd[l]=1;
					}
				}
			}
			break;
		}
	}
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}