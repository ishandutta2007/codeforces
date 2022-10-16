#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
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
int n,m,fa[maxn];
struct edge{
	int u,v,w;
	bool operator<(const edge &e)const{return w<e.w;}
}e[maxn];
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x!=y) fa[x]=y;
}
namespace sub1{
	set<int> s[maxn],res; 
	int q[maxn],h,r;
	void bfs(int st){
		q[h=r=1]=st;
		while(h<=r){
			int u=q[h++];
			auto it=res.begin();
			while(it!=res.end()){
				int v=*it;
				if(s[u].find(v)!=s[u].end()){it++;continue;}
				auto it1=it;
				it1++;
				res.erase(it);
				it=it1;
				q[++r]=v;
				unite(u,v);
			}
		}
	}
	int main(){
		FOR(i,1,m){
			int u=read(),v=read(),w=read();
			e[i]=(edge){u,v,w};
			s[u].insert(v);s[v].insert(u);
		}
		FOR(i,1,n) res.insert(i),fa[i]=i;
		FOR(i,1,n) if(res.find(i)!=res.end()) res.erase(i),bfs(i); 
		sort(e+1,e+m+1);
		ll ans=0;
		FOR(i,1,m){
			int u=e[i].u,v=e[i].v;
			u=getfa(u);v=getfa(v);
			if(u==v) continue;
			fa[u]=v;
			ans+=e[i].w;
		}
		printf("%lld\n",ans);
		return 0;
	}
}
namespace sub2{
	int el;
	edge ee[maxn];
	bool vis[666][666];
	ll mst(int ban){
		FOR(i,1,n) fa[i]=i;
		ll ans=0;
		FOR(i,1,el) if(i!=ban){
			int u=ee[i].u,v=ee[i].v;
			u=getfa(u);v=getfa(v);
			if(u==v) continue;
			fa[u]=v;
			ans+=ee[i].w;
		}
		return ans;
	}
	int main(){
		int xs=0;
		FOR(i,1,m){
			int u=read(),v=read(),w=read();
			e[i]=(edge){u,v,w};
			vis[u][v]=vis[v][u]=true;
			xs^=w;
		}
		sort(e+1,e+m+1);
		FOR(i,1,n) fa[i]=i;
		FOR(i,1,n) FOR(j,i+1,n) if(!vis[i][j]) ee[++el]=(edge){i,j,0};
		int tot=el;
		FOR(i,1,m){
			int u=e[i].u,v=e[i].v;
			u=getfa(u);v=getfa(v);
			if(u==v) continue;
			ee[++el]=e[i];
			fa[u]=v;
		}
		ll ans=mst(0)+xs;
		FOR(i,1,tot) ans=min(ans,mst(i));
		printf("%lld\n",ans);
		return 0;
	}
}
int main(){
	n=read();m=read();
	if(1ll*n*(n-1)/2-m>=n) return sub1::main();
	else return sub2::main();
}