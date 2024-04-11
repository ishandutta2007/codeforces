// Author: Little09
// Problem: C2. Errich-Tac-Toe (Hard Version)
// Contest: Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/C2
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
			if (x=='X') a[i][j]=1;
			else if (x=='O') a[i][j]=2;
			else a[i][j]=0;
			dp[(i+j)%3]+=(a[i][j]>=1);
		}
	}
	int u=0;
	for (int i=0;i<=2;i++) if (dp[i]>dp[u]) u=i;
	int v=(u+1)%3,w=(u+2)%3;
	int resv=0,resw=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if ((i+j)%3==v) resv+=(a[i][j]==1),resw+=(a[i][j]==2);
			if ((i+j)%3==w) resw+=(a[i][j]==1),resv+=(a[i][j]==2);
		}
	}
	if (resv>resw) swap(v,w);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[i][j]==0) cout << '.';
			else if (a[i][j]==1) 
			{
				if ((i+j)%3==v) cout << 'O';
				else cout << 'X';
			}
			else
			{
				if ((i+j)%3==w) cout << 'X';
				else cout << 'O';
			}
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