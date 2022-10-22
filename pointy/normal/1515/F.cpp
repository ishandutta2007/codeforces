// Author: Little09
// Problem: F. Phoenix and Earthquake
// Contest: Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/F
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll a[N],x;
int b[N],c[N],d[N],cnt;
int fa[N];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
set<int>s[N];
struct point
{
	ll x;
	int id;
	bool operator < (const point &o) const
	{
		return x<o.x;
	}
};
bool used[N];
priority_queue<point>q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> x;
	for (int i=1;i<=n;i++) cin >> a[i];
	ll sum=0;
	for (int i=1;i<=n;i++) sum+=a[i];
	if (sum<x*(n-1))
	{
		printNO;
		return 0;
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		int x1=find(x),y1=find(y);
		if (x1==y1) continue;
		fa[x1]=y1;
		b[++cnt]=x,c[cnt]=y,d[cnt]=i;
	}
	for (int i=1;i<=n;i++)
	{
		if (find(i)!=find(1))
		{
			printNO;
			return 0;
		}
	}
	printYES;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=cnt;i++)
	{
		s[b[i]].insert(i),s[c[i]].insert(i);
	}
	for (int i=1;i<=n;i++) q.push((point){a[i],i});
	int uuu=0;
	while (!q.empty())
	{
		point u=q.top();
		q.pop();
		if (u.x!=a[u.id]) continue;
		// cout << "id " << u.id << endl;
		// for (int i=1;i<=n;i++) cout << a[i] << " ";
		// cout << endl;
		// for (int j:s[u.id]) cout << j << " ";
		// cout << endl;
		if (used[u.id]) continue;
		int p;
		for (int j:s[u.id])
		{
			p=j;
			break;
		}
		cout << d[p] << endl;
		uuu++;
		if (uuu==n-1) return 0;
		int v=b[p];
		if (find(v)==find(u.id)) v=c[p];
		v=find(v);
		//cout << "v" << v << endl;
		if (s[u.id].size()>s[v].size())
		{
			for (int j:s[v]) s[u.id].insert(j);
			s[u.id].erase(p);
			used[v]=1,s[v].clear();
			a[u.id]+=a[v]-x,fa[v]=u.id,a[v]=0;
			assert(a[u.id]>=0);
			q.push((point){a[u.id],u.id});
		}
		else
		{
			for (int j:s[u.id]) s[v].insert(j);
			s[v].erase(p);
			used[u.id]=1,s[u.id].clear();
			a[v]+=a[u.id]-x,fa[u.id]=v,a[u.id]=0;
			assert(a[v]>=0);
			q.push((point){a[v],v});
		}
	}
	return 0;
}