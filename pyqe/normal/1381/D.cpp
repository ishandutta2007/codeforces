#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,st,fn,nn,a[100069],dp[100069][2],inf=1e18;
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd,spc;
bool r0,bad;

void bd(long long x)
{
	long long i,j,r,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x][0]=0;
	dp[x][1]=-inf;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			bd(l);
			for(j=0;j<2;j++)
			{
				if(dp[l][0]+1>=dp[x][j])
				{
					for(r=1;r>j;r--)
					{
						dp[x][r]=dp[x][r-1];
					}
					dp[x][j]=dp[l][0]+1;
					break;
				}
			}
		}
	}
}

void bd2(long long x,long long w)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			al[x][i].sc=dp[l][0]+1;
			bd2(l,max(w+1,dp[x][dp[x][0]==dp[l][0]+1]));
		}
		else
		{
			al[x][i].sc=w+1;
		}
	}
}

void ffn(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(x==fn)
	{
		r0=1;
		nn++;
		a[nn]=x;
		spc[x]=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			ffn(l);
			if(r0)
			{
				nn++;
				a[nn]=x;
				spc[x]=1;
				return;
			}
		}
	}
}

long long val(long long x)
{
	long long i,sz=al[x].size(),l,w,mx=0;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		mx=max(mx,w*!spc[l]);
	}
	return mx;
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w,c=0;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l]&&!spc[l])
		{
			dfs(l);
		}
		c+=w>=nn-1;
	}
	bad&=c<3;
}

int main()
{
	long long t,rr,i,j,ii,u,k,l,p[2],mx[2];
	bool did;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&st,&fn);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
			spc[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back({l,0});
			al[l].push_back({k,0});
		}
		bd(1);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		bd2(1,-inf);
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		r0=0;
		nn=0;
		ffn(st);
		for(ii=0;ii<2;ii++)
		{
			p[ii]=1+(nn-1)*ii;
			mx[ii]=val(a[p[ii]]);
		}
		for(did=1;p[0]<p[1]&&did;)
		{
			did=0;
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				for(;p[ii]!=1+(nn-1)*ii+mx[!ii]*u&&p[0]<p[1];)
				{
					p[ii]+=u;
					mx[ii]=max(mx[ii],val(a[p[ii]])-abs(1+(nn-1)*ii-p[ii]));
					did=1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		bad=1;
		for(i=1;i<=nn;i++)
		{
			if(i<=p[0]||i>=p[1])
			{
				dfs(a[i]);
			}
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}