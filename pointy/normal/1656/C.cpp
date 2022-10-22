// Author: Little09
// Problem: C. Make Equal With Mod
// Contest: CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/C
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	bool fl=0;
	for (int i=1;i<=n;i++) if (a[i]!=a[1]) fl=1;
	if (fl==0)
	{
		printYES;
		return;
	}
	fl=0;
	for (int i=1;i<=n;i++) if (a[i]==1) fl=1;
	if (fl==0)
	{
		printYES;
		return;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		if (a[i]==0||a[i]==2)
		{
			printNO;
			return;
		}
	}
	for (int i=1;i<n;i++)
	{
		if (a[i+1]-a[i]==1) 
		{
			printNO;
			return;
		}
	}
	printYES;
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