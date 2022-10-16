#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1555,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
struct edge{
	int u,v,w;
	bool operator<(const edge &e)const{
		return w<e.w;
	}
}e[maxn*maxn/2];
int n,el,cnt,fa[maxn*2],f[maxn*2][maxn],sz[maxn*2],ls[maxn*2],rs[maxn*2],ec[maxn*2];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void dfs(int u){
	if(ls[u] || rs[u]){
		assert(ls[u] && rs[u]);
		dfs(ls[u]);dfs(rs[u]);
		sz[u]+=sz[ls[u]]+sz[rs[u]];
		FOR(i,1,sz[ls[u]]) FOR(j,1,sz[rs[u]])
			f[u][i+j]=(f[u][i+j]+1ll*f[ls[u]][i]*f[rs[u]][j])%mod; 
	}
	else sz[u]=1;
	if(ec[u]==sz[u]*(sz[u]-1)/2) f[u][1]=(f[u][1]+1)%mod;
}
int main(){
	cnt=n=read();
	FOR(i,1,n) FOR(j,1,n){
		int x=read();
		if(i<j) e[++el]=(edge){i,j,x};
	}
	sort(e+1,e+el+1);
	FOR(i,1,2*n) fa[i]=i;
	FOR(i,1,el){
		int u=e[i].u,v=e[i].v;
		u=getfa(u);v=getfa(v);
		if(u==v){ec[u]++;continue;}
		fa[u]=fa[v]=++cnt;
		ls[cnt]=u;rs[cnt]=v;
		ec[cnt]=ec[u]+ec[v]+1;
	}
	dfs(cnt);
	FOR(i,1,n) printf("%d ",f[cnt][i]);
}