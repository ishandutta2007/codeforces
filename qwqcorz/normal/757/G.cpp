#include<bits/stdc++.h>
#define int long long
#define ll long long
#define piir pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
const int LOG=20;
const int inf=1e18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool del[N];
int p[N],np[N];
int siz[N],mx[N],rt,fa[N];
struct edge{int to,val;};
vector<edge>e[N];
void findroot(int now,int father,int tot)
{
	siz[now]=1,mx[now]=0;
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||del[to]) continue;
		findroot(to,now,tot);
		siz[now]+=siz[to];
		mx[now]=max(mx[now],siz[to]);
	}
	mx[now]=max(mx[now],tot-siz[now]);
	if (mx[now]<=tot/2) rt=now;
}
int dis[N][LOG],deep[N];
void dfs0(int now,int father,int dist,int k)
{
	dis[now][k]=dist;
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||del[to]) continue;
		dfs0(to,now,dist+i.val,k);
	}
}
vector<piir>sum1[N],sum2[N];
void dfs(int now,int father,int dist,vector<piir>&a)
{
	a.push_back(mk(np[now],dist));
	for (edge i:e[now])
	{
		int to=i.to;
		if (to==father||del[to]) continue;
		dfs(to,now,dist+i.val,a);
	}
}
void build(int now,int father,int tot,int val)
{
	rt=0;
	findroot(now,father,tot);
	fa[rt]=father;
	deep[rt]=deep[father]+1;
	dfs0(rt,0,0,deep[rt]);
	if ("myhmd")
	{
		dfs(rt,0,0,sum1[rt]);
		sort(sum1[rt].begin(),sum1[rt].end());
		int lst=0;
		for (auto &i:sum1[rt]) i.se+=lst,lst=i.se;
	}
	if (father)
	{
		dfs(now,0,val,sum2[rt]);
		sort(sum2[rt].begin(),sum2[rt].end());
		int lst=0;
		for (auto &i:sum2[rt]) i.se+=lst,lst=i.se;
	}
	int x=rt;
	findroot(x,0,tot);
	del[x]=1;
	for (edge i:e[x])
	{
		int to=i.to;
		if (to==father||del[to]) continue;
		build(to,x,siz[to],i.val);
	}
}
int calc(vector<piir>&a,int l,int r,int dist)
{
	if (a.empty()) return 0;
	int L=lower_bound(a.begin(),a.end(),mk(l,0LL))-a.begin();
	int R=lower_bound(a.begin(),a.end(),mk(r,inf))-a.begin()-1;
	if (L>R) return 0;
	return a[R].se-(L?a[L-1].se:0)+dist*(R-L+1);
}
int query(int l,int r,int x)
{
	int ret=0;
	for (int y=x;y;y=fa[y]) /*print(dis[x][deep[y]],':'),print(*/ret+=calc(sum1[y],l,r,dis[x][deep[y]])-calc(sum2[y],l,r,dis[x][deep[y]-1]);
	return ret;
}
void add(vector<piir>&a,int x,int y)
{
	if (a.empty()) return;
	int pos=lower_bound(a.begin(),a.end(),mk(x,inf))-a.begin()-1;
	a[pos].fi+=y;
	if (pos&&a[pos-1].fi>a[pos].fi)
	{
		swap(a[pos-1].fi,a[pos].fi);
		int tmp=pos-1?a[pos-2].se:0;
		a[pos-1].se=tmp+a[pos].se-a[pos-1].se;
	}
}

signed main()
{
	int n=read(),Q=read();
	for (int i=1;i<=n;i++) np[p[i]=read()]=i;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	build(1,0,n,0);
	/*
	for (int i=1;i<=n;i++)
	{
		print(i,':'),puts("");
		for (auto i:sum1[i]) print(i.se,' ');;puts("");
		for (auto i:sum2[i]) print(i.se,' ');;puts("");
	}
	for (int i=1;i<=n;i++) print(i,' '),print(fa[i],' '),print(deep[i]);
	*/
	for (int i=1,last=0;i<=Q;i++)
	{
		int opt=read();
		if (opt==1)
		{
			int l=read()^last,r=read()^last,x=read()^last;
//			print(l,' '),print(r,' '),print(x);
			print(last=query(l,r,x));
		}
		else
		{
			int x=read()^last;
//			print(x);
			for (int y=p[x];y;y=fa[y]) add(sum1[y],x,1),add(sum2[y],x,1);
			for (int y=p[x+1];y;y=fa[y]) add(sum1[y],x+1,-1),add(sum2[y],x+1,-1);
			swap(p[x],p[x+1]);
		}
		last&=(1<<30)-1;
	}
	
	return 0;
}