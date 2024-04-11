// Author: Little09
// Problem: D. The Number of Imposters
// Contest: Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/D
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
int n,m; 
int a[N],b[N][3];
int fa[N];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
vector<int>t[N],w[N];
void add(int x,int y,int z)
{
	int x1=find(x),y1=find(y);
	if (x1==y1) return;
	fa[x1]=y1;
	t[x].push_back(y),w[x].push_back(z);
	t[y].push_back(x),w[y].push_back(z);
}
bool used[N];
int s,tt;
void dfs(int x,int y,int fa)
{
	s+=y,tt++;
	a[x]=y,used[x]=1;
	for (int i=0;i<t[x].size();i++)
	{
		if (t[x][i]==fa) continue;
		dfs(t[x][i],y^w[x][i],x);
	}
}
void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) fa[i]=i,t[i].clear(),w[i].clear(),used[i]=0;
	for (int i=1;i<=m;i++) 
	{
		int x,y;
		cin >> x >> y;
		string z;
		cin >> z;
		b[i][0]=x,b[i][1]=y;
		if (z=="imposter") b[i][2]=1;
		else b[i][2]=0;
		add(b[i][0],b[i][1],b[i][2]);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		s=0,tt=0;
		dfs(i,0,0);
		ans+=max(s,tt-s);
	}
	for (int i=1;i<=m;i++)
	{
		if ((a[b[i][0]]^a[b[i][1]])!=b[i][2])
		{
			cout << -1 << endl;
			return;
		}
	}
	cout << ans << endl;
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