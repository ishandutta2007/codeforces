// Author: Little09
// Problem: B. Nezzar and Binary String
// Contest: Codeforces Round #698 (Div. 1)
// URL: https://codeforces.com/contest/1477/problem/B
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

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
char a[N],b[N];
int c[N],d[N];

int sum[N*4],add[N*4];
inline void push_up(int u)
{
	sum[u]=sum[u*2]+sum[u*2+1];
}
inline void push_down(int u,ll len)
{
	if (add[u]!=-1)
	{
		sum[u*2]=(len+1)/2*add[u];
		sum[u*2+1]=(len)/2*add[u];
		add[u*2]=add[u];
		add[u*2+1]=add[u];
		add[u]=-1;
	}
}
void build(int u,int l,int r)
{
	add[u]=-1;
	if (l==r)
	{
		sum[u]=b[l]-'0';
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	push_up(u);
}
ll ask(int u,int L,int R,int l,int r)
{
	if (l<=L&&R<=r) return sum[u];
	int mid=(L+R)>>1;
	push_down(u,R-L+1);
	ll res=0;
	if (l<=mid) res+=ask(u*2,L,mid,l,r);
	if (mid<r) res+=ask(u*2+1,mid+1,R,l,r);
	return res;
}
void change(int u,int L,int R,int l,int r,int k)
{
	if (l<=L&&R<=r) 
	{
		sum[u]=(R-L+1)*k;
		add[u]=k;
		return;
	}
	int mid=(L+R)>>1;
	push_down(u,R-L+1);
	if (l<=mid) change(u*2,L,mid,l,r,k);
	if (mid<r) change(u*2+1,mid+1,R,l,r,k);
	push_up(u);
}

void work()
{
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	for (int i=1;i<=m;i++) cin >> c[i] >> d[i];
	build(1,1,n);
	for (int i=m;i>=1;i--)
	{
		int l=c[i],r=d[i];
		int u=ask(1,1,n,l,r);
		int len=r-l+1;
		int v=len-u;
		if (u==v)
		{
			printNO;
			return;
		}
		if (u>v) change(1,1,n,l,r,1);
		else change(1,1,n,l,r,0);
	}
	int ans=1;
	// for (int i=1;i<=n;i++) cout << ask(1,1,n,i,i) << " ";
	// cout << endl;
	for (int i=1;i<=n;i++) if (a[i]-'0'!=ask(1,1,n,i,i)) ans=0;
	if (ans==1) printYES;
	else printNO;
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