#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500050,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int T,n,k,el,head[maxn],to[maxn*2],nxt[maxn*2],w[maxn*2],tl;
ll tmp[maxn],f[maxn][2];
inline void add(int u,int v,int w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_;
}
void dfs(int u,int F){
	ll sum=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		dfs(v,u);
		sum+=f[v][0];
	}
	tl=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		tmp[++tl]=max(0ll,f[v][1]+w[i]-f[v][0]);
	}
	sort(tmp+1,tmp+tl+1,greater<ll>());
	f[u][0]=f[u][1]=sum;
	FOR(i,1,min(k-1,tl)) f[u][0]+=tmp[i],f[u][1]+=tmp[i];
	if(k<=tl) f[u][0]+=tmp[k];
}
int main(){
	T=read();
	while(T--){
		n=read();k=read();
		FOR(i,1,n-1){
			int u=read(),v=read(),w=read();
			add(u,v,w);add(v,u,w);
		}
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
		FOR(i,1,n) head[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=w[i]=0;
		el=0;
	}
} // Sleep on F5