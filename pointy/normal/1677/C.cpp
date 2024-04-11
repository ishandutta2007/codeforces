// Author: Little09
// Problem: CF1677C Tokitsukaze and Two Colorful Tapes
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1677C
// Memory Limit: 250 MB
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
int a[N],b[N],siz[N],c[N],cnt;
bool vis[N];
int fa[N];

int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}


void work()
{
	cin >> n;
	for (int i=1;i<=n;i++) 
	{
		int x;
		cin >> x;
		a[x]=i;
	}
	for (int i=1;i<=n;i++) 
	{
		int x;
		cin >> x;
		b[x]=i;
	}
	for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1,vis[i]=0;
	for (int i=1;i<=n;i++)
	{
		int x=find(a[i]),y=find(b[i]);
		if (x==y) continue;
		fa[x]=y,siz[y]+=siz[x];
	}
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		int x=find(i);
		if (vis[x]) continue;
		vis[x]=1;
		cnt+=siz[x]/2;
	}
	ll ans=0;
	for (int i=1;i<=cnt;i++) ans+=(n-i+1-i)*2;
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