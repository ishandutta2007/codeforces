// Author: Little09
// Problem: A. Glory Addicts
// Contest: Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/A
// Memory Limit: 512 MB
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
ll a[N],b[N],cnta,cntb;
int c[N];
bool cmp(ll x,ll y)
{
	return x>y;
}
void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> c[i];
	cnta=0,cntb=0;
	ll sum=0;
	for (int i=1;i<=n;i++)
	{
		ll x;
		cin >> x;
		sum+=x;
		if (c[i]==0) a[++cnta]=x;
		else b[++cntb]=x;
	}
	int u=min(cnta,cntb);
	sort(a+1,a+cnta+1,cmp);
	sort(b+1,b+cntb+1,cmp);
	
	if (cnta!=cntb)
	{
		for (int i=1;i<=u;i++) sum+=a[i];
		for (int i=1;i<=u;i++) sum+=b[i];
		cout << sum << endl;
	}
	else
	{
		for (int i=1;i<=u;i++) sum+=a[i];
		for (int i=1;i<=u;i++) sum+=b[i];
		ll pp=min(a[u],b[u]);
		cout << sum-pp << endl;
	}
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