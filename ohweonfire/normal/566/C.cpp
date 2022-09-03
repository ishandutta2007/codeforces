#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=200111;

int head[maxn],nxt[maxn<<1],to[maxn<<1],l[maxn<<1],etot=1;
void addedge(int u,int v,int w){nxt[++etot]=head[u];head[u]=etot;to[etot]=v;l[etot]=w;}

int n,w[maxn];
bool use[maxn];

int seq[maxn],tot,sz[maxn];

void dfs1(int x,int f=0)
{
	seq[++tot]=x;sz[x]=1;
	for(int i=head[x];i;i=nxt[i])if(!use[to[i]]&&to[i]!=f)
	{
		dfs1(to[i],x);
		sz[x]+=sz[to[i]];
	}
}
int getrt(int u)
{
	tot=0;dfs1(u);
	int mx=0;
	for(int i=1;i<=tot;i++)if(sz[seq[i]]*2>=tot&&(mx==0||sz[mx]>sz[seq[i]]))mx=seq[i];
	return mx;
}

double go[maxn],ans[maxn];
void dfs(int x,int f,LL d)
{
	go[x]=sqrt(d)*w[x];
	ans[x]=go[x]*d;
	for(int i=head[x];i;i=nxt[i])if(to[i]!=f)
	{
		dfs(to[i],x,d+l[i]);
		go[x]+=go[to[i]];
		ans[x]+=ans[to[i]];
	}
}

int getnxt(int x)
{
	dfs(x,0,0);
	for(int i=head[x];i;i=nxt[i])if(go[x]<go[to[i]]*2)return to[i];
	return 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",w+i);
	for(int i=1,u,v,w;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	int cur=1,nxt=0;
	while(cur&&!use[cur])
	{
		cur=getrt(cur);
		nxt=getnxt(cur);
		
		use[cur]=1;
		swap(cur,nxt);
	}
	double v1=1e100,v2=1e100;
	if(cur)
	{
		dfs(cur,0,0);
		v1=ans[cur];
	}
	if(nxt)
	{
		dfs(nxt,0,0);
		v2=ans[nxt];
	}
	if(v1<v2)printf("%d %.10lf\n",cur,v1);
	else printf("%d %.10lf\n",nxt,v2);
	return 0;
}