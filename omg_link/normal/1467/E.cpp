#include <stdio.h>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#define MN 200000

using std::map;
using std::sort;
using std::stack;
using std::vector;

int n,c[MN+5],vl[MN+5],ans;
vector<int> e[MN+5];
vector<int> pList[MN+5];

int dfn[MN+5],dep[MN+5],fa[MN+5][20];

void lsh(){
	int id = 0;
	map<int,int> mp;
	for(int i=1;i<=n;i++)
		mp[c[i]];
	for(auto &p:mp){
		p.second = ++id;
	}
	for(int i=1;i<=n;i++){
		c[i] = mp[c[i]];
		pList[c[i]].push_back(i);
	}
}

void add(int u,int v){
	e[u].push_back(v);
}

int lca(int u,int v){
	if(dep[u]>dep[v]) std::swap(u,v);
	for(int i=18;i>=0;i--)
		if((dep[v]-dep[u])&(1<<i))
			v=fa[v][i];
	if(u==v) return u;
	for(int i=18;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
			u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

int fun(int u,int v){
	for(int i=18;i>=0;i--)
		if((dep[u]-dep[v]-1)&(1<<i))
			u=fa[u][i];
	return u;
}

void dfs(int u,int f){
	static int dfn_cnt = 0;
	dfn[u] = ++dfn_cnt;
	for(int i=1;i<=18;i++)
		if(fa[u][i-1])
			fa[u][i] = fa[fa[u][i-1]][i-1];
		else
			break;
	for(auto to:e[u]){
		if(to==f) continue;
		fa[to][0] = u;
		dep[to] = dep[u]+1;
		dfs(to,u);
	}
}

void dfsAns(int u,int f,int v=0){
	v += vl[u];
	if(v==0) ans++;
	for(auto to:e[u]){
		if(to==f) continue;
		dfsAns(to,u,v);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	lsh();
	for(int i=2,u,v;i<=n;i++){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		sort(pList[i].begin(),pList[i].end(),[](int a,int b)->bool{
			return dfn[a]<dfn[b];
		});
		vector<int> s;
		for(auto u:pList[i]){
			while(!s.empty()){
				int v = s.back();
				int o = lca(u,v);
				if(o==v){
					s.push_back(u);
					break;
				}else{
					vl[s.back()]++;
					vl[u]++;
					s.pop_back();
				}
			}
			if(s.empty()){
				s.push_back(u);
			}
			if(s.size()>=3){
				puts("0");
				return 0;
			}
			if(s.size()==2){
				vl[1]++;
				vl[s[1]]++;
				vl[fun(s[1],s[0])]--;
			}
		}
	}
	dfsAns(1,0);
	printf("%d\n",ans);
}