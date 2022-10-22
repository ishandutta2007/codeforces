// Author: Little09
// Problem: B. Prefix Sum Addicts
// Contest: Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/B
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll a[N],b[N];


void work()
{
	cin >> n >> m;
	for (int i=n-m+1;i<=n;i++) cin >> a[i];
	if (m==1)
	{
		printYes;
		return;
	}
	for (int i=n-m+2;i<=n;i++) b[i]=a[i]-a[i-1];
	for (int i=2;i<=n-m+1;i++) b[i]=b[n-m+2];
	b[1]=a[n];
	for (int i=2;i<=n;i++) b[1]-=b[i];
	for (int i=2;i<=n;i++) 
	{
		if (b[i]<b[i-1])
		{
			printNo;
			return;
		}
	}
	printYes;
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