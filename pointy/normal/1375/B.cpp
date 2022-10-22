// Author: Little09
// Problem: B. Neighbor Grid
// Contest: Codeforces Global Round 9
// URL: https://codeforces.com/contest/1375/problem/B
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=505;
int n,m; 
int a[N][N],b[N][N];


void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			b[i][j]=4;
			if (i==1||i==n) b[i][j]--;
			if (j==1||j==m) b[i][j]--;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]>b[i][j])
			{
				printNO;
				return;
			}
		}
	}
	printYES;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cout << b[i][j] << " ";
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