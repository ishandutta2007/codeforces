#include <stdio.h>
#include <vector>
#define MN 500000
const int mod = 1000000007;

int n,m;
int fa[MN+5];
bool e[MN+5];

int cnt = 0;
int sz = 1;
std::vector<int> v;

int gf(int u){
	return fa[u]==u?u:fa[u]=gf(fa[u]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		fa[i] = i;
		e[i] = false;
	}
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		if(k==1){
			int u;
			scanf("%d",&u);
			u = gf(u);
			if(e[u]) continue;
			e[u] = true;
			cnt++;
			sz = (sz*2)%mod;
			v.push_back(i);
		}
		if(k==2){
			int u,v;
			scanf("%d%d",&u,&v);
			u = gf(u);
			v = gf(v);
			if(u==v) continue;
			if(e[u]){
				if(e[v]){
					continue;
				}else{
					fa[u] = v;
					e[v] = true;
				}
			}else{
				if(e[v]){
					fa[v] = u;
					e[u] = true;
				}else{
					fa[u] = v;
					e[u] = true;
				}
			}
			cnt++;
			sz = (sz*2)%mod;
			::v.push_back(i);
		}
	}
	printf("%d %d\n",sz,cnt);
	for(auto a:v)
		printf("%d ",a);
	puts("");
}