#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#define MN 500000

using std::queue;
using std::set;
using std::vector;

int p[MN+5],q[MN+5];
set<int> e[MN+5];

struct object{
	static int minVal;
	static void clear(){
		minVal = 1;
	}
	static int get(int k){
		int r = minVal;
		minVal += k;
		return r;
	}
}o;

int object::minVal;

struct tree{
	vector<int> e[MN+5];
	vector<int> f[MN+5];
	bool nd[MN+5];
	void clear(int n){
		for(int i=1;i<=n;i++){
			e[i].clear();
			f[i].clear();
			nd[i] = false;
		}
	}
	void add(int u,int v){
		e[u].push_back(v);
		e[v].push_back(u);
		nd[u] = nd[v] = true;
	}
	bool dfs(int u,int fa){
		nd[u] = false;
		int isCore = -1;
		for(auto v:e[u]){
			if(v==fa) continue;
			if(dfs(v,u)){
				isCore = v;
			}else{
				f[u].push_back(v);
			}
		}
		if(!f[u].size()){
			if(fa==0)
				f[isCore].push_back(u);
			return false;
		}else{
			return true;
		}
	}
	void solve(int n){
		for(int i=1;i<=n;i++)
			if(nd[i])
				dfs(i,0);
		for(int i=1;i<=n;i++){
			if(f[i].size()){
				int S = o.get(f[i].size()+1);
				p[i] = S+f[i].size();
				q[i] = S;
				for(int j=0;j<(int)f[i].size();j++){
					p[f[i][j]] = S+j;
					q[f[i][j]] = S+j+1;
				}
			}
		}
	}
}T;

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		e[i].clear();
	o.clear();
	T.clear(n);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[u].insert(v);
		e[v].insert(u);
	}
	{
		set<int> uc;
		for(int i=1;i<=n;i++)
			if((int)e[i].size()>=n-1)
				p[i] = q[i] = o.get(1);
			else
				uc.insert(i);
		queue<int> q;
		while(!uc.empty()){
			int u;
			if(!q.empty()){
				u = q.front();
				q.pop();
			}else{
				u = *uc.begin();
				uc.erase(uc.begin());
			}
			vector<int> its;
			for(auto v:uc){
				if(e[u].find(v)!=e[u].end()) continue;
				its.push_back(v);
				T.add(u,v);
				q.push(v);
			}
			for(auto v:its){
				uc.erase(v);
			}
		}
	}
	T.solve(n);
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	puts("");
	for(int i=1;i<=n;i++)
		printf("%d ",q[i]);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve(); 
}