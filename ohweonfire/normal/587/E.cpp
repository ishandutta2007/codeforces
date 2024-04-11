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

struct basis
{
	int n,a[30];
	void clear(){n=0;}
	basis(){clear();}
	basis(int x){if(x)n=1;else n=0;a[0]=x;}
	void add(int x)
	{
		for(int i=0;i<n;i++)if(a[i]&-a[i]&x)x^=a[i];
		if(!x)return;
		for(int i=0;i<n;i++)if(x&-x&a[i])a[i]^=x;
		a[n++]=x;
	}
};
basis comb(const basis&a,const basis&b)
{
	basis ret;
	if(a.n>b.n){ret=a;for(int i=0;i<b.n;i++)ret.add(b.a[i]);}
	else{ret=b;for(int i=0;i<a.n;i++)ret.add(a.a[i]);}
	return ret;
}
int a[200111],mx;
struct SGT
{
	struct node
	{
		int l,r;
		basis v;
	}seg[600111];
#define lson (t<<1)
#define rson ((t<<1)|1)
	void build(int l,int r,int t=1)
	{
		seg[t].l=l;seg[t].r=r;
		mx=max(mx,t);
		if(l==r)
		{
			seg[t].v=basis(a[l]);
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
		seg[t].v=comb(seg[lson].v,seg[rson].v);
	}
	void modify(int p,int v,int t=1)
	{
		if(seg[t].l==seg[t].r)
		{
			seg[t].v=basis(v);
			return;
		}
		int mid=(seg[t].l+seg[t].r)>>1;
		if(p<=mid)modify(p,v,lson);
		else modify(p,v,rson);
		seg[t].v=comb(seg[lson].v,seg[rson].v);
	}
	basis query(int l,int r,int t=1)
	{
		if(l>r)return basis();
		if(seg[t].l==l&&seg[t].r==r)return seg[t].v;
		int mid=(seg[t].l+seg[t].r)>>1;
		if(r<=mid)return query(l,r,lson);
		else if(l>mid)return query(l,r,rson);
		else return comb(query(l,mid,lson),query(mid+1,r,rson));
	}
}sgt;
int bit[200111],n,q;
void add(int x,int v){for(;x<200111;x+=x&-x)bit[x]^=v;}
int query(int x){int ret=0;for(;x;x-=x&-x)ret^=bit[x];return ret;}
int main()
{
	get2(n,q);
	for(int i=1;i<=n;i++)
		get1(a[i]);
	for(int i=n;i>=1;i--){a[i]^=a[i-1];add(i,a[i]);}
	sgt.build(1,n);
	int tp,l,r,k;
	for(int i=1;i<=q;i++)
	{
		get3(tp,l,r);
		if(tp==1)
		{
			get1(k);
			add(l,k);add(r+1,k);a[l]^=k;a[r+1]^=k;
			sgt.modify(l,a[l]);if(r<n)sgt.modify(r+1,a[r+1]);
		}
		else
		{
			basis now=sgt.query(l+1,r);
			now.add(query(l));
			printf("%d\n",1<<now.n);
		}
	}
	return 0;
}