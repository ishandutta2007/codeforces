#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222,MAXN=maxn*maxn*2,MAXM=maxn*maxn*16,mod=998244353;
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
int n,m,s,t,tot,el=1,head[MAXN],cur[MAXN],to[MAXM],nxt[MAXM],flow[MAXM],q[MAXN],h,r,dis[MAXN],cnt;
char mp1[maxn][maxn],mp2[maxn][maxn],mp[maxn][maxn];
inline void add(int u,int v,int w){
	to[++el]=v;nxt[el]=head[u];head[u]=el;flow[el]=w;
	to[++el]=u;nxt[el]=head[v];head[v]=el;flow[el]=0;
}
inline int id(int x,int y){return (x-1)*m+y;}
bool bfs(){
	FOR(i,1,tot) dis[i]=-1,cur[i]=head[i];
	dis[s]=0;
	q[h=r=1]=s;
	while(h<=r){
		int u=q[h++];
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]==-1 && flow[i]){
				dis[v]=dis[u]+1;
				q[++r]=v;
			}
		}
	}
	return ~dis[t];
}
int dfs(int u,int minres){
	if(u==t || !minres) return minres;
	int f,rtf=0;
	for(int &i=cur[u];i;i=nxt[i]){
		int v=to[i];
		if(dis[v]==dis[u]+1 && (f=dfs(v,min(flow[i],minres)))){
			flow[i]-=f;flow[i^1]+=f;
			rtf+=f;minres-=f;
			if(!minres) break;
		}
	}
	return rtf;
}
int dinic(){
	int mxf=0;
	while(bfs()) mxf+=dfs(s,1e9);
	return mxf;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) scanf("%s",mp[i]+1);
	FOR(i,1,n) FOR(j,1,m) mp1[i][j]=mp2[i][j]='0';
	FOR(i,1,n) FOR(j,1,m) if(mp[i][j]=='.'){
		if(i!=1) mp2[i-1][j]='1';
		if(i!=n) mp2[i][j]='1';
		if(j!=1) mp1[i][j-1]='1';
		if(j!=m) mp1[i][j]='1';
	}
	else cnt++;
	FOR(i,1,n) FOR(j,1,m-1) if(mp1[i][j]=='0'){
		if(i!=1){
			if(mp2[i-1][j]=='0') add(id(i,j),n*m+id(i-1,j),1);
			if(mp2[i-1][j+1]=='0') add(id(i,j),n*m+id(i-1,j+1),1); 
		}
		if(i!=n){
			if(mp2[i][j]=='0') add(id(i,j),n*m+id(i,j),1);
			if(mp2[i][j+1]=='0') add(id(i,j),n*m+id(i,j+1),1);
		}
		cnt--;
	}
	FOR(i,1,n-1) FOR(j,1,m) if(mp2[i][j]=='0') cnt--;
	s=2*n*m+1;t=tot=2*n*m+2;
	FOR(i,1,n*m) add(s,i,1);
	FOR(i,n*m+1,2*n*m) add(i,t,1); 
	printf("%d\n",cnt+dinic());
}
// 2800+ out of range