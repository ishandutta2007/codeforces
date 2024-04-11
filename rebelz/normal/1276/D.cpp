#include<bits/stdc++.h>
 
#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n;
ll d[200005][5],pre[200005],suf[200005];
vector<pii> adj[200005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

//0:  1:  2:  
void dfs(int u,int fa,int c){
	if(adj[u].size()==1&&fa>0){
		d[u][0]=0,d[u][1]=1,d[u][2]=1;
		return;
	}
	ll ans0=1,ans1=1;
	for(auto tmp:adj[u]){
		int v=tmp.fi,nc=tmp.se;
		if(v==fa) continue;
		dfs(v,u,nc);
		if(nc<c) ans0=ans0*(d[v][0]+d[v][2])%cys;
		else ans1=ans1*(d[v][0]+d[v][1])%cys;
	}
	for(int i=0;i<adj[u].size();i++){
		if(adj[u][i].fi==fa) pre[i+1]=pre[i];
		else pre[i+1]=pre[i]*(d[adj[u][i].fi][0]+d[adj[u][i].fi][2])%cys;
	}
	suf[adj[u].size()]=1;
	for(int i=adj[u].size()-1;i>=0;i--){
		if(adj[u][i].fi==fa) suf[i]=suf[i+1];
		else suf[i]=suf[i+1]*(d[adj[u][i].fi][0]+d[adj[u][i].fi][1])%cys;
	}
	for(int i=0;i<adj[u].size();i++) if(adj[u][i].se>c) d[u][1]=(d[u][1]+pre[i]*d[adj[u][i].fi][1]%cys*suf[i+1])%cys;
	for(int i=0;i<adj[u].size();i++) if(adj[u][i].se<c) d[u][0]=(d[u][0]+pre[i]*d[adj[u][i].fi][1]%cys*suf[i+1])%cys;
	d[u][1]=mod(d[u][1]+pre[adj[u].size()]);
	d[u][2]=ans0*ans1%cys;
}

int main(){
	n=readint();
	int x,y;
	for(int i=1;i<n;i++){
		x=readint(); y=readint();
		adj[x].push_back(mp(y,i)); adj[y].push_back(mp(x,i));
	}
	pre[0]=1;
	dfs(1,-1,1<<30);
	printf("%lld\n",mod(d[1][0]+d[1][1]));
	return 0;
}