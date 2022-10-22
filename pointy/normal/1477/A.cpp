// Author: Little09
// Problem: A. Nezzar and Board
// Contest: Codeforces Round #698 (Div. 1)
// URL: https://codeforces.com/contest/1477/problem/A
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n;
ll k; 
ll a[N],b;


void work()
{
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	b=a[1];
	for (int i=1;i<n;i++) a[i]=a[i+1]-a[i];
	ll g=a[1];
	for (int i=2;i<n;i++) g=__gcd(g,a[i]);
	if ((b%g+g)%g==((k%g)+g)%g) printYES;
	else printNO;
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