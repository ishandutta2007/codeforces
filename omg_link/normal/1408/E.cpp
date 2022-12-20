#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 100000
#define MM 200000
typedef long long LL;

int m,n,a[MN+5],b[MN+5];

struct edge{
	int u,v,w;
};

std::vector<edge> v;

int toSet(int x){return x;}
int toNode(int x){return x+m;}

int fa[MM+5];

int gf(int u){
	return fa[u]==u?u:fa[u]=gf(fa[u]);
}

bool unite(int u,int v){
	u = gf(u);
	v = gf(v);
	if(u==v) return false;
	fa[v] = u;
	return true;
}

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1,s;i<=m;i++){
		scanf("%d",&s);
		for(int j=1,u;j<=s;j++){
			scanf("%d",&u);
			v.push_back((edge){toSet(i),toNode(u),a[i]+b[u]});
		}
	}
	for(int i=1;i<=n+m;i++)
		fa[i] = i;
	std::sort(v.begin(),v.end(),[](edge a,edge b)->bool{
		return a.w>b.w;
	});
	LL ans = 0;
	for(auto e:v){
		if(!unite(e.u,e.v))
			ans += e.w;
	}
	printf("%lld\n",ans);
}