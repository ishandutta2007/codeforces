#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
vi g[N];
int dep[N],fa[N][20];
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	per(i,0,20)if(d>>i&1)u=fa[u][i];
	if(u==v)return u;
	per(i,0,20)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int get(int u,int v){
	int f=LCA(u,v);
	return dep[u]+dep[v]-2*dep[f];
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	int q;
	scanf("%d",&q);
	dep[0]=-1;
	dfs(1,0);
	LCAFA;
	while(q--){
		int k;
		int u[4];
		int d[4][4];
		scanf("%d%d%d%d%d",&u[0],&u[1],&u[2],&u[3],&k);
		rep(i,0,4)rep(j,0,i)d[i][j]=d[j][i]=get(u[i],u[j]);
		if((dep[u[0]]-dep[u[1]])&1){
			int ans=min({d[2][3],d[2][0]+d[3][1]+1,d[2][1]+d[3][0]+1});
			if(k>=ans&&(k-ans)%2==0)printf("YES\n");
			else printf("NO\n");
		}
		else{
			int ans=min(d[2][0]+d[3][1]+1,d[2][1]+d[3][0]+1);
			if(k>=ans&&(k-ans)%2==0)printf("YES\n");
			else if(k>=d[2][3]&&(k-d[2][3])%2==0)printf("YES\n");
			else printf("NO\n");
		}
	}
}