#include <stdio.h>
#include <vector>
#define MN 1000
typedef std::pair<int,int> pii;

using std::vector;

struct B{
	int fa[MN+5];
	void init(int n){
		for(int i=1;i<=n;i++)
			fa[i] = i;
	}
	int gf(int u){
		return fa[u]==u?u:fa[u]=gf(fa[u]);
	}
	bool test(int u,int v){
		return gf(u)!=gf(v);
	}
	bool unite(int u,int v){
		u = gf(u);
		v = gf(v);
		if(u==v) return false;
		fa[v] = u;
		return true;
	}
}B[2];

int main(){
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	B[0].init(n);
	B[1].init(n);
	for(int i=1;i<=m1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		B[0].unite(u,v);
	}
	for(int i=1;i<=m2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		B[1].unite(u,v);
	}
	vector<pii> ans;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(B[0].test(i,j)&&B[1].test(i,j)){
				ans.push_back({i,j});
				B[0].unite(i,j);
				B[1].unite(i,j);
			}
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto p:ans){
		printf("%d %d\n",p.first,p.second);
	}
}