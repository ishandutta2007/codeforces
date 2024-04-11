// Author: Little09
// Problem: A1. Burenka and Traditions (easy version)
// Contest: Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/A1
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
int a[N],dp[N];
map<int,int>q;


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	q.clear();
	q[0]=0;
	for (int i=1;i<=n;i++) a[i]^=a[i-1];
	for (int i=1;i<=n;i++)
	{
		int x=q[a[i]];
		q[a[i]]=i;
		dp[i]=dp[i-1];
		if (a[i]!=0&&x==0) continue;
		else if (x==0) dp[i]=max(dp[i],1);
		else dp[i]=max(dp[i],dp[x]+1);
	}
	cout << n-dp[n] << endl;
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