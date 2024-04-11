#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=500050,mod=998244353;
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
int n,fa[maxn],al,ans[maxn][4];
struct tree{
	int el,head[maxn],to[maxn*2],nxt[maxn*2],fa[maxn];
	inline void add(int u,int v){
		to[++el]=v;nxt[el]=head[u];head[u]=el;
	}
	void dfs(int u,int f){
		fa[u]=f;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(v==f) continue;
			dfs(v,u);
		}
	}
}t1,t2;
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void dfs(int u,int f){
	for(int i=t1.head[u];i;i=t1.nxt[i]){
		int v=t1.to[i];
		if(v==f) continue;
		dfs(v,u);
		if(t2.fa[u]!=v && t2.fa[v]!=u){
			ans[++al][0]=u;
			ans[al][1]=v;
			ans[al][2]=getfa(v);
			ans[al][3]=t2.fa[getfa(v)];
		}
	}
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		t1.add(u,v);t1.add(v,u);
	}
	t1.dfs(1,0);
	FOR(i,1,n-1){
		int u=read(),v=read();
		t2.add(u,v);t2.add(v,u);
	}
	t2.dfs(1,0);
	FOR(i,1,n){
		int f=t2.fa[i];
		if(t1.fa[i]==f || t1.fa[f]==i) fa[i]=f;
		else fa[i]=i;
	}
	dfs(1,0);
	printf("%d\n",al);
	FOR(i,1,al) printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
}