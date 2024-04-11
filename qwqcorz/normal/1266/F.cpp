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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
inline void up(int &x,int y){if (x<y) x=y;}
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
vector<int>h[N],d[N],son[N];
vector<pair<int,int>>sun[N];
int f[N],ans[N],all[N],fa[N];
void dfs0(int now,int father)
{
	fa[now]=father;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs0(to,now);
		up(f[now],f[to]);
		son[now].push_back(to);
		h[now].push_back(f[to]);
		d[now].push_back(f[to]);
	}
	f[now]++;
}
void dfs1(int now,int father,int len)
{
	if (len) h[now].push_back(len);
	int mx[3]={0,0,0};
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		mx[2]=f[to];
		sort(mx,mx+3,greater<int>());
	}
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs1(to,now,max(len,mx[0]==f[to]?mx[1]:mx[0])+1);
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs0(1,0);
	dfs1(1,0,0);
	all[n]=1;
	for (int i=1;i<=n;i++) sort(h[i].begin(),h[i].end(),greater<int>());
	for (int i=1;i<=n;i++) sort(d[i].begin(),d[i].end(),greater<int>());
	for (int i=1;i<=n;i++) sort(son[i].begin(),son[i].end(),[&](int x,int y){return f[x]>f[y];});
	for (int i=2;i<=n;i++)
	for (int j=0;j<(int)son[i].size();j++)
	sun[fa[i]].push_back(make_pair(d[i][j],j+1));
	for (int i=1;i<=n;i++) sort(sun[i].begin(),sun[i].end(),greater<pair<int,int>>());
	for (int i=1;i<=n;i++)
	{
		up(all[1],1+h[i].size());
		for (int j=0;j<(int)h[i].size();j++)
		{
			up(all[h[i][j]*2],j+1);
			if (j&&h[i][j]!=h[i][j-1]) up(ans[h[i][j]*2+1],j+1);
		}
	}
	for (int i=2;i<=n;i++)
	for (int j=0;j<(int)d[i].size();j++)
	{
		int k=upper_bound(h[fa[i]].begin(),h[fa[i]].end(),d[i][j],[&](int x,int y){
			return x>y;
		})-h[fa[i]].begin();
		up(ans[d[i][j]*2],j+1+k-1);
	}
	for (int i=1;i<=n;i++)
	for (int j=0,k=0,mx=0;j<(int)h[i].size();j++)
	{
		while (k<(int)sun[i].size()&&sun[i][k].first>=h[i][j]) up(mx,sun[i][k++].second);
//		if (d[i][j]==2) print(i,' '),print(son[i][j],' '),print(j,' '),print(mx);
		up(ans[h[i][j]*2],j+mx); 
	}
	for (int i=n;i>=1;i--) up(all[i],all[i+1]),up(ans[i],max(all[i],ans[i+2]));
	for (int i=1;i<=n;i++) print(ans[i]," \n"[i==n]);
	
	return 0;
}