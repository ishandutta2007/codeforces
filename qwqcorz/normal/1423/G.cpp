#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

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
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int tot[N*4],sum[N*4],tag[N*4];
	void update(int w,int l,int r,int y)
	{
		tag[w]+=y;
		tot[w]+=y*(r-l+1);
		sum[w]+=(l+r)*(r-l+1)/2*y;
	}
	void push_up(int w)
	{
		tot[w]=tot[ls]+tot[rs];
		sum[w]=sum[ls]+sum[rs];
	}
	void push_down(int w,int l,int r)
	{
		if (!tag[w]) return;
		update(ls,l,mid,tag[w]);
		update(rs,mid+1,r,tag[w]);
		tag[w]=0;
	}
	void add(int w,int l,int r,int ql,int qr,int y)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return update(w,l,r,y);
		push_down(w,l,r);
		if (ql<=mid) add(ls,l,mid,ql,qr,y);
		if (qr>mid) add(rs,mid+1,r,ql,qr,y);
		push_up(w);
	}
	void add(int w,int l,int r,int x,int y) {add(w,l,r,x,x,y);}
	int querytot(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return tot[w];
		push_down(w,l,r);
		return querytot(ls,l,mid,ql,qr)+querytot(rs,mid+1,r,ql,qr);
	}
	int querysum(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return sum[w];
		push_down(w,l,r);
		return querysum(ls,l,mid,ql,qr)+querysum(rs,mid+1,r,ql,qr);
	}
	#undef ls
	#undef rs
	#undef mid
}t,tl,tr;
struct Query
{
	int opt,l,r,x;
}q[N];
struct node
{
	int l,r,x;
	bool operator <(const node &a)const
	{
		return l==a.l?r<a.r:l<a.l;
	}
};
set<node>s,c[N];
int a[N],b[N],last[N];

signed main()
{
	int n=read(),m=read(),cnt=n;
	for (int i=1;i<=n;i++) b[i]=a[i]=read();
	for (int i=1;i<=m;i++)
	{
		q[i].opt=read();
		if (q[i].opt==1) q[i].l=read(),q[i].r=read(),b[++cnt]=q[i].x=read();
		else q[i].x=read();
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
	for (int i=1;i<=m;i++) if (q[i].opt==1) q[i].x=lower_bound(b+1,b+1+cnt,q[i].x)-b;
	for (int i=1;i<=n;i++) s.insert((node){i,i,a[i]});
	for (int i=1;i<=n;i++) c[a[i]].insert((node){i,i,a[i]});
	for (int i=1;i<=n;i++)
	{
		t.add(1,1,n,i-last[a[i]],1);
		tl.add(1,1,n,last[a[i]],1);
		tr.add(1,1,n,i,1);
		last[a[i]]=i;
	}
	for (int i=1;i<=cnt;i++) c[i].insert((node){0,0,i});
	for (int i=1;i<=m;i++)
	if (q[i].opt==1)
	{
		int l=q[i].l,r=q[i].r,x=q[i].x;
		///////////////////////////////////////////////////
		auto tmp=s.upper_bound((node){l,n,0});tmp--;
		if ((tmp->l)!=l)
		{
			c[tmp->x].insert((node){tmp->l,l-1,tmp->x});
			c[tmp->x].insert((node){l,tmp->r,tmp->x});
			c[tmp->x].erase(*tmp);
			s.insert((node){tmp->l,l-1,tmp->x});
			s.insert((node){l,tmp->r,tmp->x});
			s.erase(tmp);
		}
		///////////////////////////////////////////////////
		tmp=s.upper_bound((node){r,n,0});tmp--;
		if ((tmp->r)!=r)
		{
			c[tmp->x].insert((node){tmp->l,r,tmp->x});
			c[tmp->x].insert((node){r+1,tmp->r,tmp->x});
			c[tmp->x].erase(*tmp);
			s.insert((node){tmp->l,r,tmp->x});
			s.insert((node){r+1,tmp->r,tmp->x});
			s.erase(tmp);
		}
		///////////////////////////////////////////////////
		auto now=s.lower_bound((node){l,0,0});
		while (now!=s.end()&&(now->r)<=r)
		{
			auto nxt=now;nxt++;
			auto M=c[now->x].lower_bound(*now),L=M,R=M;L--,R++;
			t.add(1,1,n,1,(M->l)-(M->r));
			tl.add(1,1,n,(M->l),(M->r)-1,-1);
			tr.add(1,1,n,(M->l)+1,M->r,-1);
			t.add(1,1,n,(M->l)-(L->r),-1);
			tl.add(1,1,n,L->r,-1);
			tr.add(1,1,n,M->l,-1);
			if (R!=c[now->x].end())
			{
				t.add(1,1,n,(R->l)-(M->r),-1);
				tl.add(1,1,n,M->r,-1);
				tr.add(1,1,n,R->l,-1);
				t.add(1,1,n,(R->l)-(L->r),1);
				tl.add(1,1,n,L->r,1);
				tr.add(1,1,n,R->l,1);
			}
			c[now->x].erase(M);
			s.erase(now);
			now=nxt;
		}
		///////////////////////////////////////////////////
		c[x].insert((node){l,r,x});
		s.insert((node){l,r,x});
		auto M=c[x].lower_bound((node){l,r,x}),L=M,R=M;L--,R++;
		t.add(1,1,n,1,(M->r)-(M->l));
		tl.add(1,1,n,(M->l),(M->r)-1,1);
		tr.add(1,1,n,(M->l)+1,M->r,1);
		t.add(1,1,n,(M->l)-(L->r),1);
		tl.add(1,1,n,L->r,1);
		tr.add(1,1,n,M->l,1);
		if (R!=c[x].end())
		{
			t.add(1,1,n,(R->l)-(M->r),1);
			tl.add(1,1,n,M->r,1);
			tr.add(1,1,n,R->l,1);
			t.add(1,1,n,(R->l)-(L->r),-1);
			tl.add(1,1,n,L->r,-1);
			tr.add(1,1,n,R->l,-1);
		}
//		for (auto j:s) print(j.l,' '),print(j.r,':'),print(j.x);
	}
	else print(t.querysum(1,1,n,1,q[i].x)+t.querytot(1,1,n,q[i].x+1,n)*q[i].x
			 -(tr.querysum(1,1,n,n-q[i].x+1,n)-tr.querytot(1,1,n,n-q[i].x+1,n)*(n-q[i].x+1))
			 +(tl.querysum(1,1,n,n-q[i].x+1,n)-tl.querytot(1,1,n,n-q[i].x+1,n)*(n-q[i].x+1)));
	
	return 0;
}