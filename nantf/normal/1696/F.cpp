#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222,mod=998244353;
#define NO return puts("No"),clear()
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
int n,uf[maxn],fa[maxn],cnt,dep[maxn],dis[maxn][maxn],el,head[maxn],to[maxn],nxt[maxn];
char s[maxn];
bool eq[maxn][maxn][maxn],vis[maxn];
void clear(){
	FOR(i,1,n) uf[i]=fa[i]=dep[i]=head[i]=vis[i]=0;
	FOR(i,1,n) FOR(j,1,n) dis[i][j]=0;
	FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) eq[i][j][k]=0;
	FOR(i,1,el) to[i]=nxt[i]=0;
	cnt=el=0;
}
inline int getfa(int x){
	return uf[x]?uf[x]=getfa(uf[x]):x;
}
inline void unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x==y) return;
	uf[x]=y;
	cnt++;
}
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
bool dfs(int u,int f,int d,int rt){
	dis[rt][u]=d;
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(vis[v]) return false;
		if(!dfs(v,u,d+1,rt)) return false;
	}
	return true;
}
void solve(){
	n=read();
	FOR(i,1,n){
		FOR(j,i+1,n){
			scanf("%s",s+1);
			FOR(k,1,n) eq[k][i][j]=eq[k][j][i]=s[k]-'0';
		}
	}
	FOR(i,1,n) FOR(j,1,n) eq[i][j][j]=true;
	int mn=n,mx=0;
	FOR(i,1,n){
		FOR(j,1,n) uf[j]=0;
		cnt=0;
		FOR(j,1,n) FOR(k,1,n) if(eq[i][j][k]) unite(j,k);
		dep[i]=n-1-cnt;
		mn=min(mn,dep[i]);
		mx=max(mx,dep[i]);
	}
	if(mn!=(mx+1)/2) NO;
	int x=0,y=0,z=0;
	FOR(i,1,n) if(dep[i]==mn) (x?y?z:y:x)=i;
	if(z) NO;
	if(mx%2){
		fa[x]=y;fa[y]=x;
		FOR(d,mn,mx-1) FOR(i,1,n) if(dep[i]==d){
			FOR(j,1,n) if(j!=fa[i] && eq[i][j][fa[i]]) fa[j]=i;
		}
		fa[x]=0;
	}
	else{
		if(y) NO;
		FOR(i,1,n) if(dep[i]==mn+1) fa[i]=x;
		FOR(d,mn+1,mx-1) FOR(i,1,n) if(dep[i]==d){
			FOR(j,1,n) if(j!=fa[i] && eq[i][j][fa[i]]) fa[j]=i;
		}
	}
	FOR(i,1,n) if(fa[i]) add(fa[i],i),add(i,fa[i]);
	FOR(i,1,n){
		FOR(j,1,n) vis[j]=false;
		if(!dfs(i,0,0,i)) NO;
	}
	bool flag=true;
	FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) if((dis[i][j]==dis[i][k])^eq[i][j][k]) flag=false;
	if(!flag) NO;
	puts("Yes");
	FOR(i,1,n) if(fa[i]) printf("%d %d\n",fa[i],i);
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}
/*
3
3
001 000
000
4
0000 0000 0100 
0001 0000 
0000
6
000000 000000 010000 000000 000010
000100 000000 100000 000000
000000 010000 000000
000000 100000
000000
*/