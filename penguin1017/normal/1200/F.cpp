#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
const int mod=2520;
const int N=(int)1e3+9;
int ans[N][mod+5],con[N][10],m[N],now[N][mod],pos[mod*N+100],k[N],deg[N][mod],vis[N];
void dfs(int u,int c){
	int val=(c+k[u])%mod,v=con[u][val%m[u]];
	pos[deg[u][c]]=u;
	now[u][c]=1;
	if(u==v&&val==c){
		ans[u][c]=1;
		return;
	}
	if(ans[v][val]){
		ans[u][c]=ans[v][val];
		return;
	}
	if(now[v][val]){
		int cnt=0;
		rep(i,deg[v][val],deg[u][c]+1)if(!vis[pos[i]])cnt++,vis[pos[i]]=1;
		rep(i,deg[v][val],deg[u][c]+1)vis[pos[i]]=0;
		ans[u][c]=cnt;
		return;
	}
	deg[v][val]=deg[u][c]+1;
	dfs(v,val);
	ans[u][c]=ans[v][val];
}
int main()
{
	int n,q;
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&k[i]),k[i]=(k[i]%mod+mod)%mod;
	rep(i,1,n+1){
		scanf("%d",&m[i]);
		rep(j,0,m[i])scanf("%d",&con[i][j]);
	}
	scanf("%d",&q);
	rep(i,1,n+1){
		rep(j,0,mod){
			if(!ans[i][j])deg[i][j]=1,dfs(i,j);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",ans[x][(y%mod+mod)%mod]);
	}
 }