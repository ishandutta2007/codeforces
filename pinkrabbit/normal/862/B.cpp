#include<cstdio>
int n,h[100001],nxt[200001],to[200001],tot=0,vis[100001],sums[2];
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
void dfs(int u,int t){
	vis[u]=1;
	++sums[t];
	for(int i=h[u];i;i=nxt[i]){
		if(!vis[to[i]]){
			dfs(to[i],t^1);
		}
	}
}
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<n;++i) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	dfs(1,0);
	printf("%I64d",1ll*sums[0]*sums[1]-n+1);
	return 0;
}