#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[N];
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		int l0,l1,l01,l10;
		int r0,r1,r01,r10;
		int ans01,ans10,len,tag;
		node(){}
		node(int x)
		{
			l01=l10=r01=r10=ans01=ans10=len=1,tag=0;
			if (x) l1=r1=1,l0=r0=0;
			  else l0=r0=1,l1=r1=0;
		}
		void flip()
		{
			swap(l0,l1);
			swap(l01,l10);
			swap(r0,r1);
			swap(r01,r10);
			swap(ans01,ans10);
			tag^=1;
		}
		friend node operator +(node a,node b)
		{
			node ret;
			ret.len=a.len+b.len,ret.tag=0;
			ret.ans01=max({a.ans01,b.ans01,a.r01+b.l1,a.r0+b.l01});
			ret.ans10=max({a.ans10,b.ans10,a.r10+b.l0,a.r1+b.l10});
			ret.l0=a.l0==a.len?a.len+b.l0:a.l0;
			ret.l1=a.l1==a.len?a.len+b.l1:a.l1;
			ret.r0=b.r0==b.len?b.len+a.r0:b.r0;
			ret.r1=b.r1==b.len?b.len+a.r1:b.r1;
			ret.l01=a.l0==a.len?a.len+b.l01:(a.l01==a.len?a.len+b.l1:a.l01);
			ret.l10=a.l1==a.len?a.len+b.l10:(a.l10==a.len?a.len+b.l0:a.l10);
			ret.r01=b.r1==b.len?b.len+a.r01:(b.r01==b.len?b.len+a.r0:b.r01);
			ret.r10=b.r0==b.len?b.len+a.r10:(b.r10==b.len?b.len+a.r1:b.r10);
			return ret;
		}
	}t[N*4];
	void push_down(int w)
	{
		if (!t[w].tag) return;
		t[ls].flip();
		t[rs].flip();
		t[w].tag=0;
	} 
	void flip(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w].flip();
		push_down(w);
		if (ql<=mid) flip(ls,l,mid,ql,qr);
		if (qr>mid) flip(rs,mid+1,r,ql,qr);
		t[w]=t[ls]+t[rs];
	}
	node query(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w];
		push_down(w);
		if (qr<=mid) return query(ls,l,mid,ql,qr);
		if (ql>mid) return query(rs,mid+1,r,ql,qr);
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	void build(int w,int l,int r)
	{
		if (l==r) return t[w]=node(s[l]=='<'),void();
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
}t;

signed main()
{
	int n=read(),Q=read();
	scanf("%s",s+1);
	t.build(1,1,n);
	while (Q--)
	{
		int l=read(),r=read();
		t.flip(1,1,n,l,r);
		print(t.query(1,1,n,l,r).ans01);
	}
	
	return 0;
}