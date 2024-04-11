#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,dg[401],dp[401][401][401],sq[401],zs=0;
pair<int,int> ed[401];
vector<int> al[401],cd[401];
bitset<401> vtd,spc;
pair<int,int> mne={1e9,-1};

void rtd(int x)
{
	int i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			cd[x].push_back(l);
			dg[x]++;
			rtd(l);
		}
	}
}

void dfs(int x)
{
	int i,j,r,l;
	
	for(i=2;i<=m;i++)
	{
		dp[x][0][i]=1e9;
	}
	dp[x][0][1]=0;
	for(i=0;i<dg[x];i++)
	{
		l=cd[x][i];
		dfs(l);
		for(j=1;j<=m;j++)
		{
			dp[x][i+1][j]=1e9;
			for(r=1;r<=j;r++)
			{
				dp[x][i+1][j]=min(dp[x][i+1][j],dp[x][i][r]+dp[l][dg[l]][j-r]);
			}
		}
	}
	dp[x][dg[x]][0]=1;
	mne=min(mne,{dp[x][dg[x]][m]+(x!=1),x});
}

void bt(int x,int w)
{
	int i,j,l;
	
	spc[x]=1;
	for(i=dg[x]-1;i+1;i--)
	{
		l=cd[x][i];
		for(j=1;j<=w;j++)
		{
			if(dp[x][i+1][w]==dp[x][i][j]+dp[l][dg[l]][w-j])
			{
				break;
			}
		}
		if(w-j)
		{
			bt(l,w-j);
		}
		w=j;
	}
}

int main()
{
	int i,k,l;
	
	scanf("%d%d",&n,&m);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&k,&l);
		ed[i]={k,l};
		al[k].push_back(l);
		al[l].push_back(k);
	}
	rtd(1);
	dfs(1);
	bt(mne.sc,m);
	for(i=1;i<=n-1;i++)
	{
		k=ed[i].fr;
		l=ed[i].sc;
		if(spc[k]^spc[l])
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%d\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%d%c",sq[i]," \n"[i==zs]);
	}
}