#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,a[maxn],b[maxn],el,head[maxn],to[maxn],nxt[maxn],dfn[maxn],dfc,low[maxn],stk[maxn],tp,id[maxn],cnt;
bool ins[maxn],in[maxn];
PII p[maxn];
void clear(){
	FOR(i,1,3*n) head[i]=dfn[i]=low[i]=id[i]=in[i]=0;
	FOR(i,1,el) to[i]=nxt[i]=0;
	dfc=cnt=el=0;
}
inline void add(int u,int v){
//	printf("add(%d,%d)\n",u,v);
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	dfn[u]=low[u]=++dfc;
	stk[++tp]=u;
	ins[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		cnt++;
		do{
			id[stk[tp]]=cnt;
			ins[stk[tp]]=false;
		}while(stk[tp--]!=u);
	}
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) b[i]=read();
	FOR(i,1,n) p[i]=MP(a[i],i);
	sort(p+1,p+n+1);
	ROF(i,n,1){
		add(p[i].second,i+n);
		if(i!=1){
			add(i+n,p[i-1].second);
			add(i+n,i-1+n);
		}
	}
	FOR(i,1,n) p[i]=MP(b[i],i);
	sort(p+1,p+n+1);
	ROF(i,n,1){
		add(p[i].second,i+2*n);
		if(i!=1){
			add(i+2*n,p[i-1].second);
			add(i+2*n,i-1+2*n);
		}
	}
	FOR(i,1,3*n) if(!dfn[i]) dfs(i);
	FOR(u,1,3*n) for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(id[u]!=id[v]) in[id[v]]=true;
	}
	FOR(i,1,n) putchar('0'+!in[id[i]]);
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}