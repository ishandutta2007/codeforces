#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
#define P(x,y) make_pair(x,y)
#define N 800000

int n,m,x,ans,vis[N],tot,head[N],fa[N],sz[N][2],f[N][2];
vector<int> q[N];
struct edge{int v,c,nxt;}e[N];
char s[N];

int gfa(int x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}

void add(int x,int y,int z){
	e[++tot].v=y; e[tot].c=z; e[tot].nxt=head[x]; head[x]=tot;
}

void dfs(int u){
	for (int i=head[u],v;i;i=e[i].nxt)
		if (vis[v=e[i].v]==-1){
			vis[v]=vis[u]^e[i].c;
			dfs(v);
		}
}

void ers(int x){
	if (f[x][0]){ans-=sz[x][0]; return;}
	if (f[x][1]){ans-=sz[x][1]; return;}
	ans-=min(sz[x][0],sz[x][1]);
}

void ins(int x){
	if (f[x][0]){ans+=sz[x][0]; return;}
	if (f[x][1]){ans+=sz[x][1]; return;}
	ans+=min(sz[x][0],sz[x][1]);
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=m;++i){
		int p; scanf("%d",&p);
		for (int j=1;j<=p;++j){
			int x; scanf("%d",&x);
			q[x].push_back(i);
		}
	}
	for (int i=1;i<=n;++i){
		if (q[i].size()==2){
			add(q[i][0],q[i][1],(s[i]-'0')^1);
			add(q[i][1],q[i][0],(s[i]-'0')^1);
		}
	}
	memset(vis,-1,sizeof vis);
	for (int i=1;i<=m;++i)
		if (vis[i]==-1){vis[i]=0; dfs(i);}
	for (int i=1;i<=m;++i){
		fa[i]=i; ++sz[i][vis[i]];
	}
	ans=0;
	for (int i=1;i<=n;++i){
		int t=q[i].size();
		if (t==1){
			int x=q[i][0];
			int j=gfa(x);
			ers(j);
			if (s[i]=='0') f[j][vis[x]]=1;
			else f[j][!vis[x]]=1;
			ins(j);
		}
		if (t==2){
			int x=q[i][0],y=q[i][1];
			int fx=gfa(x),fy=gfa(y);
			if (fx!=fy){
				ers(fx); ers(fy);
				fa[fy]=fx;
				sz[fx][0]+=sz[fy][0];
				sz[fx][1]+=sz[fy][1];
				f[fx][0]|=f[fy][0];
				f[fx][1]|=f[fy][1];
				ins(fx);
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}