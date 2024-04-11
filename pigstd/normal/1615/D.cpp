#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,m,u[M],v[M],w[M],ww[M],a[M],b[M],c[M],f[M],dis[M],F;
vector<pair<int,int>>e[M],e2[M];
struct node{int a,b,c;};
vector<node>V;

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void work(int a,int b,int c)
{
//	cout<<a<<' '<<b<<' '<<c<<'\n';
	V.pb((node){a,b,c});
	if (find(a)==find(b))return;
	f[find(a)]=find(b);
	e2[b].pb(mp(a,c)),e2[a].pb(mp(b,c));
}

void dfs(int u,int fa)
{
	for (auto v:e[u])
	{
		if (v.x==fa)continue;
		if (ww[v.y]!=-1)
			work(u,v.x,ww[v.y]);
		dfs(v.x,u);
	}
}

void dfs2(int u,int fa)
{
	for (auto to:e2[u])if (to.x!=fa)dis[to.x]=dis[u]^to.y,dfs2(to.x,u);
}

void solve()
{
	n=read(),m=read();V.clear();
	for (int i=1;i<=n;i++)f[i]=i,e[i].clear(),e2[i].clear(),dis[i]=0;
	for (int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		if (w[i]!=-1)
		{
			int cnt=0;
			for (int j=0;j<=30;j++)
				if ((w[i]>>j)&1)cnt++;
			ww[i]=cnt&1;
		}
		else ww[i]=-1;
		e[u[i]].pb(mp(v[i],i)),e[v[i]].pb(mp(u[i],i));
	}//puts("qwq");
	dfs(1,0);//puts("qwq");
	for (int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		work(a,b,c);
	}int F=1;
	for (int i=1;i<=n;i++)if (find(i)==i)dfs2(i,0);
	for (auto x:V)
		if (dis[x.a]^dis[x.b]^x.c){F=0;break;}
	if (!F){NO return;}YES
	for (int i=1;i<n;i++)
	{
		if (w[i]==-1)w[i]=dis[u[i]]^dis[v[i]];
		cout<<u[i]<<' '<<v[i]<<' '<<w[i]<<'\n';
	}
}

signed main()
{
	WT solve();
	return 0;
}
/*

*/