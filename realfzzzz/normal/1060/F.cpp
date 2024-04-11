#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=50+5;
int n;
vector<int> g[maxn];
ll C[maxn][maxn];
int sz[maxn];
using ld=long double;
ld f[maxn][maxn],tmp[maxn];
void dfs(int u,int fa){
	sz[u]=1;
	f[u][1]=1;
	for(int v:g[u]) if(v!=fa){
		dfs(v,u);
		memset(tmp,0,sizeof(tmp));
		for(int i=1;i<=sz[u];i++) for(int j=1;j<=sz[v];j++){
			for(int k=1;k<=i+j-1;k++)
				tmp[k]+=f[u][i]*f[v][j]*C[k-1][i-1]*C[sz[u]+sz[v]-k][sz[u]-i]/2;
			tmp[i+j]+=f[u][i]*f[v][j]*C[i+j-2][i-1]*C[sz[u]+sz[v]-i-j][sz[u]-i]*(i+j-1);
		}
		sz[u]+=sz[v];
		for(int i=1;i<=sz[u];i++) f[u][i]=tmp[i]/C[sz[u]-2][sz[v]-1]/(sz[u]-1);
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	for(int i=1;i<=n;i++){
		dfs(i,0);
		printf("%.10Lf\n",f[i][1]);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}