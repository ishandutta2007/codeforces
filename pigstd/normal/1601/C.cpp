#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
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

const int M=2e6+10;
int n,m,a[M],b[M],p[M];
map<int,int>t; 
pair<int,int>pp[M]; 

struct segment_tree
{
	struct node
	{
		int tl,tr,val1,val2,val;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val1(x) t[(x)].val1
	#define val2(x) t[(x)].val2
	#define val(x) t[(x)].val
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		val1(k)=val1(lson)+val1(rson),
		val2(k)=val2(lson)+val2(rson),
		val(k)=min(val(lson)+val2(rson),val1(lson)+val(rson)); 
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){val1(k)=1,val2(k)=val(k)=0;return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update1(int k,int l,int z)
	{
		if (l(k)>l||r(k)<l)return;
		if (l(k)==l&&r(k)==l){val1(k)=z;return;}
		update1(lson,l,z),update1(rson,l,z);
		pushup(k);
	}
	void update2(int k,int l,int z)
	{
		if (l(k)>l||r(k)<l)return;
		if (l(k)==l&&r(k)==l){val2(k)=z;return;}
		update2(lson,l,z),update2(rson,l,z);
		pushup(k);
	}
	int query(){return val(1);} 
}T;

struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void add(int u,int x)
	{
		for (int i=u;i<=n+m;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=c[i];
		return res;
	}
}T2;

signed main()
{
	WT
	{
		n=read(),m=read();t.clear();
		for (int i=1;i<=n;i++)p[i]=a[i]=read();
		for (int i=1;i<=m;i++)p[i+n]=b[i]=read();
		sort(b+1,b+1+m);sort(p+1,p+1+n+m);int cnt=0;
		for (int i=1;i<=n+m;i++)
			if (p[i]!=p[i-1])t[p[i]]=++cnt;
		for (int i=1;i<=n;i++)a[i]=t[a[i]];
		for (int i=1;i<=m;i++)b[i]=t[b[i]];
		long long res=0;T.build(1,1,n);
		for (int i=n;i>=1;i--)
			res+=T2.ask(a[i]-1),T2.add(a[i],1);
		for (int i=n;i>=1;i--)
			T2.add(a[i],-1);
		for (int i=1;i<=n;i++)pp[i]=mp(a[i],i);
		sort(pp+1,pp+1+n);int l1=1,l2=1;
		for (int i=1;i<=m;i++)
		{
			while(l1<=n&&pp[l1].x<=b[i])T.update1(1,pp[l1].y,0),l1++;
			while(l2<=n&&pp[l2].x<b[i])T.update2(1,pp[l2].y,1),l2++;
			res+=T.query();
		}printf("%lld\n",res);
	}
	return 0;
}
/*
1
3 3
3 2 1
1 2 3
*/