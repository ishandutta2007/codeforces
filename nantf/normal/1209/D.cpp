#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
int n,k,ans,el,head[maxn],to[maxn],nxt[maxn];
bool vis[maxn];
map<PII,bool> vise;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(vis[v]){
			ans++;continue;
		}
		dfs(v,u);
	}
}
int main(){
	n=read();k=read();
	FOR(i,1,k){
		int x=read(),y=read();
		if(x>y) swap(x,y);
		if(vise[MP(x,y)]) ans+=2;
		else{
			vise[MP(x,y)]=true;
			add(x,y);add(y,x);
		}
	}
	FOR(i,1,n) if(!vis[i]) dfs(i,0);
	printf("%d\n",ans/2);
}
// lian diao san chang NTF cai si le