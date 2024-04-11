// Author: Little09
// Problem: A. Burenka Plays with Fractions
// Contest: Codeforces Round #815 (Div. 2)
// URL: https://codeforces.com/contest/1720/problem/A
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
int a[N];


void work()
{
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	a*=d,c*=b;
	if (a==c) cout << 0 << endl;
	else if (a==0||c==0) cout << 1 << endl;
	else if (a%c==0||c%a==0) cout << 1 << endl;
	else cout << 2 << endl;
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