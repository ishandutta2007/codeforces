// Author: Little09
// Problem: E. Rectangular Congruence
// Contest: Codeforces - Codeforces Round #822 (Div. 2)
// URL: https://codeforces.com/contest/1734/problem/E
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

const int N=505;
int n,m; 
int a[N],b[N][N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) b[i][i]=a[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++) b[i][j]=(b[i][j-1]+i)%n;
		if (i!=1) b[i][1]=(b[i][n]+i)%n;
		for (int j=2;j<i;j++) b[i][j]=(b[i][j-1]+i)%n;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
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
	int T=1;
	while (T--) work();
	return 0;
}