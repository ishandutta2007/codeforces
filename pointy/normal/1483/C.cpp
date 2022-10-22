// Author: Little09
// Problem: E. Skyline Photo
// Contest: Codeforces Round #709 (Div. 2, based on Technocup 2021 Final Round)
// URL: https://codeforces.com/contest/1484/problem/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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

const int N=300005;
int n,m; 
int a[N];
ll b[N];
ll s[N*4],tag[N*4];
inline void push_up(int u)
{
	s[u]=max(s[u*2],s[u*2+1]);
}
inline void push_down(int u)
{
	if (tag[u]==-inf) return;
	s[u*2]=max(s[u*2],tag[u]);
	s[u*2+1]=max(s[u*2+1],tag[u]);
	tag[u*2]=max(tag[u*2],tag[u]);
	tag[u*2+1]=max(tag[u*2+1],tag[u]);
	tag[u]=-inf;
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		s[u]=-inf,tag[u]=-inf;
		if (l==0) s[u]=0;
		return;
	}
	tag[u]=-inf;
	//cout << s[9] << endl;
	int mid=(l+r)>>1;
	build(u*2,l,mid),build(u*2+1,mid+1,r);
	push_up(u);
}
ll ask(int u,int L,int R,int l,int r)
{
	// if (l==1&&r==1)
	// {
		// cout << "ask " << u << " "<< L << " " << R << " " << s[u] << endl;
	// }
	if (l<=L&&R<=r) return s[u];
	int mid=(L+R)>>1;
	ll res=-inf;
	push_down(u);
	if (l<=mid) res=max(res,ask(u*2,L,mid,l,r));
	if (r>mid) res=max(res,ask(u*2+1,mid+1,R,l,r));
	return res;
}
void update(int u,int L,int R,int l,int r,ll x)
{
	// if (l==3&&r==5)
	// {
		// cout << u << " " <<L <<" "<<R<<" "<<l<<" "<<r<<" "<<x<<endl;
	// }
	if (l<=L&&R<=r)
	{
		s[u]=max(s[u],x);
		tag[u]=max(tag[u],x);
		return;
	}
	push_down(u);
	int mid=(L+R)>>1;
	if (l<=mid) update(u*2,L,mid,l,r,x);
	if (mid<r) update(u*2+1,mid+1,R,l,r,x);
	push_up(u);
}
int f[N][21];
void STwork()
{
	for (int i=1;i<=n;i++) f[i][0]=a[i];
	int t=log2(n);
	for (int i=1;i<=t;i++)
	{
		for (int j=1;j<=n-(1<<i)+1;j++)
		{
			f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
		}
	}
}
int STquery(int l,int r)
{
	int t=log2(r-l+1);
	return min(f[l][t],f[r-(1<<t)+1][t]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	build(1,0,n);
	//cout << "---" << s[9] << endl;
	STwork();
	//cout << "---" << ask(1,0,n,1,1) << endl;
	for (int i=1;i<=n;i++)
	{
		int L,R,l=1,r=i;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (STquery(mid,i)==a[i]) r=mid-1;
			else l=mid+1;
		}
		L=l;
		l=i,r=n;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (STquery(i,mid)==a[i]) l=mid+1;
			else r=mid-1;
		}
		R=r;
		//cout << L << " " << R << endl;
		ll op=ask(1,0,n,L-1,i-1);
		//cout << op+b[i] << endl;
		update(1,0,n,i,R,op+b[i]);
		// cout << i << " " << R << " " << op+b[i] << endl;
		// cout << "---" << ask(1,0,n,1,1) << endl;
	}
	cout << ask(1,0,n,n,n) << endl;
	return 0;
}