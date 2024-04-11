#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,cr,dg[100069],dsu[100069],cc[100069],ce[100069],lf[100069],nr[100069],fq[6],sq[100069],dp[100069],inf=1e18;
vector<long long> al[100069];
bitset<100069> vtd;

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
	long long i,sz=al[x].size(),l;
	
	if(nr[x]<6)
	{
		fq[nr[x]]++;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(nr[x]+1<nr[l])
		{
			nr[l]=nr[x]+1;
			dfs(l);
		}
	}
}

void fl(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			fl(l);
			dp[x]=dp[l];
		}
	}
	if(dg[x]==1)
	{
		dp[x]=cr/min(nr[x]+1,cr);
	}
	sq[x]=cr-min(nr[x],cr)*dp[x];
}

int main()
{
	long long t,rr,i,j,k,l;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			dg[i]=0;
			dsu[i]=i;
			cc[i]=1;
			ce[i]=0;
			lf[i]=0;
			nr[i]=inf;
			vtd[i]=0;
			sq[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
			dg[k]++;
			dg[l]++;
			if(fd(k)!=fd(l))
			{
				cc[fd(k)]+=cc[fd(l)];
				ce[fd(k)]+=ce[fd(l)];
				dsu[fd(l)]=fd(k);
			}
			ce[fd(k)]++;
		}
		for(i=1;i<=n;i++)
		{
			if(dg[i]<=1)
			{
				lf[fd(i)]++;
			}
		}
		bad=1;
		for(i=1;i<=n;i++)
		{
			if(ce[fd(i)]>=cc[fd(i)]||lf[fd(i)]>=4)
			{
				sq[i]=1+(dg[i]>1);
			}
			else if(lf[fd(i)]==3&&dg[i]==3)
			{
				for(j=0;j<6;j++)
				{
					fq[j]=0;
				}
				nr[i]=0;
				dfs(i);
				if(fq[2]==3)
				{
					cr=3;
					fl(i);
				}
				else if(fq[1]==3&&fq[3]==2)
				{
					cr=4;
					fl(i);
				}
				else if(fq[1]==3&&fq[2]==2&&fq[5]==1)
				{
					cr=6;
					fl(i);
				}
			}
			bad&=!sq[i];
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==n]);
			}
		}
	}
}