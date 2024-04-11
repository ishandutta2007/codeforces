// Author: Little09
// Problem: C1. Errich-Tac-Toe (Easy Version)
// Contest: Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/C1
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

const int N=305;
int n,m; 
int a[N][N],dp[3];

void work()
{
	cin >> n;
	mem(dp);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			char x;
			cin >> x;
			a[i][j]=(x=='X');
			dp[(i+j)%3]+=a[i][j];
		}
	}
	int u=0;
	for (int i=0;i<=2;i++) if (dp[i]<dp[u]) u=i;
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[i][j]==0) cout << '.';
			else if ((i+j)%3==u) cout << 'O';
			else cout << 'X';
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