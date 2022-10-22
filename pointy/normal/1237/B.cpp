// Author: Little09
// Problem: B. Balanced Tunnel
// Contest: Codeforces Global Round 5
// URL: https://codeforces.com/contest/1237/problem/B
// Memory Limit: 512 MB
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N],p[N],c[N],d[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> c[i];
	for (int i=1;i<=n;i++) a[i]=c[n+1-i];
	for (int i=1;i<=n;i++) p[a[i]]=i;
	for (int i=1;i<=n;i++) cin >> d[i];
	for (int i=1;i<=n;i++) b[i]=d[n+1-i];
	int mx=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		mx=max(mx,p[b[i]]);
		if (mx>p[b[i]]) ans++; 
	}
	cout << ans;
	return 0;
}