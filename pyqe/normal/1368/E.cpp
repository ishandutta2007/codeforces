#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[200069],zs,inf=1e18;
vector<long long> al[200069],pr[200069];
bitset<200069> spc;

int main()
{
	long long t,rr,i,j,k,l,sz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			pr[i].clear();
			spc[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			pr[l].push_back(k);
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(!spc[i])
			{
				sz=pr[i].size();
				for(j=0;j<sz;j++)
				{
					l=pr[i][j];
					if(!spc[l])
					{
						j=-1;
						break;
					}
				}
				if(j==-1)
				{
					sz=al[i].size();
					for(j=0;j<sz;j++)
					{
						l=al[i][j];
						if(!spc[l])
						{
							zs++;
							sq[zs]=l;
							spc[l]=1;
						}
					}
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}