#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int n,m,a[M];
struct node
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<2];int a[M];
	#define l(k) t[(k)].tl
	#define r(k) t[(k)].tr
	#define tag(k) t[(k)].tag
	#define val(k) t[(k)].val
	#define lson k<<1
	#define rson k<<1|1
	void pushup(int k)
	{
		val(k)=val(lson)+val(rson);
	}
	void change(int k)
	{
		val(k)=r(k)-l(k)+1-val(k);
	}
	void pushdown(int k)
	{
		if (!tag(k))return;
		change(lson),tag(lson)^=1;
		change(rson),tag(rson)^=1;
		tag(k)=0; 
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)
		{
			val(k)=a[l];
			return;
		}
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r)
	{
		if (l(k)>r||r(k)<l)return;
		if (l(k)>=l&&r(k)<=r)
		{
			change(k);tag(k)^=1;
			return;
		}
		pushdown(k);
		update(lson,l,r),update(rson,l,r);
		pushup(k);
	}
	int query(int k,int l,int r)
	{
		
		if (l(k)>r||r(k)<l)return 0;
		if (l(k)>=l&&r(k)<=r)return val(k);
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r);
	}
}T[25];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		for (int j=0;j<=20;j++)
			if ((1<<j)&a[i])T[j].a[i]=1;
	}
	for (int i=0;i<=20;i++)T[i].build(1,1,n);
	m=read();
	while(m--)
	{
		int op=read();
		if (op==1)
		{
			int l=read(),r=read();long long ans=0;
			for (int i=0;i<=20;i++)
				ans+=(1ll<<i)*T[i].query(1,l,r);
			cout<<ans<<endl;
		}
		else
		{
			int l=read(),r=read(),z=read();
			for (int i=0;i<=20;i++)
				if (z&(1<<i))
					T[i].update(1,l,r);
		}
	}
	return 0;
}