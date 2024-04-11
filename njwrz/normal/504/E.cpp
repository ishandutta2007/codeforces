#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define ll long long
#define lb long double
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,Q; 
V<int> v[300005];
char c[300005];
int l2[300005],dep[300005];
int top[300005];
V<int> up[300005],down[300005];
int son[300005],tod[300005];
int fa[300005][20];
void dfs(int x,int y){
	for(auto u:v[x])if(u!=y){
		dep[u]=dep[x]+1;
		fa[u][0]=x;
		dfs(u,x);
		if(tod[u]>tod[son[x]])son[x]=u;
	}
	tod[x]=tod[son[x]]+1;
}
void dfs(int x,int y,int tp){
	top[x]=tp;
	if(x==tp){
		int now=x;
		FOR(i,1,tod[x]){
			down[x].PB(now);
			now=son[now];
		}
		now=x;
		FOR(i,1,tod[x]){
			up[x].PB(now);
			now=fa[now][0];
		} 
	}
	if(son[x])dfs(son[x],x,tp);
	for(auto u:v[x])if(u!=son[x]&&u!=y)dfs(u,x,u);
}
int get(int x,int k){
	if(k==0)RE x;
	int t=l2[k];
	int now=top[fa[x][t]];
	if(dep[now]>=dep[x]-k){
		RE up[now][dep[now]-dep[x]+k];
	}else RE down[now][dep[x]-k-dep[now]];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y];
	rep(i,0,20)if(t&(1<<i))x=fa[x][i];
	if(x==y)RE x;
	for(int i=19;i>=0;i--)if(fa[x][i]!=fa[y][i]){
		x=fa[x][i];
		y=fa[y][i];
	}
	RE fa[x][0];
}
struct hash{
	int val1[300005],val2[300005],p37[300005],mod,finv[300005];
	int POW(int x,int y){
		int re=1;
		while(y){
			if(y&1)re=1ll*re*x%mod;
			x=1ll*x*x%mod;
			y=y/2;
		}
		RE re;
	}
	void dfs(int x,int y){
		val1[x]=(val1[x]+1ll*p37[dep[x]]*(c[x]-'a'))%mod;
		for(auto u:v[x])if(u!=y){
			val2[u]=(1ll*val2[x]*37+c[u]-'a')%mod;
			val1[u]=val1[x];
			dfs(u,x);
		}
	}
	void init(int x){
		p37[0]=1;mod=x;
		FOR(i,1,n)p37[i]=p37[i-1]*37ll%mod;
		finv[0]=1;finv[1]=POW(37,mod-2);
		FOR(i,2,n)finv[i]=1ll*finv[i-1]*finv[1]%mod;
		val2[1]=c[1]-'a';
		dfs(1,-1);
	}
	int check(int x,int mid,int y,int k){
		int re=val2[x];
		if(dep[x]-dep[mid]>=k){
			RE (re-1ll*val2[get(x,k)]*p37[k]%mod+mod)%mod;
		}
		re=(re-1ll*val2[mid]*p37[dep[x]-dep[mid]]%mod+mod)%mod;
		int ed=get(y,dep[x]+dep[y]-dep[mid]*2+1-k);
		re=(re+1ll*(val1[ed]-val1[fa[mid][0]]+mod)*finv[dep[mid]]%mod*p37[dep[x]-dep[mid]])%mod;
		RE re;
	}
}T;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,2,n)l2[i]=l2[i/2]+1;
	FOR(i,1,n)cin>>c[i];
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	rep(i,1,20)FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	dfs(1,-1,1);
	T.init(998244353);
	int Q;
	cin>>Q;
	FOR(_,1,Q){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int t1=lca(a,b),t2=lca(c,d);
		int l=1,r=min(dep[a]+dep[b]-dep[t1]*2,dep[c]+dep[d]-dep[t2]*2)+1,mid=0,ans=0;
		while(r>=l){
			int mid=(l+r)>>1;
			if(T.check(a,t1,b,mid)==T.check(c,t2,d,mid)){
				ans=mid;l=mid+1;
			}else r=mid-1;
		}
		cout<<ans<<'\n';
	}
	RE 0;
}