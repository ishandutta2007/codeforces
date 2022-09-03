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
	struct node
	{
		int l,r,mx,delta;
	}seg[600111];
	void build(int l,int r,int t=1)
	{
		seg[t].l=l;seg[t].r=r;seg[t].delta=0;
		if(l==r)
		{
			seg[t].mx=l;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
		seg[t].mx=max(seg[lson].mx,seg[rson].mx);
	}
	void pushdown(int t)
	{
		seg[lson].delta+=seg[t].delta;seg[rson].delta+=seg[t].delta;
		seg[lson].mx+=seg[t].delta;seg[rson].mx+=seg[t].delta;
		seg[t].delta=0;
	}
	void add(int l,int r,int v,int t=1)
	{
		if(l>r)return;
		if(seg[t].l==l&&seg[t].r==r)
		{
			seg[t].delta+=v;
			seg[t].mx+=v;
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
	int query(){return seg[1].mx;}
}sgt;

int a[150111],b[150111],h,n,l;
int getid(int x){return lower_bound(a+1,a+l+1,h-x)-a;}
int main()
{
	get3(n,l,h);
	for(int i=1;i<=l;i++)get1(a[i]);
	for(int i=1;i<=n;i++)get1(b[i]);
	
	sgt.build(1,l,1);sort(a+1,a+l+1);
	for(int i=1;i<l;i++)sgt.add(getid(b[i]),l,-1);
	int ans=0;
	for(int i=l;i<=n;i++)
	{
//		printf("i= %d\n",i);
		sgt.add(getid(b[i]),l,-1);
		if(sgt.query()<=0)
			ans++;
		sgt.add(getid(b[i-l+1]),l,1);
	}
	printendl(ans);
	return 0;
}