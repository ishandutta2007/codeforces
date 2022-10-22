// Author: Little09
// Problem: B. Fibonacci Strings
// Contest: Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/B
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
ll a[N],s,fib[N],sb[N];
ll ans[N];
multiset<ll>q;

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	s=0;
	for (int i=1;i<=n;i++) s+=a[i];
	int u=-1;
	for (int i=55;i>=1;i--) 
	{
		if (s==sb[i])
		{
			u=i;
			break;
		}
	}
	if (u==-1)
	{
		printNO;
		return;
	}
	q.clear();
	for (int i=1;i<=n;i++) q.insert(-a[i]);
	ll las=0;
	for (int i=u;i>=1;i--)
	{
		if (q.empty())
		{
			printNO;
			return;
		}
		auto u=q.begin();
		ll v=-(*u);
		//cout << v << endl;
		q.erase(u);
		if (v<fib[i])
		{
			printNO;
			return;
		}
		v-=fib[i];
		if (las) q.insert(-las);
		las=v;
	}
	printYES;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	fib[1]=fib[2]=1;
	for (int i=3;i<=55;i++) fib[i]=fib[i-1]+fib[i-2];
	for (int i=1;i<=55;i++) sb[i]=sb[i-1]+fib[i];
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}