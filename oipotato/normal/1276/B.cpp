#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<cassert>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=200010,M=1000010;//
int n,m,i,x,y,ans;
int g1[N],g2[N],gd[N],v[3*M+N],nxt[M*3+N],ed;
int cnt,dfn[N],id[N],fa[N],f[N],mn[N],sd[N],idom[N];
void add(int*g,int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
int F(int x){
	if(f[x]==x)return x;
	int y=F(f[x]);
	if(sd[mn[x]]>sd[mn[f[x]]])mn[x]=mn[f[x]];
	return f[x]=y;
}
void dfs(int x){
	id[dfn[x]=++cnt]=x;
	for(int i=g1[x];i;i=nxt[i])if(!dfn[v[i]])dfs(v[i]),fa[dfn[v[i]]]=dfn[x];
}
void tarjan(int S){
	int i,j,k,x;
	for(cnt=0,i=1;i<=n;i++)gd[i]=dfn[i]=id[i]=fa[i]=idom[i]=0,f[i]=sd[i]=mn[i]=i;
	dfs(S);
	for(i=n;i>1;i--){
		for(j=g2[id[i]];j;j=nxt[j])F(k=dfn[v[j]]),sd[i]=sd[i]<sd[mn[k]]?sd[i]:sd[mn[k]];
		add(gd,sd[i],i);
		for(j=gd[f[i]=x=fa[i]];j;j=nxt[j])F(k=v[j]),idom[k]=sd[mn[k]]<x?mn[k]:x;
		gd[x]=0;
	}
	for(i=2;i<=n;add(gd,idom[i],i),i++)if(idom[i]!=sd[i])idom[i]=idom[idom[i]];
}
int q[N];
int work(int x,int y)
{
	tarjan(x);
	int t;q[t=1]=dfn[y];
	rep(i,t)for(int p=gd[q[i]];p;p=nxt[p])q[++t]=v[p];
	return t-1;
}
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int a,b;
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for(ed=0,i=1;i<=n;i++)g1[i]=g2[i]=0;
		while(m--)scanf("%d%d",&x,&y),add(g1,x,y),add(g1,y,x),add(g2,y,x),add(g2,x,y);
		printf("%lld\n",1ll*work(a,b)*work(b,a));
	}
}