#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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

const int Mod=1e9+7;
const int M=1e5+10;
const int V=1e7;
int n,prime[V+10],de[M],sum[V+10],fa[25][M],inv[V+10],cnt,a[M],ans[M];
bool f[V+10];
vector<int>e[M];
struct node{int a,pos,w;};
vector<node>b[M];

int poww(int a,int b=Mod-2)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void init()
{
	for (int i=1;i<=20;i++)
		for (int j=1;j<=n;j++)
			fa[i][j]=fa[i-1][fa[i-1][j]];
}
 
int LCA(int u,int v)
{
	if (de[u]<de[v])swap(u,v);
	for (int i=20;i>=0;i--)
		if (de[fa[i][u]]>=de[v])u=fa[i][u];
	if (u==v)return u;
	for (int i=20;i>=0;i--)
		if (fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}

void dfs1(int u,int f)
{
	fa[0][u]=f,de[u]=de[f]+1;
	for (auto v:e[u])
		if (v!=f)dfs1(v,u);
}

void dfs2(int u)
{
	vector<pii>V;
	for (int i=1;i<=cnt&&prime[i]*prime[i]<=a[u];i++)
		if (a[u]%prime[i]==0)
		{
			int w=0;
			while(a[u]%prime[i]==0)w++,a[u]/=prime[i];
			int qwq=1;
			for (int j=1;j<=w;j++)
				qwq*=prime[i],sum[qwq]=sum[qwq]*prime[i]%Mod;
			V.pb(mp(prime[i],w));
		}
	if (a[u]!=1)sum[a[u]]=sum[a[u]]*a[u]%Mod,V.pb(mp(a[u],1));
	for (auto qwq:b[u])
	{
		int val=1,tmp=qwq.a;
		for (int i=1;i<=cnt&&prime[i]*prime[i]<=tmp;i++)
			if (tmp%prime[i]==0)
			{
				int w=0;
				while(tmp%prime[i]==0)w++,tmp/=prime[i];
				int qwq=1;
				for (int j=1;j<=w;j++)
					qwq*=prime[i],val=val*sum[qwq]%Mod;
			}
		if (tmp!=1)val=val*sum[tmp]%Mod;
		if (qwq.w==1)ans[qwq.pos]=ans[qwq.pos]*val%Mod;
		else ans[qwq.pos]=ans[qwq.pos]*poww(val)%Mod;
	}
	for (auto v:e[u])
	{
		if (v==fa[0][u])continue;
		dfs2(v);
	}
	for (auto x:V)
	{
		int qwq=1;
		for (int i=1;i<=x.y;i++)
			qwq*=x.x,sum[qwq]=sum[qwq]*inv[x.x]%Mod;
	}
}

signed main()
{
	for (int i=1;i<=V;i++)sum[i]=1;
	for (int i=2;i<=V;i++)
	{
		if (f[i])continue;prime[++cnt]=i;
		inv[i]=poww(i);
		for (int j=i*2;j<=V;j+=i)f[j]=1;
	}
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	for (int i=1;i<=n;i++)a[i]=read();
	int q=read();dfs1(1,0);init();
	for (int i=1;i<=q;i++)
	{
		int u=read(),v=read(),w=read();ans[i]=1;
		b[u].pb((node){w,i,1}),b[v].pb((node){w,i,1});
		int lca=LCA(u,v);b[lca].pb((node){w,i,-1});
		if (lca!=1)b[fa[0][lca]].pb((node){w,i,-1});
	}
	dfs2(1);
	for (int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}
/*
4
1 2
1 3
1 4
6 4 9 5
1
2 3 6
*/