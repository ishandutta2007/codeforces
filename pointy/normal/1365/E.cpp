// Author: Little09
// Problem: E. Maximum Subsequence Value
// Contest: Codeforces Round #648 (Div. 2)
// URL: https://codeforces.com/contest/1365/problem/E
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

const int N=500005;
int n,m; 
ll a[N];


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
	for (int i=1;i<=n;i++) cin >> a[i];
	ll ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			ans=max(ans,a[i]|a[j]);
			for (int k=j+1;k<=n;k++)
			{
				ans=max(ans,a[i]|a[j]|a[k]);
			}
		}
	}
	cout << ans;
	return 0;
}