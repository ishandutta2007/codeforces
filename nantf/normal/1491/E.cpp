#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
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
int n,el=1,head[maxn],to[maxn],nxt[maxn],fib[maxn],sz[maxn],id[maxn],il;
bool bl[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int dep,int u,int f){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || bl[i]) continue;
		dfs(dep,v,u);
		sz[u]+=sz[v];
		if(sz[v]==fib[dep-1] || sz[v]==fib[dep-2]) id[++il]=i;
	}
}
bool work(int dep,int rt){
//	printf("work(%d,%d)\n",dep,rt);
	if(dep<=2) return true;
	il=0;
	dfs(dep,rt,0);
//	printf("il=%d\n",il);
	if(il>2 || !il) return false;
	int e1=id[1],e2=id[2];
	int u1=to[e1],v1=to[e1^1],tp1=sz[u1]==fib[dep-1]?0:1;
	int u2=to[e2],v2=to[e2^1],tp2=sz[u2]==fib[dep-1]?0:1;
	if(il==1){
		bl[e1]=bl[e1^1]=true;
		bool ans=false;
		if(tp1) ans=work(dep-2,u1)&work(dep-1,v1);
		else ans=work(dep-1,u1)&work(dep-2,v1);
		bl[e1]=bl[e1^1]=false;
		return ans;
	}
	else{
		bl[e1]=bl[e1^1]=true;
		bl[e2]=bl[e2^1]=true;
		bool ans=false;
		ans=work(dep-2,tp1?u1:v1)&work(dep-2,tp2?u2:v2)&work(dep-3,tp1?v1:u1);
		bl[e1]=bl[e1^1]=false;
		bl[e2]=bl[e2^1]=false;
		return ans;
	}
	return false;
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	fib[0]=fib[1]=1;
	FOR(i,2,30) fib[i]=fib[i-1]+fib[i-2];
	FOR(i,1,30) if(fib[i]==n) return puts(work(i,1)?"YES":"NO"),0;
	puts("NO");
}