#include <stdio.h>
#define MN 300000

int n;
char s[MN+5];

struct bcj{
	int fa[MN+5];
	int sz[MN+5];
	void init(int n){
		for(int i=0;i<=n;i++){
			fa[i] = i;
			sz[i] = 1;
		}
	}
	int gf(int u){
		return fa[u]==u?u:fa[u]=gf(fa[u]);
	}
	void unite(int u,int v){
		u = gf(u);
		v = gf(v);
		if(u==v) return;
		fa[v] = u;
		sz[u] += sz[v];
	}
	int size(int u){
		return sz[gf(u)];
	}
}B[2];

void solve(){
	scanf("%d%s",&n,&s[1]);
	B[0].init(n),B[1].init(n);
	for(int i=1;i<=n;i++){
		if(s[i]=='L'){
			B[i&1].unite(i-1,i);
		}else{
			B[(i&1)^1].unite(i-1,i);
		}
	}
	for(int i=0;i<=n;i++){
		printf("%d ",B[i&1].size(i));
	}puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}