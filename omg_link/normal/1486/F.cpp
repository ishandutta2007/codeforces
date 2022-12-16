#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#define MN 300000
typedef std::pair<int,int> pii;

int n;
std::vector<int> e[MN+5];

int dep[MN+5],fa[MN+5][20];

void add(int u,int v){
	e[u].push_back(v);
}

void init(int u,int f){
	for(int i=0;i<19;i++)
		if(fa[u][i])
			fa[u][i+1] = fa[fa[u][i]][i];
		else
			break;
	for(auto v:e[u]){
		if(v==f) continue;
		dep[v] = dep[u]+1;
		fa[v][0] = u;
		init(v,u);
	}
}

int jump(int u,int l){
	if(l<=0) return u;
	for(int i=0;l;i++){
		if(l&(1<<i)){	
			u = fa[u][i];
			l -= 1<<i;
		}
	}
	return u;
}

int lca(int u,int v){
	if(dep[u]<dep[v])
		std::swap(u,v);
	u = jump(u,dep[u]-dep[v]);
	if(u==v) return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i]){
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}

int cnt0[MN+5];
std::map<int,int> cnt1[MN+5];
std::map<pii,int> cnt2[MN+5];

int dif1[MN+5],dif2[MN+5],wei1[MN+5],wei2[MN+5];

int nId(){
	static int d = 0;
	return n+(++d);
}

long long c2(int x){
	return 1ll*x*(x-1)/2;
}

void dedif(int u,int f){
	for(auto v:e[u]){
		if(v==f) continue;
		dedif(v,u);
		dif1[u] += dif1[v];
		dif2[u] += dif2[v];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;i++){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	init(1,0);
	int m;
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		int o = lca(u,v);
		wei1[o]++;
		dif1[o] -= 2;
		dif1[u]++;
		dif1[v]++;
		int tu = jump(u,dep[u]-dep[o]-1);
		int tv = jump(v,dep[v]-dep[o]-1);
		if(tu!=o) wei2[tu]++;
		if(tv!=o) wei2[tv]++;
		dif2[tu]--;
		dif2[tv]--;
		dif2[u]++;
		dif2[v]++;
		if(tu==o) tu = nId();
		if(tv==o) tv = nId();
		cnt0[o]++;
		cnt1[o][tu]++;
		cnt1[o][tv]++;
		if(tu>tv) std::swap(tu,tv);
		cnt2[o][pii(tu,tv)]++;
	}
	dedif(1,0);
	long long ans = 0;
	for(int i=1;i<=n;i++){
		ans += c2(cnt0[i]);
		for(auto p:cnt1[i])
			ans -= c2(p.second);
		for(auto p:cnt2[i])
			ans += c2(p.second);
		ans += 1ll*wei1[i]*dif1[i];
		ans -= 1ll*wei2[i]*dif2[i];
	}
	printf("%lld\n",ans);
}