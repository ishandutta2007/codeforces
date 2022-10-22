#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n,m,ans[M];
struct node
{
	int x,y,p;
}a[M];
bool cmp1(node a,node b)
{
	return a.x-a.y<b.x-b.y;
}
bool cmp2(node a,node b)
{
	return a.p<b.p;
}
struct segment_tree
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define len(x) (r(x)-l(x)+1)
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		val(k)=val(lson)+val(rson);
	}
	void pushdown(int k)
	{
		val(lson)+=tag(k)*len(lson);
		val(rson)+=tag(k)*len(rson);
		tag(lson)+=tag(k),tag(rson)+=tag(k);
		tag(k)=0;
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)
		{
			val(k)=0;
			return;
		}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r)
		{
			tag(k)+=z;val(k)+=len(k)*z;
			return;
		}if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)
			return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T1,T2,T3;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i].x=read(),a[i].y=read(),a[i].p=i;
	sort(a+1,a+1+n,cmp1);T1.build(1,1,n),T2.build(1,1,n),T3.build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		T1.update(1,1,i-1,a[i].y),T1.update(1,i+1,n,a[i].x);
		T2.update(1,1,i-1,1),T3.update(1,i+1,n,1);
	}
	for (int i=1;i<=n;i++)
		ans[a[i].p]=T1.query(1,i,i)+T2.query(1,i,i)*a[i].x+T3.query(1,i,i)*a[i].y;
	sort(a+1,a+1+n,cmp2);
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();int cnt=min(a[x].x+a[y].y,a[x].y+a[y].x);
		ans[x]-=cnt,ans[y]-=cnt;
	}
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}