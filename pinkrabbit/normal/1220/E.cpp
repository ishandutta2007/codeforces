#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,s,a[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
ll dis[MN],Ans;
void dfs(int u,int fa){
	dis[u]=dis[fa]+a[u];
	for(int i=h[u];i;i=nxt[i])if(to[i]!=fa)dfs(to[i],u);
}
int deg[MN],vis[MN],faz[MN],que[MN],l,r;
int main(){
	int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,m)scanf("%d%d",&x,&y),ins(x,y),ins(y,x),++deg[x],++deg[y];
	scanf("%d",&s);
	if(m==n-1){
		dfs(s,0);
		printf("%lld\n",*max_element(dis+1,dis+n+1));
		return 0;
	}
	l=1,r=0;
	F(i,1,n)if(deg[i]==1)que[++r]=i,vis[i]=1;
	while(l<=r){
		int u=que[l++];
		for(int i=h[u];i;i=nxt[i])if(!vis[to[i]]){
			faz[u]=to[i];
			if(1==--deg[to[i]])que[++r]=to[i],vis[to[i]]=1;
		}
	}
	F(i,1,n)if(!vis[i])Ans+=a[i];
	if(vis[s]){
		int z=s;
		while(faz[z])Ans+=a[z],a[z]=0,z=faz[z];
	}
	dF(i,r,1)dis[que[i]]=dis[faz[que[i]]]+a[que[i]];
	Ans+=*max_element(dis+1,dis+n+1);
	printf("%lld\n",Ans);
	return 0;
}