// Author: Little09
// Problem: F. Ideal Farm
// Contest: Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/F
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

ll s,n,k;
void work()
{
	cin >> s >> n >> k;
	if (k>s)
	{
		printNO;
		return;
	}
	if (k==s)
	{
		printYES;
		return;
	}
	ll t=(s+1)%k,a=(s+1)/k;
	ll ans=t*((a+2)/2)+(k-t)*((a+1)/2);
	if (n+1<=ans) printNO;
	else printYES;
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