#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#define MN 100000
typedef std::pair<int,int> pii;

using std::map;
using std::set;
using std::swap;
using std::vector;

struct BCJ1{
	struct Node{
		int val,id;
		bool operator < (const Node& that)const{
			return this->val < that.val;
		}
	};
	int fa[MN+5];
	set<Node> s[MN+5];
	set<int> activeMulti;
	map<int,set<int>> activeSingle;
	
	void enable(int u){
		if(s[u].size()==1){
			int val = (*s[u].begin()).val;
			activeSingle[val].insert(u);
		}else{
			activeMulti.insert(u);
		}
	}
	void disable(int u){
		if(s[u].size()==1){
			int val = (*s[u].begin()).val;
			activeSingle[val].erase(u);
			if(activeSingle[val].size()==0)
				activeSingle.erase(val);
		}else{
			activeMulti.erase(u);
		}
	}
	bool getNode(int& u,int& v){
		if(activeMulti.size()+activeSingle.size()<2) return false;
		Node ret[2] = {{-1,-1},{-1,-1}};
		int cnt = 0;
		for(const auto& pis:activeSingle){
			if(cnt==0||ret[0].val!=pis.first){
				int x = *pis.second.begin();
				ret[cnt++] = *s[x].begin();
				if(cnt==2) break;
			}
		}
		if(cnt<2)
			for(int x:activeMulti){
				for(Node p:s[x]){
					if(cnt==0||ret[0].val!=p.val){
						ret[cnt++] = p;
						break;
					}
				}
				if(cnt==2) break;
			}
		assert(cnt==2);
		u = ret[0].id;
		v = ret[1].id;
		return true;
	}
	void init(int n){
		for(int i=1;i<=n;i++){
			fa[i] = i;
			s[i].insert({i,i});
			enable(i);
		}
	}
	int gf(int u){
		return fa[u]==u?u:fa[u]=gf(fa[u]);
	}
	void unite(int u,int v){
		u = gf(u);
		v = gf(v);
		assert(u!=v);
		if(s[u].size()<s[v].size())
			swap(u,v);
		disable(u);
		disable(v);
		for(auto p:s[v])
			s[u].insert(p);
		fa[v] = u;
		enable(u);
	}
	void update(int u,int val,int nval){
		int hd = gf(u);
		auto it = s[hd].find({val,0});
		if(it==s[hd].end()) return;
		disable(hd);
		s[hd].erase(it);
		s[hd].insert({nval,u});
		enable(hd);
	}
}B1;

struct BCJ2{
	int fa[MN+5];
	vector<int> a[MN+5];
	
	void init(int n){
		for(int i=1;i<=n;i++){
			fa[i] = i;
			a[i].push_back(i);
		}
	}
	void unite(int u,int v){
		u = fa[u];
		v = fa[v];
		assert(u!=v);
		if(a[u].size()<a[v].size())
			swap(u,v);
		for(auto x:a[v]){
			B1.update(x,v,u);
			fa[x] = u;
			a[u].push_back(x);
		}
	}
}B2;

int main(){
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	B1.init(n);
	B2.init(n);
	for(int i=1;i<=m1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		B1.unite(u,v);
	}
	for(int i=1;i<=m2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		B2.unite(u,v);
	}
	vector<pii> ans;
	for(int u,v;B1.getNode(u,v);){
		B1.unite(u,v);
		B2.unite(u,v);
		ans.push_back({u,v});
	}
	printf("%d\n",(int)ans.size());
	for(auto p:ans){
		printf("%d %d\n",p.first,p.second);
	}
}