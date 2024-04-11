#include <stdio.h>
#include <map>
#include <set>
#define MN 1000000
int n,m,q,fa[MN+5];
std::set<int> s[MN+5];
std::map<int,int> id[MN+5];
int gn(){
	static int cnt=100000;
	++cnt;
	fa[cnt]=cnt;
	return cnt;
}
int fun(int u,int c){
	if(id[u].find(c)==id[u].end())
		id[u][c]=gn();
	return id[u][c];
}
int gf(int u){
	return fa[u]==u?u:fa[u]=gf(fa[u]);
}
void unite(int u,int v){
	u=gf(u),v=gf(v);
	if(u==v) return;
	if(s[u].size()<s[v].size())
		std::swap(u,v);
	for(auto x:s[v]){
		if(s[u].find(x)==s[u].end())
			s[u].insert(x);
	}
	fa[v]=u;
}
void link(int u,int v,int c){
	unite(u,fun(v,c));
	unite(v,fun(u,c));
	int fu=gf(u),fv=gf(v);
	if(s[fv].find(u)==s[fv].end())
		s[fv].insert(u);
	if(s[fu].find(v)==s[fu].end())
		s[fu].insert(v);
}
int main(){
	scanf("%d%d%*d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		s[i].insert(i);
	}
	for(int i=1,u,v,c;i<=m;i++){
		scanf("%d%d%d",&u,&v,&c);
		link(u,v,c);
	}
	while(q--){
		static char opt[2];
		static int x,y,z;
		scanf("%s",&opt[0]);
		if(opt[0]=='?'){
			scanf("%d%d",&x,&y);
			x=gf(x);
			puts(s[x].find(y)==s[x].end()?"No":"Yes");
		}else{
			scanf("%d%d%d",&x,&y,&z);
			link(x,y,z);
		}
	}
}