// Author: Little09
// Problem: CF1039D You Are Given a Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1039D
// Memory Limit: 500 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,ans[N]; 
vector<int>t[N];
int a[N],cnt,dp[N],fa[N];
void dfs(int x,int f)
{
	a[++cnt]=x,fa[x]=f;
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs(i,x);
	}
}
int solve(int k)
{
	int res=0;
	for (int i=n;i>=1;i--) dp[i]=0;
	for (int i=n;i>=1;i--)
	{
		int mx=0,my=0;
		for (int j:t[a[i]])
		{
			if (j==fa[a[i]]) continue;
			if (dp[j]>mx) my=mx,mx=dp[j];
			else if (dp[j]>my) my=dp[j];
		}
		if (mx+my+1>=k) res++;
		else dp[a[i]]=mx+1;
	}
	return res;
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
		t[x].push_back(y);
		t[y].push_back(x);
	}
	dfs(1,0);
	int B=sqrt(n*log(n)/log(2));
	for (int i=1;i<=B;i++) ans[i]=solve(i);
	for (int i=B+1;i<=n;)
	{
		int l=i,r=n,u=solve(i);
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (solve(mid)==u) l=mid+1;
			else r=mid-1;
		}
		for (int j=i;j<=r;j++) ans[j]=u;
		i=r+1;
	}
	for (int i=1;i<=n;i++) cout << ans[i] << endl;
	return 0;
}