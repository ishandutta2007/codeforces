#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
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
int n,h[maxn],el,head[maxn],to[maxn],nxt[maxn],pos[maxn],g[maxn];
ll f[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline bool cmp(int x,int y){
	return h[x]<h[y];
}
void dfs(int u,int F){
	int mx=0,mx2=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		dfs(v,u);
		f[u]+=f[v]+g[v];
		if(g[v]>mx) mx2=mx,mx=g[v];
		else mx2=max(mx2,g[v]);
	}
	if(F) f[u]-=mx,g[u]=max(h[u],mx);
	else f[u]-=mx+mx2,f[u]+=max(h[u],mx)+max(h[u],mx2);
//	printf("f[%d]=%lld\n",u,f[u]);
}
int main(){
	n=read();
	FOR(i,1,n) h[i]=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	FOR(i,1,n) pos[i]=i;
	sort(pos+1,pos+n+1,cmp);
	dfs(pos[n],0);
	printf("%lld\n",f[pos[n]]);
}