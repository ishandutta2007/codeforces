// Author: Little09
// Problem: C. Parity Shuffle Sorting
// Contest: Codeforces - Codeforces Round #821 (Div. 2)
// URL: https://codeforc.es/contest/1733/problem/C
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
#define endl "\n"
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
	cout << n-1 << endl;
	if (n!=1) cout << 1 << " " << n << endl;
	for (int i=2;i<n;i++)
	{
		if ((a[i]+a[1])&1) cout << "1 " << i << endl;
		else cout << i << " " << n << endl;
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