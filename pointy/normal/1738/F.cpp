// Author: Little09
// Problem: F. Connectivity Addicts
// Contest: Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/F
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
int d[N],fa[N];
bool vis[N];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x!=y) fa[x]=y;
	else return 1;
	return 0;
}

void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) cin >> d[i];
	for (int i=1;i<=n;i++) vis[i]=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	while (1)
	{
		int maxu=-1;
		for (int i=1;i<=n;i++)
		{
			if (vis[i]) continue;
			if (maxu==-1||d[maxu]<d[i]) maxu=i;
		}
		if (maxu==-1) break;
		vis[maxu]=1;
		for (int i=1;i<=d[maxu];i++)
		{
			cout << "? " << maxu << endl;
			fflush(stdout);
			int v;
			cin >> v;
			merge(maxu,v);
			if (vis[v]) break;
			vis[v]=1;
		}
	}
	cout << "! ";
	for (int i=1;i<=n;i++) cout << find(i) << " ";
	cout << endl;
	fflush(stdout);
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}