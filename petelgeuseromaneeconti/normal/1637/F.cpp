#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
const int N=200005,K=20;
int n,h[N],fa[N][K],dep[N],id[N];
vector<int>e[N];
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int dt=dep[u]-dep[v];
	per(i,K-1,0)if(dt>>i&1)u=fa[u][i];
	if(u==v)return u;
	per(i,K-1,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int ind,tin[N],tou[N];
void dfs1(int k1,int k2){
	tin[k1]=++ind;
	fa[k1][0]=k2,dep[k1]=dep[k2]+1;
	rep(i,1,K-1)fa[k1][i]=fa[fa[k1][i-1]][i-1];
	each(x,e[k1])if(x!=k2)dfs1(x,k1);
	tou[k1]=ind;
}
vector<int>nd;
bool dfs2(int k1,int k2,int tar){
	if(k1==tar)return nd.pb(k1),1;
	each(x,e[k1])if(x!=k2&&dfs2(x,k1,tar))return nd.pb(k1),1;
	return 0;
}
bool in_sub(int u,int v){ // u  v 
	return tin[v]<=tin[u]&&tin[u]<=tou[v];
}
int mx[N];
bool vis[N];
long long ans;
void dfs3(int k1,int k2){
	each(x,e[k1])if(x!=k2&&!vis[x]){
		dfs3(x,k1);
		mx[k1]=max(mx[k1],mx[x]);
	}
	if(mx[k1]<h[k1])ans+=h[k1]-mx[k1],mx[k1]=h[k1];
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n)rd(h[i]);
	rep(i,2,n){
		int u,v;
		rd(u),rd(v);
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	iota(id+1,id+n+1,1);
	sort(id+1,id+n+1,[&](int lhs,int rhs){return tie(h[lhs],lhs)>tie(h[rhs],rhs);});
	int l,r;
	auto ps=[&](int u){
		int a[3]={l,r,u};
		sort(a,a+3,[&](int lhs,int rhs){return tin[lhs]<tin[rhs];});
		if(a[0]==a[1]||a[1]==a[2]){
			l=a[0],r=a[2];
			return 1;
		}
		int t=LCA(LCA(a[0],a[1]),a[2]);
		if(a[0]==t){
			if(LCA(a[1],a[2])==t){
				l=a[1],r=a[2];
				return 1;
			}
			if(!in_sub(a[2],a[1]))return 0;
			l=a[0],r=a[2];
			return 1;
		}else{
			if(in_sub(a[1],a[0])){
				l=a[1],r=a[2];
				return 1;
			}
			if(!in_sub(a[2],a[1]))return 0;
			l=a[0],r=a[2];
			return 1;
		}
	};
	ans+=h[id[1]]*2;
	l=r=id[1];
	rep(i,2,n)ps(id[i]);
	dfs2(l,0,r);
	each(x,nd)vis[x]=1;
	each(k1,nd)each(x,e[k1])if(!vis[x])dfs3(x,0);
	printf("%lld\n",ans);
	return 0;
}