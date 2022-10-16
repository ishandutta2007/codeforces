#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=400040;
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
int n,k,el,head[maxn],to[maxn],nxt[maxn],dep[maxn],sz[maxn],x[maxn];
ll ans;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
int main(){
	n=read();k=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	FOR(i,1,n) x[i]=dep[i]-sz[i];
	sort(x+1,x+n+1);
	FOR(i,n-k+1,n) ans+=x[i];
	printf("%lld\n",ans);
}