#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dh[200069],cdh=0,sbt[200069],bg[200069],pr[200069][18],bl[200069];
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l,e;
	pair<long long,long long> mxe={-1e18,-1};
	
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
			mxe=max(mxe,{sbt[l],l});
		}
	}
	cdh--;
	e=mxe.sc;
	if(e==-1)
	{
		bg[x]=x;
	}
	else
	{
		bg[x]=bg[e];
	}
}

int main()
{
	long long i,k,l,w,ds,p;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	printf("d 1\n");
	fflush(stdout);
	scanf("%lld",&ds);
	for(p=bg[1];1;p=bg[k])
	{
		printf("d %lld\n",p);
		fflush(stdout);
		scanf("%lld",&k);
		w=(ds+k+dh[p])/2-ds;
		for(i=17;i>=0;i--)
		{
			if(w>>i&1)
			{
				p=pr[p][i];
			}
		}
		if(dh[p]==ds)
		{
			printf("! %lld\n",p);
			fflush(stdout);
			break;
		}
		printf("s %lld\n",p);
		fflush(stdout);
		scanf("%lld",&k);
	}
}