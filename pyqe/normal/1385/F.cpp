#include <bits/stdc++.h>

using namespace std;

long long n,d,dg[200069],pd[200069];
vector<long long> al[200069];
queue<long long> q;
bitset<200069> vtd;

int main()
{
	long long t,rr,i,k,l,sz,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			dg[i]=0;
			pd[i]=0;
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
			dg[k]++;
			dg[l]++;
		}
		for(i=1;i<=n;i++)
		{
			if(dg[i]==1)
			{
				q.push(i);
			}
		}
		z=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			vtd[k]=1;
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(!vtd[l])
				{
					pd[l]++;
					if(pd[l]==d)
					{
						pd[l]=0;
						dg[l]-=d;
						z++;
						if(dg[l]==1)
						{
							q.push(l);
						}
					}
				}
			}
		}
		printf("%lld\n",z);
	}
}