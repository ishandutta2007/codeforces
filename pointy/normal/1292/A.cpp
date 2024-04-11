// Author: Little09
// Problem: C. NEKO's Maze Game
// Contest: Codeforces Round #614 (Div. 2)
// URL: https://codeforces.com/contest/1293/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
int a[3][N];
ll dp[3][N];
ll ans;
int ask(int x,int y)
{
	int l=max(y-1,1),r=min(y+1,n);
	if (a[x][y]==0) return 0;
	int res=0;
		for (int j=l;j<=r;j++)
		{
			res+=a[3-x][j];
		}
	return res;
}
void update(int x,int y)
{
	int l=max(y-3,1),r=min(y+3,n);
	for (int i=1;i<=2;i++)
	{
		for (int j=l;j<=r;j++)
		{
			ans-=dp[i][j];
		}
	}
	a[x][y]^=1;
	for (int i=1;i<=2;i++)
	{
		for (int j=l;j<=r;j++)
		{
			dp[i][j]=ask(i,j);
			ans+=dp[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin >> x >> y;
		update(x,y);
		if (ans==0) printYes;
		else printNo;
	}
	return 0;
}