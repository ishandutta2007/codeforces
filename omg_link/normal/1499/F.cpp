#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 5000
typedef long long LL;
const int mod = 998244353;

int n,k;
std::vector<int> e[MN+5];
int f[MN+5][MN+5],g[MN+5][MN+5],d[MN+5];

void add(int u,int v){
	e[u].push_back(v);
}

void dfs(int u,int fa){
	for(int v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		d[u] = std::max(d[u],d[v]+1);
	}
	for(int i=0;i<=k;i++){
		if(i*2<=k){
			static int lstm;
			if(i==0){
				f[u][i+1] = 1;
				for(int v:e[u]){
					if(v==fa) continue;
					f[u][i+1] = 1ll*f[u][i+1]*g[v][i]%mod;
				}
				lstm = f[u][i+1];
			}else{
				LL m2=1;
				for(int v:e[u]){
					if(v==fa) continue;
					m2 = m2*g[v][i]%mod;
				}
				f[u][i+1] = (m2-lstm+mod)%mod;
				lstm = m2;
			}
		}else{
			if(i>d[u]) break;
			std::vector<int> pre,suf;
			pre.push_back(1);
			suf.push_back(1);
			for(auto it=e[u].begin();it!=e[u].end();it++){
				if(*it==fa) continue;
				pre.push_back(1ll*pre.back()*g[*it][k-i]%mod);
			}
			for(auto it=e[u].rbegin();it!=e[u].rend();it++){
				if(*it==fa) continue;
				suf.push_back(1ll*suf.back()*g[*it][k-i]%mod);
			}
			int id1 = 0;
			int id2 = (int)pre.size()-2;
			for(int v:e[u]){
				if(v==fa) continue;
				f[u][i+1] = (f[u][i+1]+1ll*pre[id1]*suf[id2]%mod*f[v][i])%mod;
				id1++,id2--;
			}
		}
		f[u][0] = (f[u][0]+f[u][i+1])%mod;
	}
	g[u][0] = f[u][0];
	for(int i=1;i<=k;i++){
		g[u][i] = (g[u][i-1]+f[u][i])%mod;
	}
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dfs(1,0);
	printf("%d\n",f[1][0]);
}