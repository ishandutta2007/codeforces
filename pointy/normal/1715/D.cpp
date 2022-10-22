// Author: Little09
// Problem: D. 2+ doors
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/D
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
 
const int N=200005;
int n,m; 
int ans[N],a[N],b[N],c[N];
int d[N];
vector<int>t[N];
 
void work(int p)
{
	for (int i=1;i<=n;i++) t[i].clear();
	for (int i=1;i<=n;i++) d[i]=-1;
	for (int i=1;i<=m;i++)
	{
		int x=a[i],y=b[i],z=((c[i]&(1<<p))!=0);
		if (z==0) d[x]=0,d[y]=0;
		else if (x==y) d[x]=z;
		else t[x].push_back(y),t[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
	{
		if (d[i]!=-1) continue;
		bool fl=0;
		for (int j:t[i]) if (d[j]==0) fl=1;
		d[i]=fl;
	}
	for (int i=1;i<=n;i++) ans[i]^=(d[i]<<p);
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=m;i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i=0;i<=30;i++) work(i);
	for (int i=1;i<=n;i++) cout << ans[i] << " ";
	return 0;
}