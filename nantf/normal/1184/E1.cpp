#include<bits/stdc++.h>
using namespace std;
int n,m,head[100010],fa[100010],o=0,ans=0;
bool w=false;
struct edge{
	int u,v,w;
	bool operator <(const edge &b)const{
		return w<b.w;
	}
}e1[1000010];
struct edge1{
	int to,link,w;
}e2[200010];
void add_edge(int u,int v,int w){
	e2[++o].to=v,e2[o].link=head[u],head[u]=o,e2[o].w=w;
	e2[++o].to=u,e2[o].link=head[v],head[v]=o,e2[o].w=w;
}
int find(int a){
	return (fa[a]==a?a:fa[a]=find(fa[a]));
}
void dfs(int u,int fa,int tag){
	if(u==tag){
		w=true;
		return;
	}
	for(int i=head[u];i;i=e2[i].link){
		if(e2[i].to==fa) continue;
		dfs(e2[i].to,u,tag);
		if(w){
			ans=max(ans,e2[i].w);
			return;
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) scanf("%d %d %d",&e1[i].u,&e1[i].v,&e1[i].w);
	sort(e1+2,e1+m+1);
	for(int i=2;i<=m;i++){
		int fau=find(e1[i].u),fav=find(e1[i].v);
		if(fau==fav) continue;
		fa[fau]=fav;
		add_edge(e1[i].u,e1[i].v,e1[i].w);
	}
	dfs(e1[1].u,0,e1[1].v);
	if(!w) printf("%d\n",(int)1e9);
	else printf("%d\n",min((int)1e9,ans));
}