// LUOGU_RID: 90800477
// Author: Little09
// Problem: CF870E Points, Lines and Ready-made Titles
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF870E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define endl "\n"
#define printYes cout << "Yes\n"
#define printYES cout << "YES\n"
#define printNo cout << "No\n"
#define printNO cout << "NO\n"
#define lowbit(x) ((x)&(-(x)))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
const ll mod=1000000007;

const int N=500005;
int n,m; 
int a[N],b[N],c[N];

map<int,int>p,q;
int tot;

int fa[N],d[N];
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	fa[x]=y;
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
	cin >> n;
	for (int i=1;i<=2*n;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin >> x >> y;
		if (q[x]==0) q[x]=++tot;
		if (p[y]==0) p[y]=++tot;
		a[i]=q[x],b[i]=p[y];
		merge(a[i],b[i]);
	}
	for (int i=1;i<=2*n;i++) 
	{
		c[find(i)]++;
	}
	for (int i=1;i<=n;i++) d[find(a[i])]++;
	ll ans=1;
	for (int i=1;i<=2*n;i++)
	{
		if (find(i)!=i) continue;
		if (c[i]>d[i]) ans=ans*(ksm(2,c[i])-1)%mod;
		else ans=ans*ksm(2,c[i])%mod;
	}
	cout << ans;
	return 0;
}