#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+1;
const int LOG=75;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct segment_tree
{
	#define mid ((l+r+2)/2-1)
	struct node
	{
		int ls,rs,mn,tag;
		node(){ls=rs=mn=tag=0;}
		void add(int x){mn+=x,tag+=x;}
	}t[N*LOG];
	int cnt,rt;
	int new_node(int l,int r)
	{
		t[++cnt].mn=l;
		return cnt;
	}
	segment_tree(){cnt=0,rt=new_node(-1,mod);}
	void push_down(int w,int l,int r)
	{
		if (!t[w].ls) t[w].ls=new_node(l,mid);
		if (!t[w].rs) t[w].rs=new_node(mid+1,r);
		if (!t[w].tag) return;
		t[t[w].ls].add(t[w].tag);
		t[t[w].rs].add(t[w].tag);
		t[w].tag=0;
	}
	void add(int &w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return t[w].add(x);
		push_down(w,l,r);
		add(t[w].ls,l,mid,ql,qr,x);
		add(t[w].rs,mid+1,r,ql,qr,x);
		t[w].mn=min(t[t[w].ls].mn,t[t[w].rs].mn);
	}
	int find(int w,int l,int r,int x)
	{
		if (l==r) return l;
		push_down(w,l,r);
		if (t[t[w].rs].mn>x) return find(t[w].ls,l,mid,x);
						else return find(t[w].rs,mid+1,r,x);
	}
	int query(int w,int l,int r,int x)
	{
		if (l==r) return t[w].mn;
		push_down(w,l,r);
		if (x<=mid) return query(t[w].ls,l,mid,x);
			   else return query(t[w].rs,mid+1,r,x);
	}
	#undef mid
}t;
void GreenDay()
{
	int n=read();
	for (int i=1,lastans=0;i<=n;i++)
	{
		int T=read();
		int pos1=t.find(t.rt,-1,mod,T-1),pos2=t.find(t.rt,-1,mod,T);
		t.add(t.rt,-1,mod,-1,pos1,1);
		t.add(t.rt,-1,mod,pos2+1,mod,-1);
		int q=read();
		for (int i=1;i<=q;i++) print(lastans=t.query(t.rt,-1,mod,(read()+lastans)%mod));
	}
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}