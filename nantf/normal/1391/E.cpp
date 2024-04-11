#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222222,mod=998244353;
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
int n,m,el,head[maxn],to[maxn],nxt[maxn],dep[maxn],fa[maxn],p[maxn];
bool vis[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void clear(){
	FOR(i,1,el) to[i]=nxt[i]=0;
	FOR(i,1,n) dep[i]=fa[i]=p[i]=head[i]=vis[i]=0;
	el=0;
}
void dfs(int u,int f){
	vis[u]=true;
	dep[u]=dep[f]+1;
	fa[u]=f;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!vis[v]) dfs(v,u);
	}
}
inline bool cmp(int x,int y){return dep[x]<dep[y];}
void solve(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	FOR(i,1,n) if(dep[i]>=(n+1)/2){
		puts("PATH");
		printf("%d\n",dep[i]);
		while(i) printf("%d ",i),i=fa[i];
		puts("");
		return clear();
	}
	puts("PAIRING");
	FOR(i,1,n) p[i]=i;
	sort(p+1,p+n+1,cmp);
	int cnt=0;
	FOR(i,1,n-1) if(dep[p[i]]==dep[p[i+1]]) cnt++,i++;
	printf("%d\n",cnt);
	FOR(i,1,n-1) if(dep[p[i]]==dep[p[i+1]]) printf("%d %d\n",p[i],p[i+1]),i++;
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}