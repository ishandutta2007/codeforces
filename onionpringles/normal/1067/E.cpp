#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define mul(x,y) ((long long)(x)*(y)%mod)
const int N=501010;
vector<int> adj[N];
int d[N][2],e[N][2],
D[2],E[2];
void dfs(int u,int p=-1){
	d[u][1]=1;
	for(auto &x:adj[u]){
		if(x==p)continue;
		dfs(x,u);
		D[0]=D[1]=E[0]=E[1]=0;
		for(int j=0;j<2;j++){
			for(int i=0;i<2;i++){
				D[i]+=mul(d[u][i],mul(2-j*i,d[x][j]));
				if(D[i]>=mod)D[i]-=mod;
				E[i]+=mul(e[u][i],mul(2-j*i,d[x][j]));
				if(E[i]>=mod)E[i]-=mod;
				E[i]+=mul(e[x][j],mul(2-j*i,d[u][i]));
				if(E[i]>=mod)E[i]-=mod;
			}
		}
		D[0]+=mul(d[u][1],d[x][1]);
		if(D[0]>=mod)D[0]-=mod;
		E[0]+=mul(e[u][1],d[x][1]);
		if(E[0]>=mod)E[0]-=mod;
		E[0]+=mul(e[x][1],d[u][1]);
		if(E[0]>=mod)E[0]-=mod;
		E[0]+=mul(d[u][1],d[x][1]);
		if(E[0]>=mod)E[0]-=mod;
		for(int i=0;i<2;i++){
			d[u][i]=D[i];e[u][i]=E[i];
		}
	}
}
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	printf("%d\n",mul(2,(e[0][0]+e[0][1])%mod));
}