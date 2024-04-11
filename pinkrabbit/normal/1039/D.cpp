#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std; // lgv
int n;
int h[100001],nxt[200001],to[200001],tot;
void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int fa[100001],dfn[100001],cnt;
void DFS(int u){
	for(int i=h[u];i;i=nxt[i]) if(to[i]!=fa[u]) fa[to[i]]=u, DFS(to[i]);
	dfn[++cnt]=u;
}
int f[100001],g[100001];
int ans[100001];
int dp(int k){
	if(~ans[k]) return ans[k];
	for(int I=1;I<=n;++I){
		int u=dfn[I];
		int mx1=0, mx2=0, sum=0;
		for(int i=h[u];i;i=nxt[i]) if(to[i]!=fa[u]){
			sum+=f[to[i]];
			if(g[to[i]]>mx2) mx2=g[to[i]];
			if(mx2>mx1) swap(mx1,mx2);
		}
		f[u]=sum;
		if(mx1+mx2+1>=k) ++f[u], g[u]=0;
		else g[u]=mx1+1;
	} return ans[k]=f[1];
}
int S;
void solve(int L,int R,int Al,int Ar){
	if(Al>Ar) return;
	if(L==R){
		for(int i=Al;i<=Ar;++i) ans[i]=L;
		return;
	}
	int Mid=L+R>>1, l=Al, r=Ar, mid, mn=Ar+1;
	while(l<=r){
		mid=l+r>>1;
		if(dp(mid)<=Mid) mn=mid, r=mid-1;
		else l=mid+1;
	}
	solve(L,Mid,mn,Ar);
	solve(Mid+1,R,Al,mn-1);
}
int main(){
	int x,y;
	scanf("%d",&n); S=(sqrt(n*(31-__builtin_clz(n)))-1)/2.3+1;
	for(int i=1;i<n;++i) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	DFS(1);
	memset(ans,-1,sizeof ans);
	ans[1]=n;
	for(int i=2;i<=S;++i) dp(i);
	int B=n+1;
	solve(0,ans[S],S+1,B-1);
	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);
	return 0;
}