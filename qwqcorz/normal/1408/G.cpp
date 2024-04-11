#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1505;
const int p=998244353;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct dsu
{
	int fa[N],siz[N],tot[N];
	void send(int n){for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1,tot[i]=0;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	int merge(int x,int y)
	{
		x=find(x),y=find(y),tot[x]++;
		if (x==y) return x;
		fa[x]=y,siz[y]+=siz[x],tot[y]+=tot[x];
		return y;
	}
}d;
int u[N*N],v[N*N],e[N][N],id[N],vis[N*2],n,cnt;
vector<int>t[N*2],f[N*2];
void dfs(int now)
{
	f[now]={1};
	for (int to:t[now])
	{
		dfs(to);
		vector<int>g(min((int)f[now].size()+(int)f[to].size()-1,n+1));
		for (int i=0;i<(int)f[now].size();i++)
		for (int j=0;j<(int)f[to].size()&&i+j<=n;j++)
		g[i+j]=(g[i+j]+1LL*f[now][i]*f[to][j])%p;
		f[now].swap(g);
	}
	if (f[now].size()==1) f[now]={0,1};
	else f[now][1]=(f[now][1]+1)%p;
}

signed main()
{
	n=read(),d.send(cnt=n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) e[i][j]=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<i;j++) u[e[i][j]]=i,v[e[i][j]]=j;
	for (int i=1;i<=n;i++) id[i]=i;
	for (int i=1;i<=n*(n-1)/2;i++)
	{
		int x=d.merge(u[i],v[i]);
		if (d.siz[x]*(d.siz[x]-1)/2==d.tot[x])
		{
			cnt++;
			for (int j=1;j<=n;j++) if (d.find(j)==x)
			{
				if (vis[id[j]]<i) t[cnt].push_back(id[j]);
				vis[id[j]]=i,id[j]=cnt;
			}
		}
	}
	dfs(cnt);
	for (int i=1;i<=n;i++) print(f[cnt][i]," \n"[i==n]);
	
	return 0;
}