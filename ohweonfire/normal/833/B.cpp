// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

#define lson (t<<1)
#define rson ((t<<1)|1)
struct SGT
{
	struct segment
	{
		int l,r,delta,mx;
	}seg[133333];
	void pushdown(int t)
	{
		seg[lson].delta+=seg[t].delta;seg[rson].delta+=seg[t].delta;
		seg[lson].mx+=seg[t].delta;seg[rson].mx+=seg[t].delta;
		seg[t].delta=0;
	}
	void build(int l,int r,int t=1)
	{
		seg[t].l=l;seg[t].r=r;seg[t].delta=seg[t].mx=0;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
	}
	void add(int l,int r,int v,int t=1)
	{
		if(l>r)return;
		if(seg[t].l==l&&seg[t].r==r)
		{
			seg[t].delta+=v;seg[t].mx+=v;
			return;
		}
		pushdown(t);
		int mid=(seg[t].l+seg[t].r)>>1;
		if(r<=mid)add(l,r,v,lson);
		else if(l>mid)add(l,r,v,rson);
		else
		{
			add(l,mid,v,lson);
			add(mid+1,r,v,rson);
		}
		seg[t].mx=max(seg[lson].mx,seg[rson].mx);
	}
	int query(int l,int r,int t=1)
	{
		if(l>r)return 0;
		if(seg[t].l==l&&seg[t].r==r)return seg[t].mx;
		pushdown(t);
		int mid=(seg[t].l+seg[t].r)>>1;
		if(r<=mid)return query(l,r,lson);
		else if(l>mid)return query(l,r,rson);
		else return max(query(l,mid,lson),query(mid+1,r,rson));
	}
}m1;

int n,k,a[35111],last[35111],pre[35111];
int dp[55][35111];
int main()
{
	get2(n,k);
	for(int i=1;i<=n;i++)
	{
		get1(a[i]);
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1;i<=n;i++)dp[1][i]=dp[1][i-1]+(pre[i]==0);
	for(int i=2;i<=k;i++)
	{
		m1.build(1,n);
		for(int j=1;j<=n;j++)m1.add(j,j,dp[i-1][j]);
		for(int j=1;j<=n;j++)
		{
			m1.add(max(1,pre[j]),j-1,1);
			dp[i][j]=m1.query(1,j-1);
		}
	}
	printendl(dp[k][n]);
	return 0;
}