// Author: Little09
// Problem: C. Even Number Addicts
// Contest: Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/C
// Memory Limit: 512 MB
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

const int N=105;
int n,m; 
int X,Y;
int dp[N][N][2][2];

int dfs(int x,int y,int op,int tp)
{
	if (dp[x][y][op][tp]!=0) return dp[x][y][op][tp];
	if (x==0&&y==0)
	{
		if (op==0) return dp[x][y][op][tp]=1;
		else return dp[x][y][op][tp]=-1;
	}
	if (tp==0)
	{
		if (x>0&&dfs(x-1,y,op,tp^1)==1) return dp[x][y][op][tp]=1;
		if (y>0&&dfs(x,y-1,op^1,tp^1)==1) return dp[x][y][op][tp]=1;
		return dp[x][y][op][tp]=-1;
	}
	else
	{
		if (x>0&&dfs(x-1,y,op,tp^1)==-1) return dp[x][y][op][tp]=-1;
		if (y>0&&dfs(x,y-1,op,tp^1)==-1) return dp[x][y][op][tp]=-1;
		return dp[x][y][op][tp]=1;
	}
}

void work()
{
	cin >> n;
	X=0,Y=0;
	for (int i=1;i<=n;i++) 
	{
		int x;
		cin >> x;
		x=abs(x);
		if (x%2==0) X++;
		else Y++;
	}
	if (dfs(X,Y,0,0)==1) cout << "Alice" << endl;
	else cout << "Bob" << endl;
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