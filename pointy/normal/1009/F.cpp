// Author: Little09
// Problem: CF1009F Dominant Indices
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1009F
// Memory Limit: 500 MB
// Time Limit: 4500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
vector<int>t[N];
int len[N],fa[N],son[N],ans[N];
vector<int>dp[N];
void dfs1(int x,int f)
{
	fa[x]=f,son[x]=0,len[x]=0;
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs1(i,x);
		if (len[i]>=len[son[x]]) son[x]=i,len[x]=len[i]+1;
	}
}
void dfs2(int x)
{
	if (son[x])
	{
		dfs2(son[x]);
		swap(dp[x],dp[son[x]]);
		dp[x].push_back(1);
		ans[x]=ans[son[x]];
		if (dp[x][ans[x]]==1) ans[x]=len[x];
		for (int i:t[x])
		{
			if (i==fa[x]||i==son[x]) continue;
			dfs2(i);
			for (int j=0;j<=len[i];j++)
			{
				int tmp=len[x]-(len[i]-j+1);
				dp[x][tmp]+=dp[i][j];
				if (dp[x][tmp]>dp[x][ans[x]]||(dp[x][tmp]==dp[x][ans[x]]&&tmp>ans[x])) ans[x]=tmp;
			}
		}
	}
	else
	{
		dp[x].push_back(1);
		ans[x]=len[x];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		t[x].push_back(y),t[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1);
	for (int i=1;i<=n;i++) cout << len[i]-ans[i] << endl;
	return 0;
}