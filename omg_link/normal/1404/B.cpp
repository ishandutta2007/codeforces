#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define MN 100000

int n,a,b,da,db,l;

int hd[MN+5],to[MN*2+5],nxt[MN*2+5],rn;

void init(int n){
	rn=0;
	for(int i=1;i<=n;i++)
		hd[i] = -1;
}

void add(int u,int v){
	to[rn]=v,nxt[rn]=hd[u];
	hd[u]=rn++;
}

int dfs(int u,int f){
	std::vector<int> v;
	v.push_back(0);
	v.push_back(0);
	for(int i=hd[u];~i;i=nxt[i]){
		if(to[i]==f) continue;
		v.push_back(dfs(to[i],u));
	}
	std::sort(v.begin(),v.end(),std::greater<int>());
	l = std::max(l,v[0]+v[1]);
	return v[0]+1;
}

int dfs2(int u,int target,int f){
	if(u==target) return 0;
	int ans = 0x3fffffff;
	for(int i=hd[u];~i;i=nxt[i]){
		if(to[i]==f) continue;
		ans = std::min(ans,dfs2(to[i],target,u));
	}
	return ans+1;
}

int dist(int u,int v){
	return dfs2(u,v,0);
}

void solve(){
	scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
	init(n);
	for(int i=2,u,v;i<=n;i++){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	l = 0;
	dfs(1,0);
	if(da>=dist(a,b)){
		puts("Alice");
		return;
	}
	if(db>2*da&&l>2*da){
		puts("Bob");
	}else{
		puts("Alice");
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}