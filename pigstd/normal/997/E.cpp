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
const int M=1.2e5+10;
int n,q,p[M],t[M],ans[M];
vector<pii>a[M];
struct segment_tree
{
	struct tree
	{
		int tl,tr,tag1,tag2,val,minn,sum;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define minn(x) t[(x)].minn
	#define sum(x) t[(x)].sum
	#define tag1(x) t[(x)].tag1
	#define tag2(x) t[(x)].tag2
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		sum(k)=sum(lson)+sum(rson);val(k)=0;
		minn(k)=min(minn(lson),minn(rson)); 
		if (minn(k)==minn(lson))val(k)+=val(lson);
		if (minn(k)==minn(rson))val(k)+=val(rson);
	}
	void add1(int k,int x){minn(k)+=x,tag1(k)+=x;}
	void add2(int k,int x){sum(k)+=x*val(k),tag2(k)+=x;}
	void pushdown(int k)
	{
		if (tag1(k))
			add1(lson,tag1(k)),add1(rson,tag1(k)),tag1(k)=0;
		if (tag2(k))
		{
			if (minn(lson)==minn(k))add2(lson,tag2(k));
			if (minn(rson)==minn(k))add2(rson,tag2(k));
			tag2(k)=0;
		}
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r,val(k)=1,minn(k)=inf;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
	}
	void upd(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r)return add1(k,z),void();
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		upd(lson,l,r,z),upd(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return sum(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T;

signed main()
{
	n=read();T.build(1,1,n);
	for (int i=1;i<=n;i++)t[p[i]=read()]=i;
	q=read();
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		a[r].pb(mp(l,i));
	}
	for (int i=1;i<=n;i++)
	{
		T.upd(1,i,i,-inf);T.upd(1,1,i,1);
		if (p[i]!=1&&t[p[i]-1]<i)T.upd(1,1,t[p[i]-1],-1);
		if (p[i]!=n&&t[p[i]+1]<i)T.upd(1,1,t[p[i]+1],-1);
		T.add2(1,1);
		for (auto x:a[i])
			ans[x.y]=T.query(1,x.x,i);
	}
	for (int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}