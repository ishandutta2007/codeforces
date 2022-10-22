// Author: Little09
// Problem: F. The Struggling Contestant
// Contest: Codeforces Global Round 12
// URL: https://codeforces.com/contest/1450/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m; 
int a[N],b[N],c[N];

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) b[i]=0,c[i]=0;
	int k=1;
	for (int i=1;i<n;i++)
	{
		if (a[i]==a[i+1]) b[i]=1,k++;
	}
	c[a[1]]++,c[a[n]]++;
	for (int i=1;i<n;i++) if (b[i]) c[a[i]]++,c[a[i+1]]++;
	int u=1;
	for (int i=1;i<=n;i++) if (c[i]>c[u]) u=i;
	int res=c[u]-(k+1),ans=k;
	for (int i=1;i<n;i++) if (b[i]==0&&a[i]!=u&&a[i+1]!=u&&res>0) res--,ans++;
	if (res<=0) cout << ans-1 << endl;
	else cout << -1 << endl;
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