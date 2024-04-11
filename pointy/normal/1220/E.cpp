// Author: Little09
// Problem: E. Tourism
// Contest: Codeforces Round #586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/E
// Memory Limit: 256 MB
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
ll a[N];
vector<int>t[N];
bool vis[N],used[N];
int fa[N];
void dfs(int x,int f)
{
	used[x]=1,fa[x]=f;
	//cout << x << " " << f << endl;
	for (int i:t[x])
	{
		if (i==f) continue;
		if (used[i]) vis[x]=1;
		else dfs(i,x);
	}
}
void work(int x)
{
	if (fa[x]==0) return;
	if (vis[fa[x]]) return;
	vis[fa[x]]=1;
	work(fa[x]);
}
ll dis[N];
ll ask(int x)
{
	if (x==0||vis[x]) return 0;
	if (dis[x]>0) return dis[x];
	return dis[x]=a[x]+ask(fa[x]);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		t[x].push_back(y);
		t[y].push_back(x);
	}
	int s;
	cin >> s;
	dfs(s,0);
	for (int i=1;i<=n;i++) if (vis[i]) work(i);
	ll ans=0,res=0;
	for (int i=1;i<=n;i++) if (vis[i]) ans+=a[i];
	for (int i=1;i<=n;i++)
	{
		res=max(res,ask(i));
	}
	cout << ans+res;
	return 0;
}