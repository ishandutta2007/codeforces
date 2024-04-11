#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,el,head[2020],to[maxn],nxt[maxn],q[2020],h=1,r,deg[2020],fa[2020],val[maxn];
char mp[1010][1010];
bool vis[2020];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;deg[v]++;
}
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x!=y) fa[x]=y;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) scanf("%s",mp[i]+1);
	FOR(i,1,n+m) fa[i]=i;
	FOR(i,1,n) FOR(j,1,m) if(mp[i][j]=='=') unite(i,j+n);
	FOR(i,1,n) FOR(j,1,m){
		if(mp[i][j]=='<') add(getfa(i),getfa(j+n));
		if(mp[i][j]=='>') add(getfa(j+n),getfa(i));
	}
	FOR(i,1,n+m) if(i==getfa(i) && !deg[i]) q[++r]=i,val[i]=1,vis[i]=true;
	while(h<=r){
		int u=q[h++];
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]) continue;
			if(!--deg[v]){
				vis[v]=true;
				val[v]=val[u]+1;
				q[++r]=v;
			}
		}
	}
	FOR(i,1,n+m) if(i==getfa(i) && !vis[i]) return puts("NO"),0;
	puts("YES");
	FOR(i,1,n) printf("%d ",val[getfa(i)]);
	puts("");
	FOR(i,1,m) printf("%d ",val[getfa(i+n)]);
}