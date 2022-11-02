#include<bits/stdc++.h>
#define LL long long
#define maxn 1000010
#define mo 1000000007
#define inf 10000000000000000LL
#define eps 1e-6
using namespace std;
struct edge{
	int point,next,f;
}e[600010];
vector<int> b[200010];
set<pair<LL,int>> s;
int n,m,sa,tot,g[200010],f[200010],que[200010],deg[200010],fa[200010][20],ans,sum[200010],dep[200010];
LL dis[200010];
void build(int x,int y,int z){
	e[++tot].point=y; e[tot].f=z; e[tot].next=g[x]; g[x]=tot;
}
void dijkstra(int x){
	for (int i=1;i<=n;i++) dis[i]=inf;
	dis[x]=0;
	s.insert(make_pair(dis[x],x));
	while (!s.empty()){
		set<pair<LL,int>>::iterator it=s.begin();
		for (int i=g[it->second];i;i=e[i].next)
		if (dis[e[i].point]>dis[it->second]+e[i].f){
			s.erase(make_pair(dis[e[i].point],e[i].point));
			dis[e[i].point]=dis[it->second]+e[i].f;
			s.insert(make_pair(dis[e[i].point],e[i].point));
		}
		s.erase(it);
	}
}
int getlca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--)
	if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--)
	if (fa[x][i]!=fa[y][i]){
		x=fa[x][i];
		y=fa[y][i];
	}
	return fa[x][0];
}
void dfs(int x){
	sum[x]=1;
	for (int i=0;i<b[x].size();i++){
		dfs(b[x][i]);
		sum[x]+=sum[b[x][i]];
	}
}
int main(){
    scanf("%d%d%d",&n,&m,&sa);
    for (int i=0;i<m;i++){
    	int o,p,t;
		scanf("%d%d%d",&o,&p,&t);
    	build(o,p,t);
    	build(p,o,t);
    }
    dijkstra(sa);
    for (int i=1;i<=n;i++){
    	for (int j=g[i];j;j=e[j].next)
    	if (dis[e[j].point]==dis[i]+e[j].f) deg[e[j].point]++;
    }
    que[0]=sa;
    int tail=0;
    for (int i=0;i<=tail;i++){
		for (int j=g[que[i]];j;j=e[j].next)
		if (dis[e[j].point]==dis[que[i]]+e[j].f){
			deg[e[j].point]--;
			if (deg[e[j].point]==0) que[++tail]=e[j].point;
		}
    }
    dep[sa]=1;
    for (int i=1;i<=tail;i++){
		int lca=0;
    	for (int j=g[que[i]];j;j=e[j].next)
    	if (dis[e[j].point]+e[j].f==dis[que[i]]){
    		if (lca==0) lca=e[j].point;
			else lca=getlca(lca,e[j].point);
    	}
    	fa[que[i]][0]=lca;
    	dep[que[i]]=dep[lca]+1;
    	b[lca].push_back(que[i]);
    	for (int j=1;j<20;j++) fa[que[i]][j]=fa[fa[que[i]][j-1]][j-1];
    }
    dfs(sa);
    for (int i=1;i<=n;i++)
	if (i!=sa) ans=max(ans,sum[i]);
	printf("%d\n",ans);
}