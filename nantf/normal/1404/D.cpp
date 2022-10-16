#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100,mod=998244353;
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
int n,el,to[maxn*2],nxt[maxn*2],head[maxn],col[maxn],id[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(col[v]!=-1) continue;
		col[v]=col[u]^1;
		dfs(v);
	}
}
int main(){
	n=read();
	if(n%2==0){
		puts("First");
		fflush(stdout);
		FOR(_,0,1) FOR(i,1,n) printf("%d ",i);
		puts("");
		fflush(stdout);
		return 0;
	}
	puts("Second");
	fflush(stdout);
	FOR(i,1,2*n){
		int x=read();
		if(id[x]) add(id[x],i),add(i,id[x]);
		else id[x]=i;
	}
	FOR(i,1,n) add(i,i+n),add(i+n,i);
	FOR(i,1,2*n) col[i]=-1;
	FOR(i,1,2*n) if(col[i]==-1) col[i]=0,dfs(i); 
	int sum=0;
	FOR(i,1,2*n) if(col[i]) sum=(sum+i)%(2*n);
	if(sum){
		FOR(i,1,2*n) if(!col[i]) printf("%d ",i);
	}
	else{
		FOR(i,1,2*n) if(col[i]) printf("%d ",i);
	}
	puts("");
	fflush(stdout);
}
// orz orz orz