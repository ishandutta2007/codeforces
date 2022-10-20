#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int cnt=0,cnte=0,n,m,deg[N];
int u[N*2],v[N*2];
bool vis[N*2];
struct edge
{
	int to,nxt,id;
}e[N*4];
int head[N],cur[N],fa[N];
void add_edge(int u,int v,int id)
{
	e[++cnte].to=v;
	e[cnte].id=id;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void add(int u,int v)
{
	fa[find(u)]=find(v);
	::u[++cnt]=u,::v[cnt]=v;
	add_edge(u,v,cnt);
	add_edge(v,u,cnt);
	deg[u]++,deg[v]++;
}
vector<int>ans;
void dfs(int now)
{
	for (int i=cur[now];i;i=cur[now])
	{
		cur[now]=e[i].nxt;
		int to=e[i].to,id=e[i].id;
		if (vis[id]) continue;
		vis[id]=1;
		dfs(to);
		ans.push_back(id);
	}
}
int tmp;
bool check(int x)
{
	static bool is[N];
	memset(is,0,sizeof(is));
	vector<int>answer;
	for (int i=0;i<cnt;i++) if (i%2==x)
	{
		if (ans[i]<=tmp) answer.push_back(ans[i]);
					else is[u[ans[i]]]=1;
	}
	for (int i=0;i<cnt;i++)
	if (ans[i]<=tmp&&i%2!=x&&(is[u[ans[i]]]||is[v[ans[i]]]))
	{
		is[u[ans[i]]]=0;
		is[v[ans[i]]]=0;
		answer.push_back(ans[i]);
	}
	if ((int)answer.size()<=(n+m+1)/2)
	{
		print(answer.size());
		for (int i:answer)
		{
			print(u[i],' ');
			print(v[i]);
		}
		return 1;
	}
	return 0;
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	tmp=cnt;
	for (int i=1;i<=n;i++) if (deg[i]&1) add(i,0);
	for (int i=0;i<=n;i++) if (find(i)!=find(0)&&deg[i]) add(i,0),add(i,0);
	memcpy(cur,head,sizeof(cur));
	dfs(0);
	if (check(0)) return 0;
	if (check(1)) return 0;
	puts("Fail");
	
	return 0;
}