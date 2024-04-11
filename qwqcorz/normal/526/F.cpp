#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int p[N],s1[N],t1=0,s2[N],t2=0;
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		int mn,tot,tag;
		friend node operator +(node a,node b)
		{
			node ret; ret.tag=ret.tot=0;
			ret.mn=min(a.mn,b.mn);
			if (a.mn==ret.mn) ret.tot+=a.tot;
			if (b.mn==ret.mn) ret.tot+=b.tot;
			return ret;
		}
		void update(int x)
		{
			mn+=x;
			tag+=x;
		}
	}t[N*4];
	void push_down(int w)
	{
		if (!t[w].tag) return;
		t[ls].update(t[w].tag);
		t[rs].update(t[w].tag);
		t[w].tag=0;
	}
	void build(int w,int l,int r)
	{
		if (l==r) return t[w]=(node){1,1,0},void();
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return t[w].update(x);
		push_down(w);
		add(ls,l,mid,ql,qr,x);
		add(rs,mid+1,r,ql,qr,x);
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
	#undef mid
	#undef rs
	#undef ls
}t;

signed main()
{
	ll ans=0;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		p[x]=y;
	}
	t.build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		while (t1&&p[s1[t1]]<p[i])
		{
			t.add(1,1,n,s1[t1-1]+1,s1[t1],p[i]-p[s1[t1]]);
			t1--;
		}
		s1[++t1]=i;
		while (t2&&p[s2[t2]]>p[i])
		{
			t.add(1,1,n,s2[t2-1]+1,s2[t2],p[s2[t2]]-p[i]);
			t2--;
		}
		s2[++t2]=i;
		t.add(1,1,n,1,i,-1);
		auto now=t.query(1,1,n,1,i);
		if (now.mn==0) ans+=now.tot;
	}
	print(ans);
	
	return 0;
}