#include<bits/stdc++.h>
using namespace std;
const int maxn=2555555;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,q,k[1111],m[1111],e[1111][10],to[maxn],stk[maxn],tp,seq[maxn],sl,cnt[1111],ans[maxn];
bool vis[maxn],ins[maxn];
inline int id(int x,int y){return (x-1)*2520+y;}
inline void add(int u,int v){to[u]=v;}
inline void dfs(int u){
	if(vis[u]) return;
	stk[++tp]=u;
	vis[u]=ins[u]=true;
	if(!ins[to[u]]) dfs(to[u]),ans[u]=ans[to[u]];
	else{
		sl=0;
		ROF(i,tp,1){
			seq[++sl]=stk[i];
			if(stk[i]==to[u]) break;
		}
		int sss=0;
		FOR(i,1,sl) if(++cnt[seq[i]/2520]==1) sss++;
		ans[u]=sss;
		FOR(i,1,sl) cnt[seq[i]/2520]=0;
	}
	tp--;
	ins[u]=false;
}
int main(){
	n=read();
	FOR(i,1,n) k[i]=(read()%2520+2520)%2520;
	FOR(i,1,n){
		m[i]=read();
		FOR(j,0,m[i]-1) e[i][j]=read();
	}
	FOR(i,1,n) FOR(j,0,2519) add(id(i,j),id(e[i][(j+k[i])%m[i]],(j+k[i])%2520));
	FOR(i,1,n) FOR(j,0,2519) dfs(id(i,j));
	q=read();
	while(q--){
		int x=read(),y=(read()%2520+2520)%2520;
		printf("%d\n",ans[id(x,y)]);
	}
}