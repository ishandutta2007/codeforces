#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--)
#define NO puts("NO");
#define YES puts("YES");
#define l(x) t[(x)].tl
#define r(x) t[(x)].tr
#define val(x) t[(x)].val
#define tag(x) t[(x)].tag
#define lson k<<1
#define rson k<<1|1
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=2e5+10;
int n,a[M],f[M];
vector<int>v[M];

struct segment_tree1
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<2];
	void pushup(int k){val(k)=min(val(lson),val(rson));}
	void pushdown(int k)
	{
		tag(lson)+=tag(k),tag(rson)+=tag(k);
		val(lson)+=tag(k),val(rson)+=tag(k);
		tag(k)=0;
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;val(k)=tag(k)=0;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r){val(k)+=z,tag(k)+=z;return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return inf;
		pushdown(k);
		return min(query(lson,l,r),query(rson,l,r));
	}
}T1;
struct segment_tree2
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<2];
	void pushup(int k){val(k)=max(val(lson),val(rson));}
	void pushdown(int k)
	{
		tag(lson)+=tag(k),tag(rson)+=tag(k);
		val(lson)+=tag(k),val(rson)+=tag(k);
		tag(k)=0;
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;val(k)=0,tag(k)=0;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r){val(k)+=z,tag(k)+=z;return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return -inf;
		pushdown(k);
		return max(query(lson,l,r),query(rson,l,r));
	}
}T2;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read(),v[a[i]].pb(i);
	T1.build(1,0,n),T2.build(1,0,n);
	for (int i=1;i<=n;i++)T1.update(1,i,n,1),T2.update(1,i,n,1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v[i].size();j++)
		{
			int u=v[i][j];
			f[u]=max(f[u],T2.query(1,u,n)-T1.query(1,0,u-1));
//			if (u==1)
//			{
//				cout<<T2.query(1,u,n)<<' '<<T1.query(1,0,u-1)<<endl;
//				for (int i=1;i<=n;i++)cout<<T2.query(1,i,i)<<' ';puts("");
//			}
		}
		for (int j=0;j<v[i].size();j++)
			T1.update(1,v[i][j],n,-2),T2.update(1,v[i][j],n,-2);
	}
//	for (int i=1;i<=n;i++)cout<<f[i]/2<<' ';puts("");
	T1.build(1,0,n),T2.build(1,0,n);
	for (int i=1;i<=n;i++)T1.update(1,i,n,1),T2.update(1,i,n,1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<v[i].size();j++)
			T1.update(1,v[i][j],n,-2),T2.update(1,v[i][j],n,-2);
		for (int j=0;j<v[i].size();j++)
		{
			int u=v[i][j];
			f[u]=max(f[u],T2.query(1,0,u-1)-T1.query(1,u,n)-1);
		}
	}
	for (int i=1;i<=n;i++)cout<<f[i]/2<<' ';puts("");
	return 0;
}