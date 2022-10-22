// Author: Little09
// Problem: B. Beautiful Array
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/B
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
ll n,k,b,s; 
ll a[N];


void work()
{
	cin >> n >> k >> b >> s;
	if (s/k==b)
	{
		for (int i=1;i<n;i++) cout << "0 ";
		cout << s << endl;
		return;
	}
	for (int i=1;i<=n;i++) a[i]=0;
	for (int i=1;i<n;i++)
	{
		if (s>=k-1) a[i]=k-1,s-=k-1;
		else a[i]=s,s=0;
		if (s/k==b)
		{
			for (int j=1;j<n;j++) cout << a[j] << " ";
			cout << s << endl;
			return;
		}
	}
	cout << -1 << endl;
	return;
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