//AFO countdown:14 Days
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
int n,q,a[M],f[M];

struct segment_tree
{
	struct tree
	{
		int tl,tr,tag,val,maxn;
	}t[M<<2];
	#define l(x) t[(x)].tl
	#define r(x) t[(x)].tr
	#define val(x) t[(x)].val
	#define tag(x) t[(x)].tag
	#define maxn(x) t[(x)].maxn
	#define len(x) (r(x)-l(x)+1)
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		maxn(k)=max(maxn(lson),maxn(rson));
		val(k)=val(lson)+val(rson);
	}
	void pushdown(int k)
	{
		if (tag(k)==0)return;
		maxn(lson)=maxn(rson)=tag(k),
		val(lson)=len(lson)*tag(k),
		val(rson)=len(rson)*tag(k),
		tag(lson)=tag(rson)=tag(k),
		tag(k)=0;
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r){val(k)=maxn(k)=f[l];return;}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int z)
	{
//		if (k==1)cout<<1<<'q'<<l<<' '<<r<<' '<<z<<endl;
		if (l(k)>=l&&r(k)<=r)
		{
			maxn(k)=z,val(k)=len(k)*z;
			tag(k)=z;return;
		}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
//		if (k==1)cout<<2<<'q'<<l<<' '<<r<<endl;
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
	int find(int k,int l)
	{
		if (l(k)==r(k))return l(k);pushdown(k);
		if (maxn(lson)>=l)return find(lson,l);
		else return find(rson,l);
	}
}T;

signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	f[n]=n;for (int i=n-1;i>=1;i--)
		if (a[i]<=a[i+1])f[i]=f[i+1];
		else f[i]=i;
	T.build(1,1,n);
	for (int i=1;i<=n;i++)
		T.update(1,i,i,f[i]);//cout<<f[i]<<' ';
	while(q--)
	{
		int opt=read(),l=read(),r=read();
		if (opt==1)
		{
			if (l!=n)
			{
				int x=T.query(1,l+1,l+1);
				if (r<=a[l+1])T.update(1,l,l,x);
				else T.update(1,l,l,l);
			}
			if (l!=1)
			{
				int x=T.query(1,l-1,l-1);
				if (a[l-1]<=r)T.update(1,T.find(1,x),l-1,T.query(1,l,l));
				else T.update(1,T.find(1,x),l-1,l-1);
			}
			a[l]=r;
		}
		else
		{
			int x=T.find(1,r)-1,res=-(l+r-2)*(r-l+1)/2;
//			cout<<x<<' '<<res<<' '<<"qwq";
			if (x<l)res+=(r-l+1)*r;
			else res+=T.query(1,l,x)+(r-x)*r;
//			if (l==8&&r==10)
//				for (int j=l;j<=r;j++)
//					cout<<T.query(1,j,j)<<' ';puts("qwq");
			printf("%lld\n",res);
		}
	}
	return 0;
}