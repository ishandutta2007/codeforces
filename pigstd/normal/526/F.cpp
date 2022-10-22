#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18;
const int M=3e5+10;
int n,p[M],t[M];
struct segment_tree
{
	struct tree
	{
		int tl,tr,minn,val,tag;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define minn(x) t[(x)].minn
	#define lson k<<1
	#define rson k<<1|1
	void pushdown(int k){minn(lson)+=tag(k),minn(rson)+=tag(k),tag(lson)+=tag(k),tag(rson)+=tag(k),tag(k)=0;}
	void pushup(int k)
	{
		minn(k)=min(minn(lson),minn(rson));
		if (minn(lson)==minn(rson))val(k)=val(lson)+val(rson);
		else if (minn(lson)<minn(rson))val(k)=val(lson);
		else val(k)=val(rson);
	}
	pii merge(pii a,pii b){return mp(min(a.x,b.x),a.x==b.x?a.y+b.y:(a.x<b.x?a.y:b.y));}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;val(k)=r-l+1;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r)return tag(k)+=z,minn(k)+=z,void();
		if (l(k)>r||r(k)<l)return; 
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	pii query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return mp(minn(k),val(k));
		if (l(k)>r||r(k)<l)return mp(inf,0);
		pushdown(k);
		return merge(query(lson,l,r),query(rson,l,r));
	}
}T;

signed main()
{
	n=read();T.build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		p[x]=y,t[y]=x;
	}int res=0;
	for (int i=1;i<=n;i++)
	{
		T.update(1,1,i,1);
		if (t[i]!=1&&p[t[i]-1]<i)T.update(1,1,p[t[i]-1],-1);
		if (t[i]!=n&&p[t[i]+1]<i)T.update(1,1,p[t[i]+1],-1);
		res+=T.query(1,1,i).y;
//		cout<<res<<' ';
//		for (int i=1;i<=n;i++)cout<<T.query(1,i,i).x<<' ';puts("");
	}
	cout<<res<<endl;
	return 0;
}