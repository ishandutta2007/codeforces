#include<bits/stdc++.h>
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
int n,m,root;
struct edge {
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v) {
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
struct BIT {
	int t[N*2],n;
	void add(int x,int y) {
		for (;x<=n;x+=x&-x) t[x]+=y;
	}
	int query(int x) {
		int ret=0;
		for (;x;x=(x-1)&x) ret+=t[x];
		return ret;
	}
}b;
struct LCT
{
	#define ls son[0]
	#define rs son[1]
	struct node {
		int fa,son[2],siz,id,rev_tag;
	}t[N];
	bool isroot(int x) {
		return t[t[x].fa].ls!=x&&t[t[x].fa].rs!=x;
	}
	bool where(int x) {
		return t[t[x].fa].rs==x;
	}
	void push_up(int x) {
		t[x].siz=t[t[x].ls].siz+t[t[x].rs].siz+1;
	}
	void push_down(int x) {
		if (t[x].rev_tag) {
			swap(t[x].ls,t[x].rs);
			t[t[x].ls].rev_tag^=1;
			t[t[x].rs].rev_tag^=1;
			t[x].rev_tag=0;
		}
	}
	void connect(int x,int y,bool s) {
		t[x].fa=y,t[y].son[s]=x;
	}
	void rotate(int x)
	{
		int y=t[x].fa,R=t[y].fa,wx=where(x),wy=where(y),B=t[x].son[!wx];
		if (!isroot(y)) connect(x,R,wy);
				   else t[x].fa=R;
		connect(B,y,wx);
		connect(y,x,!wx);
		push_up(y);
		push_up(x);
	}
	void splay(int x)
	{
		static int st[N],top=0;
		st[++top]=x;
		for (int tmp=x;!isroot(tmp);tmp=t[tmp].fa) st[++top]=t[tmp].fa;
		while (top) push_down(st[top--]);
		for (;!isroot(x);rotate(x))
		if (!isroot(t[x].fa))
		rotate(where(t[x].fa)==where(x)?t[x].fa:x);
	}
	void access(int x) {
		for (int y=0;x;y=x,x=t[x].fa) {
			splay(x);
			b.add(t[find(x)].id,t[t[x].rs].siz-t[x].siz);
			t[x].rs=y;
			push_up(x);
		}
	}
	void make_root(int x) {
		if (root==x) return;
		root=x;
		access(x);
		splay(x);
//		for (int i=1;i<=n;i++)
//		{
//			print(i,':');
//			print(t[i].fa,' ');
//			print(t[i].son[0],' ');
//			print(t[i].son[1],':');
//			print(t[i].id,' ');
//			print(t[i].siz,':');
//			print(t[i].rev_tag);
//		}
		t[x].rev_tag^=1;
		t[find(x)].id=++n;
		b.add(n,t[x].siz);
	}
	int find(int x) {
		push_down(x);
		while (t[x].rs) x=t[x].rs,push_down(x);
		return x;
	}
	int query(int x) {
//		for (int i=1;i<=n;i++)
//		{
//			print(i,':');
//			print(t[i].fa,' ');
//			print(t[i].son[0],' ');
//			print(t[i].son[1],':');
//			print(t[i].id,' ');
//			print(t[i].siz,':');
//			print(t[i].rev_tag);
//		}
//		puts("");
		splay(x);
//		print(x);
//		print(find(x),',');
//		print(b.query(t[find(x)].id-1));
//		for (int i=1;i<=n;i++)
//		{
//			print(i,':');
//			print(t[i].fa,' ');
//			print(t[i].son[0],' ');
//			print(t[i].son[1],':');
//			print(t[i].id,' ');
//			print(t[i].siz,':');
//			print(t[i].rev_tag);
//		}
		return b.query(t[find(x)].id-1)+t[t[x].rs].siz+1;
	}
	#undef ls
	#undef rs
}t;
void dfs(int now,int father)
{
	b.add(now,1);
	t.t[now].id=now;
	t.t[now].siz=1;
	t.t[now].fa=father;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
	}
}

signed main()
{
	root=n=read(),m=read();
	b.n=n+m;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(n,0);
	for (int i=1;i<=n;i++)
	{
		t.access(i);
		t.splay(i);
		b.add(i,t.t[i].siz);
	}
//		for (int i=1;i<=n;i++)
//		{
//			print(i,':');
//			print(t.t[i].fa,' ');
//			print(t.t[i].son[0],' ');
//			print(t.t[i].son[1],':');
//			print(t.t[i].id,' ');
//			print(t.t[i].siz,':');
//			print(t.t[i].rev_tag);
//		}
//		puts("");
	for (int i=1;i<=m;i++)
	{
		string opt;
		cin>>opt;
		int u=read(),v=opt=="compare"?read():0;
		if (opt=="up") t.make_root(u);
		if (opt=="when") print(t.query(u));
		if (opt=="compare") print(t.query(u)<t.query(v)?u:v);
//		for (int j=1;j<=n;j++) print(b.query(j)-b.query(j-1),' ');puts("");
	}
	
	return 0;
}
/*
8 20
4 6
2 4
1 5
2 7
1 2
1 8
2 3
up 6
when 1
*/