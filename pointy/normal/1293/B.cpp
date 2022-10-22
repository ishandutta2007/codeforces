// Author: Little09
// Problem: B. JOE is on TV!
// Contest: Codeforces Round #614 (Div. 2)
// URL: https://codeforces.com/contest/1293/problem/B
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
	double ans=0;
	for (int i=1;i<=n;i++) ans=ans+1.0/(i*1.0);
	printf("%.10lf\n",ans);
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	int T=1;
	while (T--) work();
	return 0;
}