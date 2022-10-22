// Author: Little09
// Problem: F. Swaps Again
// Contest: Codeforces Round #648 (Div. 2)
// URL: https://codeforces.com/contest/1365/problem/F
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
int a[N],b[N];
map<pair<int,int>,int>q;


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	q.clear();
	for (int i=1;i<=(n)/2;i++)
	{
		if (a[i]>a[n+1-i]) swap(a[i],a[n+1-i]);
		q[make_pair(a[i],a[n+1-i])]++;
	}
	for (int i=1;i<=(n)/2;i++)
	{
		if (b[i]>b[n+1-i]) swap(b[i],b[n+1-i]);
		q[make_pair(b[i],b[n+1-i])]--;
		if (q[make_pair(b[i],b[n+1-i])]<0)
		{
			printNo;
			return;
		}
	}
	if (n%2==1&&a[n/2+1]!=b[n/2+1]) printNo;
	else printYes;
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