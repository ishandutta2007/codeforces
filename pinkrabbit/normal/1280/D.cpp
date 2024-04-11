#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 3005
#define ll long long
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,k,siz[MN],f[MN][MN];
ll a[MN],g[MN][MN];
vector<int>V[MN];
void DFS(int u,int fz){
	siz[u]=1;
	f[u][1]=0,g[u][1]=a[u];
	for(auto v:V[u])if(v!=fz){
		DFS(v,u);
		static int F[MN];
		static ll G[MN];
		F(i,1,siz[u]+siz[v])F[i]=-1,G[i]=-infll;
		F(i,1,siz[u])F(j,1,siz[v]){
			if(F[i+j-1]<f[u][i]+f[v][j]||(F[i+j-1]==f[u][i]+f[v][j]&&G[i+j-1]<g[u][i]+g[v][j]))
				F[i+j-1]=f[u][i]+f[v][j],G[i+j-1]=g[u][i]+g[v][j];
			if(F[i+j]<f[u][i]+f[v][j]+(g[v][j]>0)||(F[i+j]==f[u][i]+f[v][j]+(g[v][j]>0)&&G[i+j]<g[u][i]))
				F[i+j]=f[u][i]+f[v][j]+(g[v][j]>0),G[i+j]=g[u][i];
		}
		siz[u]+=siz[v];
		F(i,1,siz[u])f[u][i]=F[i],g[u][i]=G[i];
	}
//	F(i,1,siz[u])printf("(f,g)[%d][%d]=%d,%lld\n",u,i,f[u][i],g[u][i]);
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){int x,y;
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%lld",a+i);
	F(i,1,n)scanf("%d",&x),a[i]=x-a[i];
	F(i,1,n)V[i].clear();
	F(i,2,n)scanf("%d%d",&x,&y),V[x].pb(y),V[y].pb(x);
	DFS(1,0);
	printf("%d\n",f[1][k]+(g[1][k]>0));
}	return 0;
}