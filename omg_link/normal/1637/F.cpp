#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#define MN 200000

using std::max;
using std::min;
using std::multiset;
using std::vector;

using ll = long long;

const ll INF = 1e18;

int n,h[MN+5],mx[MN+5];
ll ans[MN+5];
vector<int> e[MN+5];
ll gans = INF;

void updateAns(int u,int mx,ll ans){
	if(h[u]>mx){
		ans += h[u]-mx;
	}
	ans += ::mx[1]; //aka += global max
	gans = min(gans,ans);
}

void dfs1(int u,int f){
	for(int v:e[u]){
		if(v==f) continue;
		dfs1(v,u);
		mx[u] = max(mx[u],mx[v]);
		ans[u] += ans[v];
	}
	if(h[u]>mx[u]){
		ans[u] += h[u]-mx[u];
		mx[u] = h[u];
	}
}

void dfs2(int u,int f,ll fans,int fmax){
	ll cans = 0;
	multiset<int> s;
	for(int v:e[u]){
		if(v==f) continue;
		cans += ans[v];
		s.insert(mx[v]);
	}
	cans += fans;
	s.insert(fmax);
	updateAns(u,*s.rbegin(),cans);
	for(int v:e[u]){
		if(v==f) continue;
		s.erase(s.find(mx[v]));
		cans -= ans[v];
		if(h[u]>*s.rbegin()){
			dfs2(v,u,cans+h[u]-*s.rbegin(),h[u]);
		}else{
			dfs2(v,u,cans,*s.rbegin());
		}
		s.insert(mx[v]);
		cans += ans[v];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	for(int i=2;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,0,0,0);
	printf("%lld\n",gans);
}