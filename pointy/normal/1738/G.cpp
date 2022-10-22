// Author: Little09
// Problem: CF1738G Anti-Increasing Addicts
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1738G
// Memory Limit: 500 MB
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

const int N=1005;
int n,k; 
int a[N][N],f[N][N],mx[N][N],v[N][N];
bool ans[N][N];

void dfs(int x,int y,int id)
{
	ans[x][y]=1;
	if (x==1&&y==n+1-(k-id)) return;
	if (x==1) dfs(x,y+1,id);
	else if (ans[x-1][y]) dfs(x,y+1,id);
	else if (v[y+1][k-id]==x) dfs(x,y+1,id);
	else dfs(x-1,y,id);
}

void work()
{
	cin >> n >> k;
	for (int i=1;i<=n+1;i++)
	{
		for (int j=1;j<=n+1;j++)
		{
			a[i][j]=f[i][j]=mx[i][j]=v[i][j]=ans[i][j]=0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			char x;
			cin >> x;
			a[i][j]=x-'0';
		}
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=n;j>=1;j--)
		{
			if (a[i][j]==0) f[i][j]=mx[i+1][j+1]+1;
			mx[i][j]=max(f[i][j],max(mx[i+1][j],mx[i][j+1]));
			if (f[i][j]>=k)
			{
				printNO;
				return;
			}
			if (a[i][j]==0) v[j][f[i][j]]=max(v[j][f[i][j]],i);
		}
	}
	printYES;
	for (int i=1;i<=n;i++)
	{
		for (int j=n;j>=1;j--)
		{
			v[j][i]=max(v[j][i],v[j+1][i]);
		}
	}
	for (int i=1;i<k;i++) dfs(n,i,i);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
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