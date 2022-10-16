#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1666666,mod=998244353,d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
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
int n,m,*a[maxn],el,head[maxn],to[maxn],nxt[maxn],dfn[maxn],low[maxn],cnt,stk[maxn],tp,id[maxn],scc;
bool ins[maxn],vis[maxn];
char s[maxn];
inline int getid(int x,int y){
	return (x-1)*m+y;
} 
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	dfn[u]=low[u]=++cnt;
	stk[++tp]=u;
	ins[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		scc++;
		do{
			int v=stk[tp];
			id[v]=scc;
			ins[v]=false;
		}while(stk[tp--]!=u);
	}
}
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=new int[m+10];
	FOR(i,1,n) FOR(j,0,m+1) a[i][j]=0; 
	FOR(i,1,n){
		scanf("%s",s+1);
		FOR(j,1,m) if(s[j]=='#') a[i][j]=1;
	}
	FOR(i,1,n) FOR(j,1,m) if(a[i][j]){
		int at=i;
		while(at<=n){
			if(at!=i && a[at][j]) break;
			FOR(k,0,3){
				int x=at+d[k][0],y=j+d[k][1];
				if(x<1 || x>n || y<1 || y>m || !a[x][y]) continue;
				add(getid(i,j),getid(x,y));
			}
			at++;
		} 
	}
	FOR(i,1,n) FOR(j,1,m) if(a[i][j] && !dfn[getid(i,j)]) dfs(getid(i,j));
	FOR(u,1,n*m) if(id[u]) for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(id[v] && id[u]!=id[v]) vis[id[v]]=true;
	}
	int ans=0;
	FOR(i,1,scc) if(!vis[i]) ans++;
	printf("%d\n",ans);
	FOR(i,1,n) delete[] a[i];
}