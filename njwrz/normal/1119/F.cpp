#include<bits/stdc++.h>
#define ll long long
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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define sz(x) ((int)x.size())
using namespace std;
const int B=1e6;
int n;
V<P<int,int> > v[250005];
ll dp[250005][2];
int in[250005],fa[250005];
ll ans[250005];
int dep[250005],up[250005];
V<int> ad[250005];
set<P<int,int> > st;
int node[250005],len,vis[250005];
int root[250005];
struct seg{
	ll sum[9000005];
	int siz[9000005],cnt,lc[9000005],rc[9000005];
	void update(int &x,int l,int r,int it,int ad){
		if(!x)x=++cnt;
		sum[x]+=ad*it;siz[x]+=ad;
		if(l==r)RE;
		int mid=(l+r)>>1;
		if(mid>=it)update(lc[x],l,mid,it,ad);
		else update(rc[x],mid+1,r,it,ad);
	}
	ll get(int x,int l,int r,int k){
		if(!k)RE 0;
		if(l==r)RE 1ll*l*k;
		int mid=(l+r)>>1;
		if(siz[lc[x]]>=k){
			RE get(lc[x],l,mid,k);
		}else RE sum[lc[x]]+get(rc[x],mid+1,r,k-siz[lc[x]]);
	}
}T;
void dfs(int x,int y){
	for(auto u:v[x])if(u.F!=y){
		fa[u.F]=x;dep[u.F]=dep[x]+1;dp[u.F][1]=u.S;up[u.F]=u.S;
		T.update(root[x],0,B,u.S,1);
		dfs(u.F,x);
	}
}
ll sum=0;
int nowin;
void update(int x){
	int res=in[x]-nowin;
	sum-=dp[x][0];
	if(fa[x])T.update(root[fa[x]],0,B,dp[x][1]-dp[x][0],-1);
	dp[x][0]=T.get(root[x],0,B,res);
	if(x!=1){
		dp[x][1]=T.get(root[x],0,B,res-1)+up[x];
		gmin(dp[x][0],dp[x][1]);
	}
	if(fa[x])T.update(root[fa[x]],0,B,dp[x][1]-dp[x][0],1);
	sum+=dp[x][0];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ll s=0;
	FOR(i,2,n){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
		s+=z;
	}
	FOR(i,1,n)in[i]=v[i].size(),ad[in[i]-1].PB(i);
	dfs(1,-1);
	for(int i=n-1;i>=1;i--){
		nowin=i;
		for(auto u:ad[i])st.emplace(MP(-dep[u],u)),vis[u]=1;
		len=0;
		for(auto u:st)node[++len]=u.S;
		FOR(j,1,len)update(node[j]);
		ans[i]=sum;
	}
	ans[0]=s;
	rep(i,0,n)cout<<ans[i]<<' ';
	RE 0;
}