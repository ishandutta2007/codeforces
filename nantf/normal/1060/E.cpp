#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020;
int n,to[maxn<<1],nxt[maxn<<1],head[maxn],el,sz[maxn],odd;
bool dep[maxn];
ll ans;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	odd+=dep[u]=dep[f]^(sz[u]=1);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	ans+=1ll*sz[u]*(n-sz[u]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs(1,0);
	ans=(ans+1ll*odd*(n-odd))>>1;
	printf("%lld\n",ans);
}