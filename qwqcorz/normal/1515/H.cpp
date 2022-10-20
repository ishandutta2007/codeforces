#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int m=(1<<20)-1;
const int LOG=20;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct trie
{
	#define ls t[w].son[0]
	#define rs t[w].son[1]
	#define mid ((l+r)/2)
	int cnt=1;
	struct node
	{
		int sum,son[2],tag,or0,or1;
	}t[N*LOG];
	void push_up(int w)
	{
		t[w].sum=t[ls].sum+t[rs].sum;
		t[w].or0=t[ls].or0|t[rs].or0;
		t[w].or1=t[ls].or1|t[rs].or1;
	}
	void update(int d,int w,int x)
	{
		if (d) if (x>>(d-1)&1) swap(ls,rs);
		t[w].tag^=x;
		int u=t[w].or0&x,v=t[w].or1&x;
		t[w].or0=t[w].or0&~x|v;
		t[w].or1=t[w].or1&~x|u;
	}
	void push_down(int d,int w)
	{
		if (!t[w].tag) return;
		if (ls) update(d-1,ls,t[w].tag);
		if (rs) update(d-1,rs,t[w].tag);
		t[w].tag=0;
	}
	int st[N*LOG],top=0;
	int newNode()
	{
		if (top) return st[top--];
		return ++cnt;
	}
	void deleteNode(int x)
	{
		t[x]=node();
		st[++top]=x;
	}
	void insert(int x)
	{
		int now=1;
		t[now].or1|=x;
		t[now].or0|=x^m;
		t[now].sum++;
		for (int i=LOG-1;i>=0;i--)
		{
			if (!t[now].son[x>>i&1]) t[now].son[x>>i&1]=++cnt;
			now=t[now].son[x>>i&1];
			t[now].or1|=x;
			t[now].or0|=x^m;
			t[now].sum++;
		}
	}
	int split(int d,int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return w;
		push_down(d,w);
		int now=newNode();
		if (ql<=mid) t[now].son[0]=split(d-1,ls,l,mid,ql,qr),ls=ql<=l&&qr>=mid?0:ls;
		if (qr>mid) t[now].son[1]=split(d-1,rs,mid+1,r,ql,qr),rs=qr>=r&&ql<=mid+1?0:rs;
		push_up(now),push_up(w);
		return now;
	}
	int merge(int d,int x,int y)
	{
		if (x==y) return x;
		if (!x||!y) return x|y;
		push_down(d,x),push_down(d,y);
		t[x].son[0]=merge(d-1,t[x].son[0],t[y].son[0]);
		t[x].son[1]=merge(d-1,t[x].son[1],t[y].son[1]);
		deleteNode(y);
		if (d) push_up(x);
		else
		{
			t[x].sum=t[x].sum||t[y].sum;
			t[x].or0=t[x].or0|t[y].or0;
			t[x].or1=t[x].or1|t[y].or1;
		}
		return x;
	}
	void zyk(int d,int w,int x)
	{
		if ((t[w].or0&t[w].or1&x)==0)
		{
			update(d,w,t[w].or0&x);
			return;
		}
		push_down(d,w);
		if (ls&&(x>>(d-1)&1))
		{
			update(d-1,ls,1<<(d-1));
			rs=merge(d-1,rs,ls);
			ls=0;
		}
		if (x>>(d-1)&1) x^=1<<(d-1);
		if (ls) zyk(d-1,ls,x);
		if (rs) zyk(d-1,rs,x);
		if (d) push_up(w);
	}
	void OR(int l,int r,int x)
	{
		int w=split(LOG,1,0,m,l,r);
		zyk(LOG,w,x);
		merge(LOG,1,w);
	}
	void XOR(int l,int r,int x)
	{
		int w=split(LOG,1,0,m,l,r);
		update(LOG,w,x);
		merge(LOG,1,w);
	}
	void AND(int l,int r,int x)
	{
		int w=split(LOG,1,0,m,l,r);
		update(LOG,w,m);
		zyk(LOG,w,x^m);
		update(LOG,w,m);
		merge(LOG,1,w);
	}
	int query(int d,int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql||!w) return 0;
		if (ql<=l&&r<=qr) return t[w].sum;
		push_down(d,w);
		return query(d-1,ls,l,mid,ql,qr)+query(d-1,rs,mid+1,r,ql,qr);
	}
	#undef mid
	#undef rs
	#undef ls
}t;

signed main()
{
	int n=read(),Q=read();
	set<int>S;
	for (int i=1;i<=n;i++) S.insert(read());
	for (int i:S) t.insert(i);
	while (Q--)
	{
		int opt=read(),l=read(),r=read();
		if (opt==1) t.AND(l,r,read());
		if (opt==2) t.OR(l,r,read());
		if (opt==3) t.XOR(l,r,read());
		if (opt==4) print(t.query(LOG,1,0,m,l,r));
	}
	
	return 0;
}