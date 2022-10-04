#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
long long f[9][305][305];
long long g[305][305],t[305][305];
int main(){
	memset(f,0xc0,sizeof f);
	memset(g,0xc0,sizeof g);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		f[0][i][i]=g[i][i]=0;
	for(int i=1;i<=m;++i){
		int x,y; long long z,zz;
		scanf("%d%d%lld%lld",&x,&y,&z,&zz);
		if(z+zz>0) return puts("2"),0;
		f[0][x][y]=z;
		f[0][y][x]=zz;
	}
	for(int i=1;(1<<i)<=n;++i) for(int u=1;u<=n;++u) for(int v=1;v<=n;++v)
		for(int j=1;j<=n;++j) f[i][u][v]=max(f[i][u][v],f[i-1][u][j]+f[i-1][j][v]);
	int num=0;
	for(int i=31-__builtin_clz(n);~i;--i){
		int ok=0;
		for(int u=1;u<=n;++u) {
			for(int v=1;v<=n;++v) if(g[u][v]+f[i][v][u]>0) {ok=1; break;}
			if(ok) break;
		}
		if(!ok){
			memset(t,0xc0,sizeof t);
			num+=(1<<i);
			for(int u=1;u<=n;++u) for(int v=1;v<=n;++v)
				for(int j=1;j<=n;++j) t[u][v]=max(t[u][v],g[u][j]+f[i][j][v]);
			for(int u=1;u<=n;++u) for(int v=1;v<=n;++v) g[u][v]=t[u][v];
		}
	} printf("%d",num<n?num+1:0);
	return 0;
}