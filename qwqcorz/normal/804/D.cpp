#include<bits/stdc++.h>
#define ll long long
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
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
map<int,double>answer[N];
vector<ll>sum[N];
vector<int>a[N],tot[N],tmp;
int dis[N],rt,mx,fa[N];
void dfs(int now,int father,int len)
{
	if (dis[now]<0) tmp.push_back(now);
	if (len>mx) rt=now,mx=len;
	dis[now]=max(dis[now],len);
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now,len+1);
	}
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read(),Q=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(dis,-1,sizeof(dis));
	int cnt=0;
	for (int i=1;i<=n;i++)
	if (dis[i]<0)
	{
		cnt++;
		rt=mx=-1;
		dfs(i,0,0);
		dfs(rt,0,0);
		dfs(rt,0,0);
		for (int j:tmp) a[cnt].push_back(dis[j]),fa[j]=cnt;
		tmp.clear();
	}
	for (int i=1;i<=cnt;i++)
	{
		sort(a[i].begin(),a[i].end());
		tot[i].resize(a[i].size());
		sum[i].resize(a[i].size());
		for (int j:a[i]) tot[i][j]++,sum[i][j]+=j;
		for (int j=(int)a[i].size()-2;j>=0;j--) tot[i][j]+=tot[i][j+1],sum[i][j]+=sum[i][j+1];
	}
	for (int i=1;i<=Q;i++)
	{
		int x=fa[read()],y=fa[read()];
		if (x==y){puts("-1");continue;}
		if (x>y) swap(x,y);
		if (a[x].size()>a[y].size()) swap(x,y);
		if (answer[x].count(y)){printf("%.9lf\n",answer[x][y]);continue;}
		int len=max(a[x].back(),a[y].back());
		ll ans=0;
		for (int dis:a[x])
		{
			int tmp=min(max(len-dis-1,0),(int)a[y].size());
			if (tmp<(int)a[y].size())
				ans+=sum[y][tmp]+1LL*(dis+1)*tot[y][tmp],
				ans+=1LL*(a[y].size()-tot[y][tmp])*len;
			else
				ans+=1LL*a[y].size()*len;
		}
		printf("%.9lf\n",answer[x][y]=1.0*ans/a[x].size()/a[y].size());
	}
	
	return 0;
}