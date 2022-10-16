#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5000500;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline ll getc(){
	char ch=getchar();
	while(ch<'0' || ch>'1') ch=getchar();
	return ch-'0';
}
int n,m,d,head[maxn],el,to[maxn],nxt[maxn],head2[maxn],el2,to2[maxn],nxt2[maxn];
int dfn[maxn],low[maxn],dfs_clock,stk[maxn],tp,id[maxn],scc,cnt[maxn],tmp[maxn],tl,dp[maxn];
ll vld[100010];
bool vis[maxn],ins[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
} 
inline void add2(int u,int v){
	to2[++el2]=v;nxt2[el2]=head2[u];head2[u]=el2;
}
inline void dfs(int u){
	dfn[u]=low[u]=++dfs_clock;
	ins[stk[++tp]=u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		scc++;tl=0;	//++ 
	    do{
		    ins[stk[tp]]=false;
		    id[stk[tp]]=scc;
		    int x=(stk[tp]+d-1)/d,y=stk[tp]%d?stk[tp]%d:d;
			//(x,y) 
		    if(!((vld[x]>>y)&1)) continue;	//(x,y) 
		    tmp[++tl]=x;
		    if(!vis[x]) vis[x]=true,cnt[scc]++;	//x 
		}while(stk[tp--]!=u);
		FOR(i,1,tl) vis[tmp[i]]=0;	//vis 
	}
}
int main(){
	n=read();m=read();d=read();
	FOR(i,1,m){
		int u=read(),v=read();
		FOR(j,1,d) add((u-1)*d+j,(v-1)*d+j%d+1);
	}
	FOR(i,1,n) FOR(j,1,d) vld[i]|=getc()<<j;	//MLE 
	FOR(i,1,n*d) if(!dfn[i]) dfs(i);
	FOR(u,1,n*d) for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(id[u]!=id[v]) add2(id[u],id[v]);	// 
	}
	//tarjan 1n 
	FOR(u,1,scc){
		for(int i=head2[u];i;i=nxt2[i]) dp[u]=max(dp[u],dp[to2[i]]);
		dp[u]+=cnt[u];
	}
	printf("%d\n",dp[id[1]]); 
}