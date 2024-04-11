#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
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
int n,el,head[maxn],to[maxn],nxt[maxn],a[maxn],rt,len,col;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f,int c,int d){
	if(d>len || !col) len=d,rt=u,col=c;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(!c) dfs(v,u,a[v],d);
		else{
			int t=a[v]?a[v]:c;
			dfs(v,u,t,d+(t!=c));
		}
	}
}
void clear(){
	rt=len=col=0;
	FOR(i,1,el) to[i]=nxt[i]=0;
	FOR(i,1,n) head[i]=a[i]=0;
	el=0;
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0,a[1],1);
	len=0;
	dfs(rt,0,col,1);
	printf("%d\n",len/2+1);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}