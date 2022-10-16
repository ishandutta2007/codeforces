#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=1000000007;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,k,el,head[maxn],to[maxn*2],nxt[maxn*2],w[maxn*2],cnt,col[maxn],sz[maxn],ans;
inline void add(int u,int v,int w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
void dfs(int u){
	col[u]=cnt;sz[cnt]++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(col[v] || w[i]) continue;
		dfs(v);
	}
}
int main(){
	n=read();k=read();
	FOR(i,1,n-1){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	FOR(i,1,n) if(!col[i]) cnt++,dfs(i);
	ans=qpow(n,k);
	FOR(i,1,cnt) ans=(ans-qpow(sz[i],k)+mod)%mod;
	printf("%d\n",ans);
}