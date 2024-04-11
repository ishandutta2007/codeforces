#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666,mod=998244353;
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,m,q;
ll dis[maxn][maxn],lim[maxn][maxn],W[maxn][maxn],l[maxn][maxn];
bool ok[maxn][maxn];
int main(){
	n=read();m=read();
	FOR(i,1,n) FOR(j,1,n) W[i][j]=1e18;
	FOR(i,1,m){
		int U=read(),V=read();
		W[U][V]=W[V][U]=read();
	}
	FOR(i,1,n) FOR(j,1,n) dis[i][j]=W[i][j];
	FOR(i,1,n) dis[i][i]=0;
	FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	q=read();
	FOR(i,1,q){
		int u=read(),v=read();
		l[u][v]=l[v][u]=read();
	}
//	FOR(i,1,n) FOR(j,1,n) lim[i][j]=1e18;
	FOR(U,1,n) FOR(u,1,n) FOR(v,1,n)
		if(u!=v) lim[v][U]=max(lim[v][U],l[u][v]-dis[u][U]);
	FOR(v,1,n) FOR(U,1,n) FOR(V,1,n)
		if(U!=V && dis[V][v]+W[U][V]<=lim[v][U]) ok[U][V]=true; 
	int ans=0;
	FOR(u,1,n) FOR(v,u+1,n) if(ok[u][v]) ans++;
	printf("%d\n",ans);
}