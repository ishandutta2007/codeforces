#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int inf=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>e[N];
int a[N],ans=0,dp[N][2];
void dfs(int now,int father)
{
	int g[2]={};
	if (a[now]) dp[now][2-a[now]]=-1,g[2-a[now]]=inf;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now);
		for (int i=0;i<=1;i++)
		if (dp[now][i]>=0)
		{
			int mn=inf;
			for (int j=0;j<=1;j++) if (dp[to][j]>=0) mn=min(mn,dp[now][i]+dp[to][j]+(i!=j));
			g[i]=max(g[i],mn);
			mn=inf;
			for (int j=0;j<=1;j++) if (dp[to][j]>=0) mn=min(mn,dp[to][j]+(i!=j));
			dp[now][i]=max(dp[now][i],mn);
		}
	}
	ans=max(ans,min(g[0],g[1]));
}
void ACDC()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	print((ans+1)/2+1);
	ans=0;
	for (int i=1;i<=n;i++) memset(dp[i],0,sizeof(dp[i])),e[i].clear();
}

signed main()
{
	int T=read();
	/*
	if (T==36359)
	{
		for (int i=1;i<=3873;i++)
		{
			int n=read();
			for (int i=1;i<=n;i++) read();
			for (int i=1;i<n;i++) read(),read();
		}
		int n=read();
		print(n);
		for (int i=1;i<=n;i++) a[i]=read(),print(a[i]," \n"[i==n]);
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			print(u,' '),print(v);
		}
	}
	else
	*/
	while (T--) ACDC();
	
	return 0;
}