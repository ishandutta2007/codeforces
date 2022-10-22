// Author: Little09
// Problem: CF1336A Linova and Kingdom
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1336A
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,k;
vector<int>t[N];
int fa[N],d[N],dis[N],siz[N];
void dfs(int x,int f)
{
	fa[x]=f,siz[x]=1;
	for (int i:t[x])
	{
		if (i==f) continue;
		d[x]++,dis[i]=dis[x]+1;
		dfs(i,x);
		siz[x]+=siz[i];
	}
}
struct point
{
	int id,x;
	bool operator < (const point &o) const
	{
		return x<o.x;
	}
};
priority_queue<point>q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		t[x].push_back(y),t[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) if (d[i]==0) q.push((point){i,dis[i]});
	ll ans=0;
	for (int i=1;i<=k;i++)
	{
		point u=q.top();
		q.pop();
		ans+=u.x;
		d[fa[u.id]]--;
		if (d[fa[u.id]]==0) q.push((point){fa[u.id],dis[fa[u.id]]-siz[fa[u.id]]+1});
	}
	cout << ans;
	return 0;
}