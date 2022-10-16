#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v,nxt;
}e[200020];
int n,el,head[200020],cost[200020],ans;
int cnt,dfn[200020],low[200020];
int top,stk[200020];
bool ins[200020];
inline void add(int u,int v){
	e[++el]=(edge){v,head[u]};head[u]=el;
}
void dfs(int u){
	dfn[u]=low[u]=++cnt;
	stk[++top]=u;
	ins[u]=true;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int minn=2147483647,size=0;
		do{
			ins[stk[top]]=false;
			minn=min(minn,cost[stk[top]]);
			size++;
		}while(stk[top--]!=u);
		if(size!=1) ans+=minn;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",cost+i);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(i==x) ans+=cost[i];
		else add(i,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) dfs(i);
	printf("%d\n",ans);
}