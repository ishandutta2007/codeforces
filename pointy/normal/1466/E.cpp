// Author: Little09
// Problem: E. Apollo versus Pan
// Contest: Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/E
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
const ll mod=1000000007;

const int N=500005;
ll n,m; 
ll a[N],b[N],ans[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) b[i]=0,ans[i]=0;
	for (int i=0;i<=60;i++)
	{
		ll x=0,y=0;
		for (int j=1;j<=n;j++)
		{
			if (a[j]&(1ll<<i)) x++;
			else y++;
		}
		ll tmp=(1ll<<i)%mod;
		for (int j=1;j<=n;j++)
		{
			if (a[j]&(1ll<<i)) b[j]=(b[j]+tmp*n%mod)%mod;
			else b[j]=(b[j]+tmp*x)%mod;
		}
	}
	// for (int i=1;i<=n;i++) cout << b[i] << " ";
	// cout << endl;
	for (int i=0;i<=60;i++)
	{
		ll x=0,y=0;
		for (int j=1;j<=n;j++)
		{
			if (a[j]&(1ll<<i)) x++;
			else y++;
		}
		ll tmp=(1ll<<i)%mod;
		for (int j=1;j<=n;j++)
		{
			if (a[j]&(1ll<<i)) ans[j]=(ans[j]+b[j]*x%mod*tmp%mod)%mod;
		}
	}
	ll res=0;
	for (int i=1;i<=n;i++) res=(res+ans[i])%mod;
	cout << res << endl;
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