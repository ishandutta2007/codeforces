// Author: Little09
// Problem: D. Solve The Maze
// Contest: Codeforces Round #648 (Div. 2)
// URL: https://codeforces.com/contest/1365/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

const int N=55;
int n,m; 
char a[N][N];
const int det[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool ans;
void work(int x,int y)
{
	if (x<1||y<1||x>n||y>m) return;
	if (a[x][y]=='G') 
	{
		ans=0;
		return;
	}
	if (a[x][y]=='B') return;
	a[x][y]='#';
}
inline int num(int x,int y)
{
	return (x-1)*m+y;
}
int fa[N*N];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void add(int i,int j,int x,int y)
{
	if (x<1||y<1||x>n||y>m) return;
	if (a[i][j]=='#'||a[x][y]=='#') return;
	int u=find(num(i,j)),v=find(num(x,y));
	if (u!=v) fa[u]=v;
}

void work()
{
	cin >> n >> m;
	ans=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			fa[num(i,j)]=num(i,j);
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]=='B')
			{
				for (int k=0;k<4;k++) work(i+det[k][0],j+det[k][1]);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			for (int k=0;k<4;k++) add(i,j,i+det[k][0],j+det[k][1]);
		}
	}
 	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]=='G')
			{
				ans&=(find(num(i,j))==find(num(n,m)));
			}
		}
	}
	if (ans==1) printYes;
	else printNo;
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