#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fq[2];
vector<pair<long long,bool>> al[200069];
bitset<200069> vtd,dh;
bool r0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	fq[dh[x]]++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			dh[l]=dh[x]^w;
			dfs(l);
		}
		else if(dh[l]!=(dh[x]^w))
		{
			r0=1;
		}
		if(r0)
		{
			return;
		}
	}
}

int main()
{
	long long t,rr,i,j,ii,k,l,e,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			for(j=0;j<8;j++)
			{
				scanf(" %c",&ch);
			}
			e=ch=='r';
			al[k].push_back({l,e});
			al[l].push_back({k,e});
		}
		r0=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				for(ii=0;ii<2;ii++)
				{
					fq[ii]=0;
				}
				dfs(i);
				if(r0)
				{
					break;
				}
				z+=max(fq[0],fq[1]);
			}
		}
		if(r0)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}