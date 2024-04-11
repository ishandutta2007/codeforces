#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=5555;
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
int n,m,el,head[maxn],to[maxn],nxt[maxn],id[maxn],ans[maxn],tot=1;
bool vis[maxn],ins[maxn];
inline void add(int u,int v,int w){
	to[++el]=v;nxt[el]=head[u];head[u]=el;id[el]=w;
}
void dfs(int u){
	ins[u]=vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]){
			if(ins[v]) ans[id[i]]=tot=2;
			else ans[id[i]]=1;
		}
		else dfs(v),ans[id[i]]=1;
	}
	ins[u]=false;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v,i);
	}
	FOR(i,1,n) if(!vis[i]) dfs(i);
	printf("%d\n",tot);
	FOR(i,1,m) printf("%d ",ans[i]);
}