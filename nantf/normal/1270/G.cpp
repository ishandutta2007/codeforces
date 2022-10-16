#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000100;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	char ch=getchar();bool f=false;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int t,n,el,head[maxn],to[maxn],nxt[maxn],stk[maxn],tp,ans[maxn],al;
bool vis[maxn],ins[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	vis[u]=ins[u]=true;
	stk[++tp]=u;
	if(vis[to[u]]){
		if(ins[to[u]] && !al){
			ROF(i,tp,1){
				ans[++al]=stk[i];
				if(stk[i]==to[u]) break;
			}
		}
	}
	else dfs(to[u]);
	ins[u]=false;
	stk[tp--]=0;
}
int main(){
	read(t);
	while(t--){
		read(n);
		FOR(i,1,n){
			int x;
			read(x);
			add(i,i-x);
		}
		FOR(i,1,n) if(!vis[i]) dfs(i);
		printf("%d\n",al);
		FOR(i,1,al) printf("%d ",ans[i]);
		puts("");
		FOR(i,1,n) head[i]=vis[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=0;
		el=al=0;
	}
	return 0;
}