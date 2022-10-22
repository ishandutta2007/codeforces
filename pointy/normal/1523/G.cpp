// Author: Little09
// Problem: G. Try Booking
// Contest: Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/G
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
#define lowbit(x) (x&(-x))

const int inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=200005;
int n,m; 
struct point
{
	int l,r,c;
}a[N],b[N];
bool cmp(point x,point y)
{
	return x.r-x.l>y.r-y.l;
}
int rt[N],tot,ans[N];
int lc[N*100],rc[N*100],s[N*100];
inline int make_node()
{
	++tot;
	lc[tot]=0,rc[tot]=0,s[tot]=inf;
	return tot;
}
inline void push_up(int u)
{
	s[u]=min(s[lc[u]],s[rc[u]]);
}
void add(int &u,int l,int r,int x,int y)
{
	if (!u) u=make_node();
	if (l==r) 
	{
		s[u]=min(s[u],y);
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) add(lc[u],l,mid,x,y);
	else add(rc[u],mid+1,r,x,y);
	push_up(u);
}
int query(int u,int L,int R,int l,int r)
{
	if (!u) return inf;
	if (l<=L&&R<=r) return s[u];
	int mid=(L+R)>>1,res=inf;
	if (l<=mid) res=min(res,query(lc[u],L,mid,l,r));
	if (mid<r) res=min(res,query(rc[u],mid+1,R,l,r));
	return res;
}
void addseg(int l,int r,int x)
{
	for (;r<=n;r+=lowbit(r)) add(rt[r],1,n,l,x);
}
int ask(int l,int r)
{
	int res=inf;
	for (;r;r-=lowbit(r)) res=min(res,query(rt[r],1,n,l,n));
	return res;
}
int dfs(int l,int r)
{
	if (l>r) return 0;
	int t=ask(l,r);
	if (t==inf) return 0;
	int res=b[t].r-b[t].l+1;
	res+=dfs(l,b[t].l-1);
	res+=dfs(b[t].r+1,r);
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	s[0]=inf;
	cin >> n >> m;
	for (int i=1;i<=m;i++)
	{
		cin >> a[i].l >> a[i].r;
		a[i].c=i;
		b[i]=a[i];
	}
	sort(a+1,a+m+1,cmp);
	int tot=1;
	for (int i=n;i>=1;i--)
	{
		while (tot<=m&&a[tot].r-a[tot].l+1==i) 
		{
			addseg(a[tot].l,a[tot].r,a[tot].c);
			//cout << a[tot].l << " " << a[tot].r << endl;
			tot++;
		}
		ans[i]=dfs(1,n);
	}
	for (int i=1;i<=n;i++) cout << ans[i] << endl;
	return 0;
}