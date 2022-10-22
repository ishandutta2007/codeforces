// Author: Little09
// Problem: F. Parametric MST
// Contest: CodeTON Round 1 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1656/problem/F
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
ll a[N],s,ans,sum[N];


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	s=sum[n];
	if (s+1ll*(n-2)*a[1]>0)
	{
		cout << "INF" << endl;
		return;
	}
	if (s+1ll*(n-2)*a[n]<0)
	{
		cout << "INF" << endl;
		return;
	}
	ans=-inf;
	for (int i=1;i<n;i++)
	{
		ll res=sum[i]*a[n]+(s-sum[i])*a[1]-a[1]*a[n];
		ll op=s+a[1]*(n-i-1)+a[n]*(i-1);
		//ans=min(ans,res+op*t);
		ll l=-a[i+1],r=-a[i];
		if (op<0) ans=max(ans,res+op*l);
		else ans=max(ans,res+op*r);
	}
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