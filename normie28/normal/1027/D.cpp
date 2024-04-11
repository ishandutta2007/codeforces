// Thanks to robs77 for this template
/***********HEADER***************/
#include <bits/stdc++.h>
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
#define ll  long long 

/*********VARIABLE****************/
using namespace std;
typedef pair<ll,ll> ii;
/******************************/
const ll N=200000+10;
int n,c[N],to[N],bel[N],val[N],scc;
int stk[N],tp,ins[N];
int low[N],dfn[N],vis[N],idx;
unsigned long long ans=0;
 int out[N];
/*********FUNCTIONS**************/
int read(){
	int x=0;char c;
	do{c=getchar();}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	return x;
}

void dfs(int u){
	low[u]=dfn[u]=++idx;
	ins[stk[++tp]=u]=1;
 
	int v=to[u]; if(!dfn[v]){
		dfs(v); low[u]=std::min(low[u],low[v]);
	}else if(ins[v]) low[u]=std::min(low[u],dfn[v]);
 
	if(low[u]==dfn[u]){
		val[++scc]=c[u];int x=0;
		do{
			bel[x=stk[tp]]=scc; ins[x]=0; stk[tp--]=0;
			val[scc]=std::min(val[scc],c[x]);
		}while(x!=u);
	}
 
}
 

/***********MAIN**************/

int main(void) 
{
	n=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) to[i]=read();
 
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;i++) if(bel[i]!=bel[to[i]])
		out[bel[i]]++;
	for(int i=1;i<=scc;i++) if(out[i]==0) ans=ans+val[i];
 
	std::cout<<ans<<std::endl;
}