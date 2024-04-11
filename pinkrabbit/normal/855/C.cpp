#include<cstdio>
#define Mod 1000000007
int n,m,k,X,ans;
int he[100001],to[200001],nxt[200001],tot;
inline void ins(int x,int y){nxt[++tot]=he[x];to[tot]=y;he[x]=tot;}
int f[100001][11], g[100001][11], h[100001][11];
int F[100001][11], G[100001][11], H[100001][11];
void dfs(int u,int fa){
	int cnt=0;
	for(int i=he[u];i;i=nxt[i]) if(to[i]!=fa)
		dfs(to[i],u), ++cnt;
	if(cnt==0) {f[u][1]=1, g[u][0]=k-1, h[u][0]=m-k; for(int x=0;x<=X;++x) return;}
	f[u][0]=1, g[u][0]=k-1, h[u][0]=m-k;
	for(int i=he[u];i;i=nxt[i]) if(to[i]!=fa){
		for(int x=0;x<=X;++x){
			F[u][x]=G[u][x]=H[u][x]=0;
			for(int y=0;y<=x;++y){
				F[u][x]+=(long long)f[u][y]*g[to[i]][x-y]%Mod;
				F[u][x]%=Mod;
				G[u][x]+=(long long)g[u][y]*((f[to[i]][x-y]+g[to[i]][x-y])%Mod+h[to[i]][x-y])%Mod;
				G[u][x]%=Mod;
				H[u][x]+=(long long)h[u][y]*(g[to[i]][x-y]+h[to[i]][x-y])%Mod;
				H[u][x]%=Mod;
			}
		}
		for(int x=X;x>=0;--x)
			f[u][x]=F[u][x],
			g[u][x]=G[u][x],
			h[u][x]=H[u][x];
	}
	for(int x=X;x>=1;--x) f[u][x]=f[u][x-1];
	f[u][0]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<n;++i)
		scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	scanf("%d%d",&k,&X);
	dfs(1,0);
	for(int i=0;i<=X;++i) ans=((long long)ans+f[1][i]+g[1][i]+h[1][i])%Mod;
	printf("%d",ans);
	return 0;
}
//f[i][x][0] : ==k
//f[i][x][1] : <k
//f[i][x][2] : >k
//f[i][x][0] = pi _ f[s][x-1][1]
//f[i][x][1] = 
//f[i][x][2] : >k