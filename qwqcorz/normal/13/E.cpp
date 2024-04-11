#include<bits/stdc++.h>
#define ls t[x].son[0]
#define rs t[x].son[1]
using namespace std;
const int N=1e5+5;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct Link_Cut_Tree
{
	int s,son[2],fa,tag;
}t[N];
int st[N],top=0;
bool where(int x)
{
	return t[t[x].fa].son[1]==x;
}
bool isroot(int x)
{
	return t[t[x].fa].son[0]!=x&&t[t[x].fa].son[1]!=x;
}
void pushup(int x)
{
	t[x].s=t[ls].s+t[rs].s+1;
}
void pushdown(int x)
{
	if (!t[x].tag) return;
	swap(ls,rs);
	t[x].tag=0;
	t[ls].tag^=1;
	t[rs].tag^=1;
}
void connect(int x,int y,int ch)
{
	t[x].fa=y;
	t[y].son[ch]=x;
}
void rotate(int x)
{
	int y=t[x].fa;
	int R=t[y].fa;
	int wx=where(x);
	int wy=where(y);
	int B=t[x].son[wx^1];
	t[x].fa=R;
	if (!isroot(y)) connect(x,R,wy);
	connect(B,y,wx);
	connect(y,x,wx^1);
	pushup(y);
	pushup(x);
}
void splay(int x)
{
	top=1;
	st[1]=x;
	for (int i=x;!isroot(i);i=t[i].fa) st[++top]=t[i].fa;
	for (;top;top--) pushdown(st[top]);
	while (!isroot(x))
	{
		int f=t[x].fa;
		if (!isroot(f))
		{
			if (where(f)==where(x)) rotate(f);
							   else rotate(x);
		}
		rotate(x);
	}
}
void access(int x)
{
	for (int y=0;x;y=x,x=t[x].fa)
	{
		splay(x);
		rs=y;
		pushup(x);
	}
}
void makeroot(int x)
{
	access(x);
	splay(x);
	t[x].tag^=1;
}
int findroot(int x)
{
	access(x);
	splay(x);
	while (ls) x=ls;
	splay(x);
	return x;
}
void split(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
}
int query(int x,int y)
{
	split(x,y);
	return t[y].s;
}
void link(int x,int y)
{
	makeroot(x);
	if (findroot(y)==x) return;
	t[x].fa=y;
}
void cut(int x,int y)
{
	makeroot(x);
	if (findroot(y)!=x||t[y].fa!=x||t[y].son[0]) return;
	rs=t[y].fa=0;
	pushup(x);
}
int p[N];
int prev(int x)
{
	pushdown(x);
	x=ls;
	while (1)
	{
		pushdown(x);
		if (!rs) break;
		x=rs;
	}
	return x;
}

int main()
{
	memset(t,0,sizeof(t));
	int n=read(),m=read();
	for (int i=1;i<=n+1;i++) t[i].s=1;
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) link(i,min(i+p[i],n+1));
	for (int i=1;i<=m;i++)
	{
		int opt=read(),x,y;
		if (opt==0)
		{
			x=read();
			y=read();
			cut(x,min(x+p[x],n+1));
			p[x]=y;
			link(x,min(x+p[x],n+1));
		}
		else
		{
			x=read();
			int ans=query(x,n+1);
			print(prev(n+1),' ');
			print(ans-1);
		}
	}

	return 0;
}