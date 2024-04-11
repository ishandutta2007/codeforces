#include<bits/stdc++.h>
using namespace std;
const int maxn=300030,mod=998244353;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int t,n,m,el,ccc,head[maxn],to[maxn*2],nxt[maxn*2],bl[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int dfs(int u){
	int ans=bl[u]==1;
	ccc=(ccc+1)%mod;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!bl[v]){
			bl[v]=3-bl[u];
			int x=dfs(v);
			if(x==-1) return -1;
			ans=(ans+x)%mod;
		}
		else if(bl[v]==bl[u]) return -1;
	}
	return ans;
}
int main(){
	t=read();
	while(t--){
		n=read();m=read();
		FOR(i,1,m){
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		bool flag=true;
		int ans=1;
		FOR(i,1,n) if(!bl[i]){
			bl[i]=1;
			ccc=0;
			int x=dfs(i);
			if(x==-1){flag=false;break;}
			ans=1ll*ans*(qpow(2,x)+qpow(2,ccc-x))%mod;
		}
		if(!flag) puts("0");
		else printf("%d\n",ans);
		FOR(i,1,n) head[i]=bl[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=0;
		el=0;
	}
}