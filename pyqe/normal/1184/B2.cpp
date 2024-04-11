#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,d2,h,h2,rn,dp[169][169],pst[1069],a[1069],fh[1069],wg[2000069],nr[2069],ca[1069],z=0,inf=1e18;
vector<pair<long long,long long>> al[2069],cd[2069];
queue<long long> q;
bitset<2069> vtd,spc;
bool r0;

void ae(long long x,long long y)
{
	al[x].push_back({y,m});
	al[y].push_back({x,m+1});
	wg[m]=1;
	m+=2;
}

void dfs(long long x)
{
	long long i,sz=cd[x].size(),l,p;
	
	vtd[x]=1;
	if(x<=d&&!spc[x])
	{
		z++;
		spc[x]=1;
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=cd[x][i].fr;
		p=cd[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
			if(r0)
			{
				spc[x]=1;
				wg[p]--;
				wg[p^1]++;
				return;
			}
		}
	}
}

int main()
{
	long long i,j,r,ii,k,l,sz,p,ub;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=inf*(i!=j);
		}
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			dp[k][l]=min(dp[k][l],1ll);
			swap(k,l);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(r=1;r<=n;r++)
			{
				dp[j][r]=min(dp[j][r],dp[j][i]+dp[i][r]);
			}
		}
	}
	scanf("%lld%lld%lld%lld",&d,&d2,&h,&h2);
	for(i=1;i<=d;i++)
	{
		scanf("%lld%lld%lld",pst+i,a+i,fh+i);
	}
	m=0;
	for(i=1;i<=d2;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(j=1;j<=d;j++)
		{
			if(a[j]>=l&&dp[pst[j]][k]<=fh[j])
			{
				ae(j,d+i);
			}
		}
	}
	for(rn=1;rn;)
	{
		for(i=1;i<=d+d2;i++)
		{
			nr[i]=inf;
			cd[i].clear();
			if(i<=d&&!spc[i])
			{
				q.push(i);
				nr[i]=0;
			}
		}
		vtd.reset();
		ub=inf;
		rn=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			if(nr[k]>=ub)
			{
				continue;
			}
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i].fr;
				p=al[k][i].sc;
				if(wg[p])
				{
					if(nr[k]+1<nr[l])
					{
						q.push(l);
						nr[l]=nr[k]+1;
					}
					if(nr[k]+1==nr[l])
					{
						cd[l].push_back({k,p});
						if(l>d&&!spc[l]&&!vtd[l])
						{
							rn++;
							ca[rn]=l;
							vtd[l]=1;
							ub=nr[l];
						}
					}
				}
			}
		}
		vtd.reset();
		for(i=1;i<=rn;i++)
		{
			r0=0;
			dfs(ca[i]);
		}
	}
	printf("%lld\n",min(z*h,d*h2));
}