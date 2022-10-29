#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
typedef unsigned long long ull;
const int N=1e5+9;
const ll mod=998244353;
vi g[N];
ull seed[N<<1],hu[N],hu2[N];
map<ull,int> id;
int cnt,ansp,maxn,tot,hp[N],hp2[N],sum[N<<1];
void dfs(int u,int f){
	hu[u]=seed[0];
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
		hu[u]+=seed[hp[v]]; 
	}
	if(!id.count(hu[u]))id[hu[u]]=++tot;
	hp[u]=id[hu[u]];
}
void dfs2(int u,int f){
	ull h=hu[u];
	if(f)h+=seed[hp2[u]];
	for(auto v:g[u]){
		if(v==f)continue;
		hu2[v]=h-seed[hp[v]];
		if(!id.count(hu2[v]))id[hu2[v]]=++tot;
		hp2[v]=id[hu2[v]];
		dfs2(v,u);
	}
}
void dfs3(int u,int f){
	if(cnt>maxn){
		maxn=cnt,ansp=u;
	}
	for(auto v:g[u]){
		if(v==f)continue;
		cnt-=!(--sum[hp[v]]);
		cnt+=!(sum[hp2[v]]++);
		dfs3(v,u);
		cnt-=!(--sum[hp2[v]]);
		cnt+=!(sum[hp[v]]++);
	}
}
int main(){
	rep(i,0,N<<1)seed[i]=((ull)rand()<<40)+((ull)rand()<<20)+rand();
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,0);
	dfs2(1,0);
	rep(i,1,n+1)cnt+=!(sum[hp[i]]++);
	maxn=cnt,ansp=1;
	dfs3(1,0);
	printf("%d",ansp);
}