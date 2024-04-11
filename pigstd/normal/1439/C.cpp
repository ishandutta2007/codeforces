#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int n,q,a[M],y;
struct tree
{
	int tl,tr,sum,minn,tag;
}t[M<<2];
#define l(x) t[(x)].tl
#define r(x) t[(x)].tr
#define sum(x) t[(x)].sum
#define tag(x) t[(x)].tag
#define len(x) (r(x)-l(x)+1)
#define minn(x) t[(x)].minn
#define lson k<<1
#define rson k<<1|1

void pushup(int k)
{
	sum(k)=sum(lson)+sum(rson);
	minn(k)=min(minn(lson),minn(rson));
}

void pushdown(int k)
{
	if (tag(k)==0)return;
	minn(lson)=minn(rson)=tag(k);
	sum(lson)=tag(k)*len(lson),
	sum(rson)=tag(k)*len(rson);
	tag(lson)=tag(rson)=tag(k);
	tag(k)=0;
}

void build(int k,int l,int r)
{
	l(k)=l,r(k)=r;
	if (l==r)
	{
		sum(k)=minn(k)=a[l];
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
		minn(k)=z,sum(k)=len(k)*z,tag(k)=z;
		return;
	}
	if (l(k)>r||r(k)<l)return;
	pushdown(k);
	update(lson,l,r,z),update(rson,l,r,z);
	pushup(k);
}

int query(int k,int l,int r)
{
	if (l(k)>=l&&r(k)<=r)return sum(k);
	if (l(k)>r||r(k)<l)return 0;
	pushdown(k);
	return query(lson,l,r)+query(rson,l,r);
}

int solve(int k,int x)
{
	if (l(k)==r(k))return l(k);
	pushdown(k);
	if (x>=minn(lson))return solve(lson,x);
	else return solve(rson,x);
}

int query(int k)
{
	if (sum(k)<=y){y-=sum(k);return len(k);}
	if (l(k)==r(k))return 0;pushdown(k);int res=0;
	if (minn(lson)<=y)res+=query(lson);
	if (minn(rson)<=y)res+=query(rson);
	return res;
}

signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);
	while(q--)
	{
		int opt=read(),x=read();y=read();
		if (opt==1)
			update(1,solve(1,y),x,y);
		else
		{
			y+=query(1,1,x-1);
			cout<<query(1)-x+1<<endl;
		}
	}
	return 0;
}