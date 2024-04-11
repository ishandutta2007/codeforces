#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=2e5+10;
int n,b[M],pp[M],cnt;
map<int,int>tt;

struct segment_tree
{
	struct tree{int tl,tr,val,tag;}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define len(x) (r(x)-l(x)+1)
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{val(k)=val(lson)+val(rson);}
	void pushdown(int k)
	{val(lson)+=tag(k)*len(lson),val(rson)+=tag(k)*len(rson);tag(lson)+=tag(k),tag(rson)+=tag(k);tag(k)=0;}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;tag(k)=val(k)=0;
		if (l==r)return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
		if (l(k)>=l&&r(k)<=r){val(k)+=z*len(k),tag(k)+=z;return;}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T;

signed main()
{
	WT
	{
		n=read();cnt=0;tt.clear();
		for (int i=1;i<=n;i++)b[i]=pp[i]=read();
		sort(pp+1,pp+1+n);
		for (int i=1;i<=n;i++)
			if (i==1||pp[i]!=pp[i-1])tt[pp[i]]=++cnt;
		for (int i=1;i<=n;i++)b[i]=tt[b[i]];
		T.build(1,1,cnt),T.update(1,b[1],b[1],1);
		int f=1;
		for (int i=2;i<=n;i++)
		{
			int x=b[i-1],y=b[i];
			if (x>y)swap(x,y);
			if (T.query(1,x+1,y-1)>0)f=0;
			T.update(1,b[i],b[i],1);
		}
		if (f)YES
		else NO
	}
	return 0;
}