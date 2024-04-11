#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=55,mod=998244353;
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
int n,f[maxn][maxn][maxn][maxn],pre[maxn][maxn];
char mp[maxn][maxn];
int sum(int xl,int yl,int xr,int yr){
	return pre[xr][yr]-pre[xr][yl-1]-pre[xl-1][yr]+pre[xl-1][yl-1];
}
int dfs(int xl,int yl,int xr,int yr){
	if(sum(xl,yl,xr,yr)<=0) return 0;
	if(f[xl][yl][xr][yr]) return f[xl][yl][xr][yr];
	f[xl][yl][xr][yr]=1e9;
	FOR(i,xl,xr-1) f[xl][yl][xr][yr]=min(f[xl][yl][xr][yr],dfs(xl,yl,i,yr)+dfs(i+1,yl,xr,yr));
	FOR(i,yl,yr-1) f[xl][yl][xr][yr]=min(f[xl][yl][xr][yr],dfs(xl,yl,xr,i)+dfs(xl,i+1,xr,yr));
	if(xr-xl<yr-yl) f[xl][yl][xr][yr]=min(f[xl][yl][xr][yr],min(dfs(xl,yl+xr-xl+1,xr,yr),dfs(xl,yl,xr,yr-xr+xl-1))+xr-xl+1);
	else f[xl][yl][xr][yr]=min(f[xl][yl][xr][yr],min(dfs(xl+yr-yl+1,yl,xr,yr),dfs(xl,yl,xr-yr+yl-1,yr))+yr-yl+1);
	return f[xl][yl][xr][yr];
}
int main(){
	n=read();
	FOR(i,1,n) scanf("%s",mp[i]+1);
	FOR(i,1,n) FOR(j,1,n){
		pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
		if(mp[i][j]=='#') pre[i][j]++;
	}
	printf("%d\n",dfs(1,1,n,n));
}