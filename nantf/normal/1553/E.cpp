#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int n,m,p[maxn],c[maxn],q[maxn],ans[maxn],al;
bool vis[maxn];
void clear(){
	FOR(i,0,n-1) c[i]=0;
	al=0;
}
void dfs(int u){
	vis[u]=true;
	if(!vis[q[u]]) dfs(q[u]);
}
void solve(){
	read(n);read(m);
	FOR(i,1,n) read(p[i]),c[(i-p[i]+n)%n]++;
	FOR(i,0,n-1) if(c[i]>=n/3){
		FOR(j,1,n) q[j]=(p[j]+i-1)%n+1;
		int tot=0;
		FOR(j,1,n) if(!vis[j]) tot++,dfs(j);
		FOR(j,1,n) vis[j]=false;
		if(tot>=n-m) ans[++al]=i;
	}
	printf("%d ",al);
	FOR(i,1,al) printf("%d ",ans[i]);
	puts("");
	clear();
}
int main(){
	int T;
	read(T);
	while(T--) solve();
}