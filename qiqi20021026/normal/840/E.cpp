#include<bits/stdc++.h>

using namespace std;

#define N 80000

int n,m,x,y,tot,u,v,a[N],fa[N],lst[N],dep[N],c[N][2],cnt,rt[N],head[N],f[N][300];
struct edge{int v,nxt;}e[N];

void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa[u]){
			fa[v]=u; dfs(v);
		}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1);
	for (int i=1;i<=n;++i){
		int u=i; cnt=1; c[1][0]=c[1][1]=0;
		for (int j=0;u&&j<256;++j,u=fa[u]){
			int x=a[u]^j,xb=1;
			for (int k=16;k>=0;--k){
				int t=x>>k&1;
				if (!c[xb][t]){c[xb][t]=++cnt; c[cnt][0]=c[cnt][1]=0;}
				xb=c[xb][t];
			}
		}
		for (int j=0;j<=256;++j){
			int x=j*256,xb=1,tmp=0;
			for (int k=16;k>=0;--k){
				int t=x>>k&1;
				if (c[xb][!t]){xb=c[xb][!t]; tmp+=1<<k;}
				else xb=c[xb][t];
			}
			f[i][j]=tmp;
		}
		lst[i]=u;
	}
	while (m--){
		scanf("%d%d",&u,&v);
		int ans=0,i;
		for (i=0;dep[v]-255>=dep[u];v=lst[v],++i)
			ans=max(ans,f[v][i]);
		for (i*=256;dep[v]>=dep[u];v=fa[v],++i)
			ans=max(ans,(a[v]^i));
		printf("%d\n",ans);
	}
	
	return 0;
}