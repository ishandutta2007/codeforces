// Author: Little09
// Problem: CF1485E Move and Swap
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1485E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int fa[N];
ll a[N];
int dis[N];
vector<int>d[N],t[N];
bool cmpA(int x,int y)
{
	return a[x]<a[y];
}
ll dp[N];
void dfs(int x)
{
	for (int i:t[x])
	{
		dis[i]=dis[x]+1;
		dfs(i);
	}
}

void work()
{
	cin >> n;
	for (int i=2;i<=n;i++) cin >> fa[i];
	for (int i=2;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) d[i].clear(),t[i].clear();
	for (int i=2;i<=n;i++) t[fa[i]].push_back(i);
	dis[1]=1;
	dfs(1);
	int mx=1;
	for (int i=2;i<=n;i++) mx=max(mx,dis[i]);
	for (int i=1;i<=n;i++) d[dis[i]].push_back(i);
	for (int i=1;i<=n;i++) dp[i]=0;
	for (int i=mx;i>=1;i--)
	{
		ll u=inf,v=0;
		for (int j:d[i]) u=min(u,a[j]),v=max(v,a[j]);
		for (int j:d[i]) dp[fa[j]]=max(dp[fa[j]],dp[j]+max(a[j]-u,v-a[j]));
		sort(d[i].begin(),d[i].end(),cmpA);
		ll res=-inf;
		for (int j:d[i])
		{
			res=max(res,dp[j]-a[j]);
			dp[fa[j]]=max(dp[fa[j]],res+a[j]);
		}
		reverse(d[i].begin(),d[i].end());
		res=-inf;
		for (int j:d[i])
		{
			res=max(res,dp[j]+a[j]);
			dp[fa[j]]=max(dp[fa[j]],res-a[j]);
		}
	}
	cout << dp[1] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}