#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=(1<<20)+5;

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
struct edge
{
	bool vis;
	int to,nxt,u,v;
}e[M];
int head[M],cnte,siz[M];
void add_edge(int u,int v,int x,int y)
{
	e[++cnte].to=v;
	e[cnte].u=x;
	e[cnte].v=y;
	e[cnte].nxt=head[u];
	head[u]=cnte;
	siz[v]++;
}
int a[N],b[N],n;
vector<int>ans;
void dfs(int now)
{
	for (int i=head[now];i;head[now]=i=e[i].nxt)
	if (!e[i].vis)
	{
		int to=e[i].to;
		e[i].vis=e[i^1].vis=1;
		dfs(to);
		ans.push_back(e[i].v);
		ans.push_back(e[i].u);
		i=head[now];
	}
}
bool check(int k)
{
	ans.clear();
	memset(head,0,sizeof(head));
	memset(siz,0,sizeof(siz));
	memset(e,0,sizeof(e));
	cnte=1;
	k=(1<<k)-1;
	for (int i=1;i<=n;i++)
	{
//		if ((a[i]^b[i])&k) return 0;
		int u=a[i]&k,v=b[i]&k;
		add_edge(u,v,i*2-1,i*2);
		add_edge(v,u,i*2,i*2-1);
	}
	for (int i=0;i<=k;i++) if (siz[i]&1) return 0;
	for (int i=0;i<=k;i++) if (siz[i]){dfs(i);break;}
	return (int)ans.size()==n*2;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	int l=0,r=20;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
				   else r=mid-1;
	}
	check(r);
	print(r);
	for (int i:ans) print(i,' ');
	
	return 0;
}