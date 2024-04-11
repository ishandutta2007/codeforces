#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666666,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0;bool f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline int qmo(int x){return x+((x>>31)&mod);}
int n,el,head[maxn],to[maxn],nxt[maxn],dis[maxn],q[maxn],h=1,r,ans[maxn],res[maxn];
bool in1[maxn],in2[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
int main(){
	n=read();
	FOR(i,1,n) dis[i]=1e9;
	FOR(i,1,n) if(read()) q[++r]=i,dis[i]=0;
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	while(h<=r){
		int u=q[h++];
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,q[++r]=v;
		}
	}
	FOR(i,1,n) ans[i]=dis[i];
	FOR(u,1,n) for(int i=head[u];i;i=nxt[i]) if(dis[u]==dis[to[i]]) in1[dis[u]]=in2[u]=true;
	FOR(d,0,n-1) if(in1[d]){
		h=n+1;r=n;
		FOR(u,1,n) res[u]=-1e9;
		FOR(u,1,n) if(dis[u]==d && in2[u]) res[u]=0,q[++r]=u;
		while(h<=r){
			int u=q[h++];
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(dis[v]==dis[u]){
					if(min(0,res[u])-1>res[v]) res[v]=min(0,res[u])-1,q[++r]=v;
				}
				else if(dis[v]>dis[u]){
					if(min(0,res[u])+1>res[v]) res[v]=min(0,res[u])+1,q[--h]=v;
				}
			}
		}
		FOR(u,1,n) if(res[u]>=0) ans[u]=min(ans[u],d);
	}
	FOR(i,1,n) printf("%d ",2*dis[i]-ans[i]);
}