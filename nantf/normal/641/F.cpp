#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222,mod=998244353;
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
int n,m1,m2;
struct twosat{
	bitset<maxn> e[maxn];
	int in[maxn];
	inline void add(int u,int v){
		e[u][v]=true;
	}
	void floyd(){
		FOR(i,2,2*n+1) e[i][i]=true;
		FOR(k,2,2*n+1) FOR(i,2,2*n+1) if(e[i][k]) e[i]|=e[k];
	}
	void work(){
		floyd();
		FOR(i,2,2*n+1) if(e[i][i^1]) FOR(j,2,2*n+1) add(i,j),add(j,i^1);
		floyd();
	}
	void dfs(int u){
		if(in[u]) return;
		in[u]=1;in[u^1]=-1;
		FOR(v,2,2*n+1) if(e[u][v]) dfs(v);
	}
	void solve(int x,int y){
		dfs(x);dfs(y);
		FOR(i,1,n) if(!in[2*i]){
			if(e[2*i][2*i+1]) dfs(2*i+1);
			else dfs(2*i);
		}
		FOR(i,1,n) printf("%d ",in[2*i]==1?0:1);
	}
}f,g;
int main(){
	n=read();m1=read();m2=read();
	while(m1--){
		int u=read(),v=read();
		u=u>0?2*u:-2*u+1;
		v=v>0?2*v:-2*v+1;
		f.add(u,v^1);f.add(v,u^1);
	}
	f.work();
	while(m2--){
		int u=read(),v=read();
		u=u>0?2*u:-2*u+1;
		v=v>0?2*v:-2*v+1;
		g.add(u,v^1);g.add(v,u^1);
	}
	g.work();
	FOR(i,2,2*n+1) FOR(j,2,2*n+1) if(f.e[i][j]^g.e[i][j] && i!=j){
		if(f.e[i][j]) return g.solve(i,j^1),0;
		else return f.solve(i,j^1),0;
	}
	puts("SIMILAR");
}