#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn,dsu[1569],cc[1569],ce[1569],pst[1569],dp[3069][1569],sbt[3069],tmp[1569],dv=998244353;
pair<long long,long long> ed[2000069];
vector<long long> al[3069];
bitset<3069> vtd;

long long tri(long long x)
{
	return x*(x-1)/2;
}

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(long long x)
{
	long long i,j,r,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x][0]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			for(j=0;j<=sbt[x];j++)
			{
				for(r=0;r<=sbt[l];r++)
				{
					tmp[j+r]=(tmp[j+r]+dp[x][j]*dp[l][r])%dv;
				}
			}
			sbt[x]+=sbt[l];
			for(j=0;j<=sbt[x];j++)
			{
				dp[x][j]=tmp[j];
				tmp[j]=0;
			}
		}
	}
	dp[x][1]=(dp[x][1]+1)%dv;
	dp[x][0]=0;
	sbt[x]+=x<=n;
}

int main()
{
	long long i,j,k,l;
	
	scanf("%lld",&n);
	m=tri(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&k);
			if(i<j)
			{
				ed[k]={i,j};
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cc[i]=1;
		pst[i]=i;
	}
	nn=n;
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(fd(k)!=fd(l))
		{
			cc[fd(k)]+=cc[fd(l)];
			ce[fd(k)]+=ce[fd(l)];
			dsu[fd(l)]=fd(k);
		}
		ce[fd(k)]++;
		if(ce[fd(k)]==tri(cc[fd(k)]))
		{
			nn++;
			for(j=1;j<=n;j++)
			{
				if(fd(j)==fd(k))
				{
					al[nn].push_back(pst[j]);
					pst[j]=nn;
				}
			}
		}
	}
	dfs(nn);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",dp[nn][i]," \n"[i==n]);
	}
}