// Author: Little09
// Problem: F. Euclid's nightmare
// Contest: Good Bye 2020
// URL: https://codeforces.com/contest/1466/problem/F
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
const ll mod=1000000007;

const int N=500005;
int n,m; 
struct point
{
	int x,y;
}a[N],b[N];
int ans[N],cnt;
int fa[N];
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		a[i].x=m+1,a[i].y=m+1;
		if (x==1) cin >> a[i].x;
		else 
		{
			cin >> a[i].x >> a[i].y;
			if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
		}
	}
	for (int i=1;i<=m+1;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
	{
		int x=find(a[i].x),y=find(a[i].y);
		if (x==m+1&&y==m+1) continue;
		if (x==y) continue;
		if (x>y) swap(x,y);
		fa[x]=y;
		ans[++cnt]=i;
	}
	cout << ksm(2,cnt) << " " << cnt << endl;
	for (int i=1;i<=cnt;i++) cout << ans[i] << " ";
	return 0;
}