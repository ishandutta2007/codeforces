#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pr[100069][17],bl[100069],dh[100069],cdh=0,sbt[100069];
vector<long long> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	vtd[x]=1;
	dh[x]=cdh;
	sbt[x]=1;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l][0]=x;
			for(j=1;j-1<bl[pr[l][j-1]];j++)
			{
				pr[l][j]=pr[pr[l][j-1]][j-1];
			}
			bl[l]=j;
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
	cdh--;
}

int main()
{
	long long t,rr,i,ii,k,l,p[2],lca,ds,tg,z;
	pair<long long,long long> mxe;
	bool bad;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=n;
		if(k==l)
		{
			printf("%lld\n",z);
			continue;
		}
		p[0]=k;
		p[1]=l;
		for(ii=0;ii<2;ii++)
		{
			for(i=16;i>=0;i--)
			{
				if(i<bl[p[ii]]&&dh[pr[p[ii]][i]]>=dh[p[!ii]])
				{
					p[ii]=pr[p[ii]][i];
				}
			}
		}
		for(i=16;i>=0;i--)
		{
			if(i<bl[p[0]]&&pr[p[0]][i]!=pr[p[1]][i])
			{
				for(ii=0;ii<2;ii++)
				{
					p[ii]=pr[p[ii]][i];
				}
			}
		}
		if(p[0]!=p[1])
		{
			p[0]=pr[p[0]][0];
		}
		lca=p[0];
		ds=dh[k]-dh[lca]+dh[l]-dh[lca];
		if(ds%2)
		{
			printf("0\n");
			continue;
		}
		ds/=2;
		mxe=max(mp(dh[k],k),{dh[l],l});
		tg=mxe.sc;
		for(i=16;i>=0;i--)
		{
			if(ds&(1<<i))
			{
				tg=pr[tg][i];
			}
		}
		p[0]=k;
		p[1]=l;
		for(ii=0;ii<2;ii++)
		{
			bad=0;
			for(i=16;i>=0;i--)
			{
				if(ds-1&(1<<i))
				{
					if(i>=bl[p[ii]])
					{
						bad=1;
						break;
					}
					p[ii]=pr[p[ii]][i];
				}
			}
			if(dh[p[ii]]<=dh[tg])
			{
				bad=1;
			}
			if(!bad)
			{
				z-=sbt[p[ii]];
			}
			else
			{
				z-=n-sbt[tg];
			}
		}
		printf("%lld\n",z);
	}
}