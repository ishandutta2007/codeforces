// Author: Little09
// Problem: C. Solo mid Oracle
// Contest: Codeforces Round #679 (Div. 1, based on Technocup 2021 Elimination Round 1)
// URL: https://codeforces.com/contest/1434/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
ll calc(ll k)
{
	return k*a+a-(k+1)*k/2*d*b;
}

void work()
{
	cin >> a >> b >> c >> d;
	if (a>b*c)
	{
		cout << -1 << endl;
		return;
	}
	if (d>c)
	{
		cout << a << endl;
		return;
	}
	//k+1
	//k*d<=c
	ll ans=0;
	ll l=0,r=c/d;
	while (r-l+1>10)
	{
		ll mid=(l+r)/2,mid1=mid-1,mid2=mid+1;
		if (calc(mid1)<calc(mid2)) l=mid1;
		else r=mid2;
	}
	for (ll k=l;k<=r;k++) 
	{
		ans=max(ans,k*a+a-(k+1)*k/2*d*b);
	}
	cout << ans << endl; 
	//2*k*a+a>=(k+1)*k*d
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