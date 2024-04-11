#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int a[M],b[M],n,m;

int lowbit(int x){return x&(-x);}

struct node
{
	struct tree
	{
		int tl,tr,val,tag;
	}t[M<<2];int c[M];
	#define l(k) t[(k)].tl
	#define r(k) t[(k)].tr
	#define val(k) t[(k)].val
	#define tag(k) t[(k)].tag
	#define lson k<<1
	#define rson k<<1|1
	void pushdown(int k)
	{
		if (!tag(k))return;
		tag(lson)=tag(rson)=tag(k);
		val(lson)=(r(lson)-l(lson)+1)*tag(k);
		val(rson)=(r(rson)-l(rson)+1)*tag(k);
		tag(k)=0;
	}
	void pushup(int k)
	{
		val(k)=val(lson)+val(rson);
	}
	void build(int k,int l,int r)
	{
		l(k)=l,r(k)=r;
		if (l==r)
			return;
		int Mid=(l+r)>>1;
		build(lson,l,Mid),build(rson,Mid+1,r);
		pushup(k);
		
	}
	int query(int k,int l,int r)
	{
//		if (l<1)return 0;
		if (l(k)>=l&&r(k)<=r)return val(k);
		if (l(k)>r||r(k)<l)return 0;
		pushdown(k);
		return query(lson,l,r)+query(rson,l,r); 
	}
	void update(int k,int l,int r,int z)
	{
//		if (k==1)cout<<l<<' '<<r<<' '<<z<<endl;
		if (l(k)>=l&&r(k)<=r)
		{
			val(k)=(r(k)-l(k)+1)*z;
			tag(k)=z;
			return;
		}
		if (l(k)>r||r(k)<l)return;
		pushdown(k);
		update(lson,l,r,z),update(rson,l,r,z);
		pushup(k);
	}
}T;

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)b[i]=read();
	T.build(1,1,n+1);
	while(m--)
	{
		int op=read();
		if (op==1)
		{
			int x=read(),y=read(),k=read();
			//y->x
			int r1=T.query(1,1,y-1);
			int r2=T.query(1,1,y+k);
			T.update(1,y,y,x-r1);
			T.update(1,y+1,y+k-1,1);
			T.update(1,y+k,y+k,r2-(x+k-1));
	//		cout<<y+k<<' '<<r2-(x+k-1)<<endl;
//			for (int i=1;i<=n;i++)cout<<T.query(1,1,i)<<' ';
//			puts("");
		}
		else
		{
			int k=read();
			int r=T.query(1,1,k);
			if (r==0)cout<<b[k]<<endl;
			else cout<<a[r]<<endl;
		}
//		puts("");
	}
	return 0;
}