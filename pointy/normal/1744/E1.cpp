// Author: Little09
// Problem: E1. Divisible Numbers (easy version)
// Contest: Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/E1
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
ll a,b,c,d;


void work()
{
	cin >> a >> b >> c >> d;
	if (c>=a*2&&d>=b*2)
	{
		cout << a*2 << " " << b*2 << endl;
		return;
	}
	ll s=a*b;
		for (ll j=1;j<=sqrt(s);j++)
		{
			if (s%j!=0) continue;
			ll k=s/j;
			if (c/j!=(a)/j&&d/k!=(b)/k)
			{
				cout << c/j*j << " " << d/k*k << endl;
				return;
			}
			if (c/k!=(a)/k&&d/j!=b/j)
			{
				cout << c/k*k << " " << d/j*j << endl;
				return;
			}
		}
	cout << "-1 -1\n";
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