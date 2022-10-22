// Author: Little09
// Problem: A. ConneR and the A.R.C. Markland-N
// Contest: Codeforces Round #614 (Div. 2)
// URL: https://codeforces.com/contest/1293/problem/A
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
int n,m,s; 
map<int,int>a;


void work()
{
	cin >> n >>s >> m;
	a.clear();
	for (int i=1;i<=m;i++)
	{
		int x;
		cin >> x;
		a[x]=1;
	}
	int u=max(s-2000,1),v=min(s+2000,n),ans=1e9;
	for (int i=u;i<=v;i++) if (a[i]==0) ans=min(ans,abs(i-s));
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