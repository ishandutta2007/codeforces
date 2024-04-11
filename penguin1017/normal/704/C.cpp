#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=1<<21;
const ll mod=1e9+7;
const ll Inf=1e18;
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
int jie[N],inv[N];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
vi g[N];
int vis[N],rev[N];
bool vis2[N];
int A[2],B[2],dp[N][2][2][2],deg[N]; 
int T,it[N];
void add(int u,bool rev1){
	u=abs(u);
	vis2[u]=1;
	if(vis[u])g[u<<1].pb(u<<1|1),g[u<<1|1].pb(u<<1),rev[u<<1|1]=rev1,deg[u<<1]++,deg[u<<1|1]++;
	else vis[u]=1,rev[u<<1]=rev1;
}
void add(int u,int v,bool rev1,bool rev2){
	u=abs(u),v=abs(v);
	vis2[u]=1,vis2[v]=1;
	if(u==v){
		it[u]=1;
		B[0]=B[1]=0;
		rep(i,0,2)B[(i^rev1)|(i^rev2)]++;
		B[0]=add(B[0],B[1]);
		B[1]=sub(B[0],mul(2,B[1]));
		A[0]=mul(A[0],B[0]);
		A[1]=mul(A[1],B[1]);
		return; 
	}
	if(vis[u])g[u<<1].pb(u<<1|1),g[u<<1|1].pb(u<<1),rev[u<<1|1]=rev1,deg[u<<1]++,deg[u<<1|1]++,u=u<<1|1;
	else vis[u]=1,rev[u<<1]=rev1,u=u<<1;
	if(vis[v])g[v<<1].pb(v<<1|1),g[v<<1|1].pb(v<<1),rev[v<<1|1]=rev2,deg[v<<1]++,deg[v<<1|1]++,v=v<<1|1;
	else vis[v]=1,rev[v<<1]=rev2,v=v<<1;
	g[u].pb(v);
	g[v].pb(u);
	deg[u]++,deg[v]++;
	
}
int val[N];
bool FLAG;
void dfs(int u,int f){
	vis[u]=T;
	int ok=1; 
	for(auto v:g[u]){
		if(v==f)continue;
		if(vis[v^1]==T&&(u!=(v^1))){
			FLAG=1;
			ok=2;
			rep(i,0,2)rep(j,0,2)rep(k,0,2)B[i^(k|(rev[v]^val[v>>1]))]=add(B[i^(k|(rev[v]^val[v>>1]))],dp[u][i][j][k]);
		}
		else{
			ok=0;
			if(u==(v^1)){
				rep(i,0,2)rep(j,0,2)rep(k,0,2)dp[v][i][j][k]=0;
				rep(i,0,2)rep(j,0,2)rep(k,0,2)dp[v][i^(j|k)][0][k^rev[u]^rev[v]]=add(dp[v][i^(j|k)][0][k^rev[u]^rev[v]],dp[u][i][j][k]);
			}
			else{
				rep(i,0,2)rep(j,0,2)rep(k,0,2)dp[v][i][j][k]=0;
				rep(i,0,2)rep(j,0,2)rep(k,0,2)dp[v][i][j][k]=add(dp[v][i][j][k],dp[u][i][0][j]);
			}
			dfs(v,u);
			if(FLAG)return;
		}
	}
	if(ok==1){
		rep(i,0,2)rep(j,0,2)rep(k,0,2)B[i^(j|k)]=add(B[i^(j|k)],dp[u][i][j][k]);
	}
}
int main(){
	pre();
	A[0]=A[1]=1;
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n){
		int k;
		scanf("%d",&k);
		if(k==1){
			int u;
			scanf("%d",&u);
			add(u,u<0);
		}
		else {
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v,u<0,v<0);
		}
	}
	memset(vis,0,sizeof vis);
	rep(i,1,m+1){
		if(!vis[i<<1]&&deg[i<<1]==1){
			B[0]=B[1]=0;
			++T;
			FLAG=0;
			val[i]=0;
			rep(j,0,2)rep(k,0,2)rep(_,0,2)dp[i<<1][j][k][_]=0;
			dp[i<<1][0][0][0^rev[i<<1]]=1;
			dfs(i<<1,0);
			++T;
			FLAG=0;
			val[i]=1;
			rep(j,0,2)rep(k,0,2)rep(_,0,2)dp[i<<1][j][k][_]=0;
			dp[i<<1][0][0][1^rev[i<<1]]=1;
			dfs(i<<1,0);
			B[0]=add(B[0],B[1]);
			B[1]=sub(B[0],mul(2,B[1]));
			A[0]=mul(A[0],B[0]);
			A[1]=mul(A[1],B[1]);
		}
		if(!vis[i<<1|1]&&deg[i<<1|1]==1){
			B[0]=B[1]=0;
			++T;
			FLAG=0;
			val[i]=0;
			rep(j,0,2)rep(k,0,2)rep(_,0,2)dp[i<<1|1][j][k][_]=0;
			dp[i<<1|1][0][0][0^rev[i<<1|1]]=1;
			dfs(i<<1|1,0);
			++T;
			FLAG=0;
			val[i]=1;
			rep(j,0,2)rep(k,0,2)rep(_,0,2)dp[i<<1|1][j][k][_]=0;
			dp[i<<1|1][0][0][1^rev[i<<1|1]]=1;
			dfs(i<<1|1,0);
			B[0]=add(B[0],B[1]);
			B[1]=sub(B[0],mul(2,B[1]));
			A[0]=mul(A[0],B[0]);
			A[1]=mul(A[1],B[1]);
		}
	}
	rep(i,1,m+1){
		if(!vis[i<<1]&&vis2[i]&&!it[i]){
			B[0]=B[1]=0;
			++T;
			FLAG=0;
			val[i]=0;
			rep(j,0,2)rep(k,0,2)rep(_,0,2)dp[i<<1][j][k][_]=0;
			dp[i<<1][0][0][0^rev[i<<1]]=1;
			dfs(i<<1,0);
			++T;
			FLAG=0;
			val[i]=1;
			rep(j,0,2)rep(k,0,2)rep(_,0,2)dp[i<<1][j][k][_]=0;
			dp[i<<1][0][0][1^rev[i<<1]]=1;
			dfs(i<<1,0);
			B[0]=add(B[0],B[1]);
			B[1]=sub(B[0],mul(2,B[1]));
			A[0]=mul(A[0],B[0]);
			A[1]=mul(A[1],B[1]);
		}
	}
	A[1]=mul(inv[2],sub(A[0],A[1]));
	rep(i,1,m+1)if(!vis2[i])A[1]=mul(A[1],2);
	printf("%d\n",A[1]);
}
/*
6 6
2 1 2
2 2 3
2 1 3
2 4 5 
2 5 6
2 6 4
*/