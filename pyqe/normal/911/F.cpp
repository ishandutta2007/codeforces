#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dg[200069],nr[2][200069],zs=0,inf=1e18;
vector<long long> al[200069];
bitset<200069> vtd,spc;
pair<long long,long long> dp[200069],sq[200069];
queue<long long> q;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x]={0,0};
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			dp[x]=max(dp[x],{dp[l].fr+1,l});
		}
	}
}

void trv(long long xx,long long x)
{
	long long i,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(nr[xx][x]+1<nr[xx][l])
		{
			nr[xx][l]=nr[xx][x]+1;
			trv(xx,l);
		}
	}
}

int main()
{
	long long i,ii,k,l,sz,p[2],e,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			al[k].push_back(l);
			dg[k]++;
			swap(k,l);
		}
	}
	dfs(1);
	for(p[0]=1;dp[p[0]].sc;p[0]=dp[p[0]].sc);
	vtd.reset();
	dfs(p[0]);
	for(p[1]=p[0];1;p[1]=dp[p[1]].sc)
	{
		spc[p[1]]=1;
		if(!dp[p[1]].sc)
		{
			break;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			nr[ii][i]=inf;
		}
		nr[ii][p[ii]]=0;
		trv(ii,p[ii]);
	}
	for(i=1;i<=n;i++)
	{
		if(!spc[i]&&dg[i]==1)
		{
			q.push(i);
		}
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		e=nr[1][k]>nr[0][k];
		z+=nr[e][k];
		zs++;
		sq[zs]={k,p[e]};
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			dg[l]--;
			if(!spc[l]&&dg[l]==1)
			{
				q.push(l);
			}
		}
	}
	for(k=p[0];k!=p[1];k=dp[k].sc)
	{
		z+=nr[1][k];
		zs++;
		sq[zs]={k,p[1]};
	}
	printf("%lld\n",z);
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld %lld\n",k,l,k);
	}
}