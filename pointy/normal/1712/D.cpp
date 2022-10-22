// Author: Little09
// Problem: D. Empty Graph
// Contest: Codeforces Round #813 (Div. 2)
// URL: https://codeforces.com/contest/1712/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
int a[N],b[N];
bool check(int x)
{
	for (int i=1;i<=n;i++) b[i]=a[i];
	int u=0;
	for (int i=1;i<=n;i++) if (a[i]*2<x) b[i]=1e9,u++;
	int ans=0;
	for (int i=1;i<n;i++)
	{
		ans=max(ans,min(b[i],b[i+1]));
	}
	if (ans<x)
	{
		if (u>0) u++;
		else 
		{
			u++;
			for (int i=1;i<=n;i++)
			{
				ans=max(ans,b[i]);
			}
			if (ans<x) u++;
		}
	}
	if (u<=m) return 1;
	return 0;
}

void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	int l=1,r=1000000000;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout << r << endl;
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