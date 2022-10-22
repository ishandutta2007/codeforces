// Author: Little09
// Problem: B. Multiplication Table
// Contest: Codeforces Round #586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/B
// Memory Limit: 256 MB
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

const int N=3005;
int n,m; 
ll a[N][N],ans[N];


void work()
{
	//cin >> n;
	//for (int i=1;i<=n;i++) cin >> a[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	ans[1]=a[1][2]*a[1][3]/a[2][3];
	ans[1]=sqrt(ans[1]);
	for (int i=2;i<=n;i++) ans[i]=a[1][i]/ans[1];
	for (int i=1;i<=n;i++) cout << ans[i] << ' ';
	return 0;
}