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

const int M=1e5+10;
int n,a[M],q;
vector<pair<int,int>>v;
struct node
{
	int lmx,lmn,rmx,rmn,lmxp,lmnp,rmxp,rmnp,mx,mn,mxl,mxr,mnl,mnr,sum;
	void work()
	{
		swap(lmxp,lmnp),swap(rmxp,rmnp),swap(mxl,mnl),swap(mxr,mnr);
		int tmp=lmx;lmx=-lmn,lmn=-tmp;sum*=-1;
		tmp=rmx,rmx=-rmn,rmn=-tmp,tmp=mx,mx=-mn,mn=-tmp;
	}
	void init(int x,int pos)
	{
		lmx=lmn=rmx=rmn=mx=mn=sum=x;
		lmxp=rmxp=lmnp=rmnp=mxl=mxr=mnl=mnr=pos;
	}
};
node merge(node a,node b)
{
	node c;c.sum=a.sum+b.sum;
	if (a.lmx>b.lmx+a.sum)c.lmx=a.lmx,c.lmxp=a.lmxp;
	else c.lmx=b.lmx+a.sum,c.lmxp=b.lmxp;
	if (a.lmn<b.lmn+a.sum)c.lmn=a.lmn,c.lmnp=a.lmnp;
	else c.lmn=b.lmn+a.sum,c.lmnp=b.lmnp;
	if (b.rmx>a.rmx+b.sum)c.rmx=b.rmx,c.rmxp=b.rmxp;
	else c.rmx=a.rmx+b.sum,c.rmxp=a.rmxp;
	if (b.rmn<a.rmn+b.sum)c.rmn=b.rmn,c.rmnp=b.rmnp;
	else c.rmn=a.rmn+b.sum,c.rmnp=a.rmnp;
	if (a.mx>b.mx)c.mx=a.mx,c.mxl=a.mxl,c.mxr=a.mxr;
	else c.mx=b.mx,c.mxl=b.mxl,c.mxr=b.mxr;
	if (a.rmx+b.lmx>c.mx)c.mx=a.rmx+b.lmx,c.mxl=a.rmxp,c.mxr=b.lmxp;
	if (a.mn<b.mn)c.mn=a.mn,c.mnl=a.mnl,c.mnr=a.mnr;
	else c.mn=b.mn,c.mnl=b.mnl,c.mnr=b.mnr;
	if (a.rmn+b.lmn<c.mn)c.mn=a.rmn+b.lmn,c.mnl=a.rmnp,c.mnr=b.lmnp;
	return c;
}
struct segment_tree
{
	struct tree
	{
		int tl,tr,tag;
		node val;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define lson k<<1
	#define rson k<<1|1
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;tag(k)=1;
		if (l==r){val(k).init(a[l],l);return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		val(k)=merge(val(lson),val(rson));
	}
	void pushdown(int k)
	{
		if (tag(k)==-1)
		{
			tag(lson)*=-1,tag(rson)*=-1,
			val(lson).work(),val(rson).work();
			tag(k)=1;
		}
	}
	void update1(int k,int l,int z)
	{
		if (l(k)==l&&r(k)==l){val(k).init(z,l);return;}
		if (l(k)>l||r(k)<l)return;pushdown(k);
		update1(lson,l,z),update1(rson,l,z);
		val(k)=merge(val(lson),val(rson));
	}
	void update2(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r){val(k).work(),tag(k)*=-1;return;}
		if (l(k)>r||r(k)<l)return;pushdown(k);
		update2(lson,l,r),update2(rson,l,r);
		val(k)=merge(val(lson),val(rson));
	}
	node query(int k,int l,int r)
	{
		if (l(k)>=l&&r(k)<=r)return val(k);
		pushdown(k);
		if (r(lson)>=l&&l(rson)<=r)return merge(query(lson,l,r),query(rson,l,r));
		else if (l(rson)>r)return query(lson,l,r);
		else return query(rson,l,r);
	}
}T;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	T.build(1,1,n);q=read();
	while(q--)
	{
		int opt=read();
		if (opt==0)
		{
			int pos=read(),val=read();
			T.update1(1,pos,val);
		}
		else
		{
			int l=read(),r=read(),k=read(),res=0;v.clear();
			for (int i=1;i<=k;i++)
			{
				node x=T.query(1,l,r);
				if (x.mx<0)break;
				res+=x.mx,T.update2(1,x.mxl,x.mxr),
				v.pb(mp(x.mxl,x.mxr));
			}printf("%lld\n",res);
			for (auto x:v)
				T.update2(1,x.x,x.y);
		}
	}
	return 0;
}

/*
15
-4 8 -3 -10 10 4 -7 -7 0 -6 3 8 -10 7 2
15
0 6 5
0 10 -7
1 4 9 1
*/