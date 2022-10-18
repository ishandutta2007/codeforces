#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
const int maxn=444444,mod=998244353,INF=1e9;
#define all(v) v.begin(),v.end()
#define sz(v) int(v.size())
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,k,el,a[maxn],fa[maxn],head[maxn],to[maxn],nxt[maxn],deg[maxn];
int l[maxn],r[maxn],tl;
ll fl[maxn],fr[maxn],tmp[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void clear(){
	FOR(i,1,n) l[i]=r[i]=fl[i]=fr[i]=head[i]=fa[i]=deg[i]=0;
	FOR(i,1,el) to[i]=nxt[i]=0;
	el=0;
}
void dfs(int u){
	int cl=l[u],cr=r[u];
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		l[v]=l[u]/deg[u];
		r[v]=(r[u]+deg[u]-1)/deg[u];
		dfs(v);
		fl[u]+=fl[v];
		fr[u]+=fl[v];
		cl-=l[v];
		cr-=l[v];
	}
	fl[u]+=1ll*a[u]*l[u];
	fr[u]+=1ll*a[u]*r[u];
	if(!head[u]) return;
	tl=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(l[v]!=r[v]) tmp[++tl]=fr[v]-fl[v]; 
	}
	sort(tmp+1,tmp+tl+1,greater<ll>());
	FOR(i,1,cl) fl[u]+=tmp[i];
	FOR(i,1,cr) fr[u]+=tmp[i]; 
}
void solve(){
	n=read();k=read();
	FOR(i,2,n) add(fa[i]=read(),i),deg[fa[i]]++;
	FOR(i,1,n) a[i]=read();
	l[1]=r[1]=k;
	dfs(1);
	printf("%lld\n",fl[1]);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}