// Author: Little09
// Problem: E. Cactus Wall
// Contest: Educational Codeforces Round 138 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1749/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
vector<char>a[N];
vector<int>dis[N];
vector<pii>tr[N];
vector<bool>vis[N],used[N];
const int det[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
const int deT[4][2]={{1,1},{-1,-1},{1,-1},{-1,1}};
priority_queue<pair<int,pii>>q;

void print(int x,int y)
{
	//cout << x << " " << y << endl;
	a[x][y]='#';
	if (y==0) return;
	print(tr[x][y].fi,tr[x][y].se);
}

void work()
{
	cin >> n >> m;
	for (int i=0;i<n;i++) a[i].clear(),dis[i].clear(),vis[i].clear(),used[i].clear(),tr[i].clear();
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			char x;
			cin >> x;
			a[i].pb(x);
			dis[i].pb(N),vis[i].pb(0),used[i].pb(0),tr[i].pb(mp(0,0));
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (a[i][j]=='#')
			{
				for (int k=0;k<4;k++)
				{
					int x=i+det[k][0],y=j+det[k][1];
					if (x<0||y<0||x>=n||y>=m) continue;
					used[x][y]=1;
				}
			}
		}
	}
	// for (int i=0;i<n;i++)
	// {
		// for (int j=0;j<m;j++)
		// {
			// cout << used[i][j] << " ";
		// }
		// cout << endl;
	// }
	while (!q.empty()) q.pop();
	for (int i=0;i<n;i++) if (used[i][0]==0) dis[i][0]=(a[i][0]=='.');
	for (int i=0;i<n;i++) if (used[i][0]==0) q.push(mp(-dis[i][0],mp(i,0)));
	while (!q.empty())
	{
		pair<int,pii> u=q.top();
		q.pop();
		if (vis[u.se.fi][u.se.se]) continue;
		if (used[u.se.fi][u.se.se]) continue;
		vis[u.se.fi][u.se.se]=1;
		int i=u.se.fi,j=u.se.se;
		for (int k=0;k<4;k++)
		{
			int x=i+deT[k][0],y=j+deT[k][1];
			if (x<0||y<0||x>=n||y>=m) continue;
			if (used[x][y]) continue;
			if (dis[x][y]>dis[i][j]+(a[x][y]=='.'))
			{
				dis[x][y]=dis[i][j]+(a[x][y]=='.');
				tr[x][y]=mp(i,j);
				q.push(mp(-dis[x][y],mp(x,y)));
			}
		}
	}
	int ans=N,ansx=-1;
	for (int i=0;i<n;i++) if (dis[i][m-1]<ans) ans=dis[i][m-1],ansx=i;
	if (ansx==-1) printNO;
	else 
	{
		printYES;
		print(ansx,m-1);
		for (int i=0;i<n;i++)
		{
			for (char j:a[i]) cout << j;
			cout << endl;
		}
	}
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