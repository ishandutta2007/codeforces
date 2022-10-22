// Author: Little09
// Problem: E. Long Way Home
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define lowbit(x) (x&(-x))
 
const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;
 
const int N=500005;
int n,m,k; 
int a[N],b[N],c[N];
 
ll dis[N],dp[N][2];
bool vis[N];
struct point
{
	ll t,v;
	bool operator < (const point & o) const
	{
		return v>o.v;
	}
};
vector<point>t[N];
priority_queue<point>q;
inline void add(int x,int y,ll z)
{
	t[x].push_back((point){y,z});
}
void dij(int s)
{
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=2;i<=n;i++) add(s,i,dis[i]);
	for (int i=1;i<=m;i++) add(a[i],b[i],c[i]);
	for (int i=1;i<=m;i++) add(b[i],a[i],c[i]);
	for (int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	dis[s]=0;
	point u;
	u.t=s,u.v=0;
	q.push(u);
	while (!q.empty())
	{
		point v=q.top();
		q.pop();
		if (vis[v.t]==1) continue;
		vis[v.t]=1;
		for (int i=0;i<t[v.t].size();i++) 
		{
			point to=t[v.t][i];
			if (dis[to.t]>dis[v.t]+to.v) 
			{
				dis[to.t]=dis[v.t]+to.v;
				point nxt={to.t,dis[to.t]};
				q.push(nxt);
			}
		}
	}
}
 
void solve(int l,int r,int L,int R,int tp)
{
	if (l>r) return;
	int mid=(l+r)>>1;
	int u=L,v=R;
	if (tp==0) v=min(v,mid);
	else u=max(u,mid);
	int pos=-1;
	for (int i=u;i<=v;i++)
	{
		ll p=dis[i]+1ll*(i-mid)*(i-mid);
		if (p<=dp[mid][tp]) dp[mid][tp]=p,pos=i;
	}
	solve(l,mid-1,L,pos,tp);
	solve(mid+1,r,pos,R,tp);
}
 
void work()
{
	for (int i=1;i<=n;i++) dp[i][0]=inf,dp[i][1]=inf;
	solve(1,n,1,n,0),solve(1,n,1,n,1);
	for (int i=1;i<=n;i++) dis[i]=min(dis[i],min(dp[i][0],dp[i][1]));
	dij(1);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++) dis[i]=inf;
	for (int i=1;i<=m;i++) cin >> a[i] >> b[i] >> c[i];
	dij(1);
	for (int i=1;i<=k;i++) work();
	for (int i=1;i<=n;i++) cout << dis[i] << " ";
	return 0;
}