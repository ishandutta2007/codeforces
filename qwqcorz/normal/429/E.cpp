#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=N*2;

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
int l[N],r[N],b[N],c[N],ans[N],d[N];
int u[M],v[M];
struct edge
{
	bool del;
	int to,nxt,id;
}e[M*2];
int head[N],cnte=1,cur[N];
void add_edge(int u,int v,int w)
{
	e[++cnte].id=w;
	e[cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
void add(int u,int v,int w)
{
	d[u]++,d[v]++;
	add_edge(u,v,w);
	add_edge(v,u,w);
}
vector<int>a;
void dfs(int now)
{
	for (int i=cur[now];i;i=cur[now])
	{
		cur[now]=e[i].nxt;
		if (e[i].del) continue;
		e[i].del=e[i^1].del=1;
		int to=e[i].to;
		u[e[i].id]=now;
		v[e[i].id]=to;
		dfs(to);
		a.push_back(e[i].id);
	}
}

signed main()
{
	int n=read(),cnt=0;
	for (int i=1;i<=n;i++)
	{
		b[++cnt]=l[i]=read();
		b[++cnt]=r[i]=read()+1;
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++)
		c[l[i]=lower_bound(b+1,b+1+cnt,l[i])-b]++,
		c[r[i]=lower_bound(b+1,b+1+cnt,r[i])-b]--;
	for (int i=1;i<=n;i++) add(l[i],r[i],i);
	for (int i=1;i<=cnt;i++) if ((c[i]+=c[i-1])&1) add(i,i+1,0);
	memcpy(cur,head,sizeof(cur));
	for (int i=1;i<=cnt;i++) dfs(i);
	for (int i=0;i<(int)a.size();i++) ans[a[i]]=u[a[i]]<v[a[i]];
	for (int i=1;i<=n;i++) print(ans[i]," \n"[i==n]);
	
	return 0;
}