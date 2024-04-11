// Author: Little09
// Problem: D. Edge Split
// Contest: Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/contest/1726/problem/D
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N],ans[N];
int fa[N],c[N],cnt;
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void work()
{
	cin >> n >> m;
	for (int i=1;i<=m;i++) 
	{
		cin >> a[i] >> b[i];
		if (a[i]>b[i]) swap(a[i],b[i]);
		ans[i]=0;
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	cnt=0;
	for (int i=1;i<=m;i++)
	{
		int x=find(a[i]),y=find(b[i]);
		if (x!=y) 
		{
			ans[i]=1;
			fa[x]=y;
		}
		else c[++cnt]=i;
	}
	if (cnt<=2)
	{
		for (int i=1;i<=m;i++) cout << ans[i];
		cout << endl;
		return;
	}
	for (int i=1;i<=n;i++) fa[i]=i;
	int fl=0;
	for (int i=1;i<=cnt;i++)
	{
		int x=find(a[c[i]]),y=find(b[c[i]]);
		if (x!=y) 
		{
			fa[x]=y;
		}
		else fl=1;
	}
	if (fl==0)
	{
		for (int i=1;i<=m;i++) cout << ans[i];
		cout << endl;
		return;
	}
	for (int i=1;i<=m;i++) ans[i]=0;
	ans[c[1]]=1,ans[c[2]]=-1,ans[c[3]]=-1;
	for (int i=1;i<=n;i++) fa[i]=i;
	fa[a[c[1]]]=b[c[1]];
	for (int i=1;i<=m;i++)
	{
		if (ans[i]!=0) continue;
		int x=find(a[i]),y=find(b[i]);
		if (x!=y) 
		{
			ans[i]=1;
			fa[x]=y;
		}
	}
	for (int i=1;i<=m;i++) if (ans[i]<0) ans[i]=0;
	for (int i=1;i<=m;i++) cout << ans[i];
	cout << endl;
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