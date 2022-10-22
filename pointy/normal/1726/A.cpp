// Author: Little09
// Problem: A. Mainak and Array
// Contest: Codeforces - Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.ml/contest/1726/problem/0
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
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	int ans=a[n]-a[1];
	for (int i=2;i<=n;i++) ans=max(ans,a[i]-a[1]);
	for (int i=1;i<n;i++) ans=max(ans,a[n]-a[i]);
	for (int i=1;i<n;i++) ans=max(ans,a[i]-a[i+1]);
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