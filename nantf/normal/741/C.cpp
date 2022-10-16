#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=266666,mod=998244353;
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
int n,x[maxn],y[maxn],to[maxn][2],ans[maxn];
void dfs(int u){
	FOR(i,0,1){
		int v=to[u][i];
		if(!ans[v]) ans[v]=3-ans[u],dfs(v);
	}
}
int main(){
	n=read();
	FOR(i,1,n) to[2*i-1][0]=2*i,to[2*i][0]=2*i-1;
	FOR(i,1,n){
		x[i]=read(),y[i]=read();
		to[x[i]][1]=y[i];to[y[i]][1]=x[i];
	}
	FOR(i,1,2*n) if(!ans[i]) ans[i]=1,dfs(i);
	FOR(i,1,n) printf("%d %d\n",ans[x[i]],ans[y[i]]);
}