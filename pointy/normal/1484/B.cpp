// Author: Little09
// Problem: B. Restore Modulo
// Contest: Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/B
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
int n,m; 
ll a[N],b[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	bool fl=1;
	for (int i=1;i<=n;i++) if (a[i]!=a[1]) fl=0;
	if (fl==1)
	{
		cout << 0 << endl;
		return;
	}
	ll ans=-1;
	for (int i=2;i<=n;i++)
	{
		if (a[i]>=a[i-1])
		{
			if (ans==-1) ans=a[i]-a[i-1];
			else if (ans!=a[i]-a[i-1])
			{
				cout << -1 << endl;
				return;
			}
		}
	}
	if (ans==-1)
	{
		for (int i=2;i<=n;i++)
		{
			if (ans==-1) ans=a[i-1]-a[i];
			else if (ans!=a[i-1]-a[i])
			{
				cout << -1 << endl;
				return;
			}
		}
		cout << 0 << endl;
		return;
	}
	ll p=-1;
	for (int i=2;i<=n;i++)
	{
		if (a[i]<a[i-1])
		{
			if (p==-1) p=a[i-1]+ans-a[i];
			else p=__gcd(p,a[i-1]+ans-a[i]);
		}
	}
	if (p==-1)
	{
		cout << 0 << endl;
		return;
	}
	b[1]=a[1]%p;
	for (int i=2;i<=n;i++) b[i]=(b[i-1]+ans)%p;
	for (int i=1;i<=n;i++)
	{
		if (a[i]!=b[i])
		{
			cout << -1 << endl;
			return;
		}
	}
	cout << p << " " << ans << endl;
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