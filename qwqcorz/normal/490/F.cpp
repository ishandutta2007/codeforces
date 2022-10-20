#include<bits/stdc++.h>
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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt;
}e[N*2];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
struct node
{
	int ls,rs,Max[2];
}t[(int)1e7];
int tot=0;
//vector<node>t;
int addnull()
{
	//t.push_back((node){0,0,0,0});
	//return t.size()-1;
	return ++tot;
}

int ans=1;
int m,a[N],b[N],root[N];
void add(int &w,int l,int r,int x,int y1,int y2)
{
//	print(w);
	if (!w) w=addnull();//print((int)(&w));print((int)(&t[1].rs));
	t[w].Max[0]=max(t[w].Max[0],y1);
	t[w].Max[1]=max(t[w].Max[1],y2);
//	print(l,' ');print(r,':');print(t[w].Max);
//	print(w,':');
//	print(l,' ');
//	print(r);
	if (l==r) return;
	if (x<=mid) add(t[w].ls,l,mid,x,y1,y2);
		   else add(t[w].rs,mid+1,r,x,y1,y2);
//	print(t[w].ls,',');
//	print(t[w].rs);
}
int query(int w,int l,int r,int L,int R,int x)
{
//	print(w,':');
//	print(l,' ');
//	print(r,':');
//	print(L,' ');
//	print(R,' ');
//	print(x,':');
//	print(t[w].Max[x]);
	if (!w||R<L) return 0;
	if (R<l||r<L) return 0;
	if (L<=l&&r<=R) return t[w].Max[x];
	return max(query(t[w].ls,l,mid,L,R,x),query(t[w].rs,mid+1,r,L,R,x));
}
void merge(int &x,int y)
{
	if (!y) return;
	if (!x) return void(x=y);
	t[x].Max[0]=max(t[x].Max[0],t[y].Max[0]);
	t[x].Max[1]=max(t[x].Max[1],t[y].Max[1]);
	ans=
	max(ans,max(
	t[t[x].ls].Max[0]+t[t[y].rs].Max[1],
	t[t[y].ls].Max[0]+t[t[x].rs].Max[1]
	));
	merge(t[x].ls,t[y].ls);
	merge(t[x].rs,t[y].rs);
}
void dfs(int now,int fa)
{
	int Max1=0,Max2=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==fa) continue;
		dfs(to,now);
		int v1=query(root[to],1,m,1,a[now]-1,0);//print(t[1].rs);
		int v2=query(root[to],1,m,a[now]+1,m,1);
		ans=max(ans,Max2+v1+1);
		ans=max(ans,Max1+v2+1);
		Max1=max(Max1,v1);
		Max2=max(Max2,v2);//print(v1,' ');print(v2);
		merge(root[now],root[to]);
	}
//	print(now,':');print(Max1,' ');print(Max2);
	add(root[now],1,m,a[now],Max1+1,Max2+1);
//	print(query(root[now],1,m,a[now],a[now],1));
//	print(t[2].Max[0]);
}

signed main()
{
	memset(t,0,sizeof(t));
	memset(root,0,sizeof(root));
//	t.push_back((node){0,0,0,0});
	int n=read();
	for (int i=1;i<=n;i++) b[i]=a[i]=read();
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+m,a[i])-b;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	ans=max(ans,max(t[root[1]].Max[0],t[root[1]].Max[1]));
	print(ans);

	return 0;
}