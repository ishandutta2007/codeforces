// Author: Little09
// Problem: C. Corners
// Contest: Codeforces Round #815 (Div. 2)
// URL: https://codeforces.com/contest/1720/problem/C
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
char a[N][N];


void work()
{
	cin >> n >> m;
	int ans=0;
	for (int i=1;i<=n;i++) 
	{
		for (int j=1;j<=m;j++)
		{
			cin >> a[i][j];
			ans=(ans+a[i][j]-'0');
		}
	}
	if (ans==0)
	{
		cout << ans << endl;
		return;
	}
	int res=3;
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<m;j++)
		{
			int u=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]-'0'*4;
			if (u==4) continue;
			if (u==3) res=min(res,2);
			if (u==2||u==1) res=min(res,1);
		}
	}
	cout << ans-res+1 << endl;
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