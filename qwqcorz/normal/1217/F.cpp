#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct Change
{
	int x,y,z,id;
}c[N*2];
pair<int,int>q[N];
map<pair<int,int>,pair<int,int> >mp;
int last,n,m,cntc=0;
vector<Change>t[N*4];
void add(int w,int l,int r,int L,int R,int x,int y,int z)
{
//	if (l==1&&r==n)
//	{
//		print(L,',');
//		print(R,' ');
//		print(x,',');
//		print(y,' ');
//		print(z);
//	}
	if (r<L||R<l) return;
	if (L<=l&&r<=R) return void(t[w].push_back((Change){x,y,z,l==L}));
	add(ls,l,mid,L,R,x,y,z);
	add(rs,mid+1,r,L,R,x,y,z);
}
map<pair<int,int>,bool>Map;
int fa[N],siz[N],st[N],top=0;
int find(int x)
{
	return fa[x]==x?x:find(fa[x]);
}
void solve(int w,int l,int r)
{
//	print(l,' ');
//	print(r,':');
//	puts("");
	int tmp=top;
	for (auto i=t[w].begin();i!=t[w].end();i++)
	{
//		print(i->x,' ');
//		print(i->y,' ');
//		print(i->z,' ');
//		print(i->id);
		if (i->id) Map[mk(i->x,i->y)]^=i->z==last;
		if (Map[mk(i->x,i->y)])
		{
			int u=find(i->x),v=find(i->y);
			if (u==v) continue;
			if (siz[u]>siz[v]) swap(u,v);
			fa[u]=v;
			siz[v]+=siz[u];
			st[++top]=u;
		}
	}
//	puts("");
	if (l==r&&q[l].fi)
	{
		int lastans=find((q[l].fi+last-1)%n+1)==find((q[l].se+last-1)%n+1);
		putchar(lastans+'0');
		last=lastans&&n>2;
	}
	if (l==r) return;
	solve(ls,l,mid);
	solve(rs,mid+1,r);
	while (tmp<top)
	{
		siz[fa[st[top]]]-=siz[st[top]];
		fa[st[top]]=st[top];
		top--;
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	n=read();
	m=read();
	for (int i=1;i<=m;i++)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1)
		{
			c[++cntc]=(Change){x,y,0,i};
			if (n>2) c[++cntc]=(Change){x%n+1,y%n+1,1,i};
		}
		else q[i]=mk(x,y);
	}
	for (int i=1;i<=cntc;i++)
	{
		if (c[i].x>c[i].y) swap(c[i].x,c[i].y);
//		print(c[i].x,' ');print(c[i].y,':');print(c[i].z);
		if (mp.count(mk(c[i].x,c[i].y)))
		add(1,1,m,mp[mk(c[i].x,c[i].y)].fi,c[i].id-1,c[i].x,c[i].y,mp[mk(c[i].x,c[i].y)].se);
		mp[mk(c[i].x,c[i].y)]=mk(c[i].id,c[i].z);
	}
	for (auto i=mp.begin();i!=mp.end();i++) add(1,1,m,i->se.fi,m,i->fi.fi,i->fi.se,i->se.se);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++) siz[i]=1;
	solve(1,1,m);

	return 0;
}