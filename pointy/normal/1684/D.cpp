// Author: Little09
// Problem: D. Traps
// Contest: Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/D
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

const int N=500005;
ll n,m; 
ll a[N];


void work()
{
	cin >> n >> m;
	ll ans=0;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) ans+=a[i];
	for (int i=1;i<=n;i++) a[i]-=n-i;
	sort(a+1,a+n+1);
	for (int i=n;i>=n-m+1;i--)
	{
		ans-=a[i];
	}
	ans-=m*(m-1)/2;
	cout << ans << endl;
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