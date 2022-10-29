#include<bits/stdc++.h>
//#undef _GLIBCXX_HAVE_ICONV
//#include<bits/extc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
//using namespace __gnu_pbds;
const int N=1<<21;
const int mod=998244353;
const ll Inf=1e18;
/*
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
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int jie[N],inv[N];
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
*/
int n,m;
ll dis[N];
int id(int i,int j,int k){
	--i;
	return i*4+j*2+k; 	
} 
vector<pii> g[N];
bool vis[N];
priority_queue <pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > PQ;
void dij(){
	int s=id(1,0,0);
	rep(i,0,N)dis[i]=Inf;
	dis[s]=0;
	PQ.push({0,s});
	while(PQ.size()){
		auto w=PQ.top();
		PQ.pop();
		ll d=w.fi,u=w.se;
		if(vis[w.se])continue;
	//	cout<<u<<' '<<dis[u]<<"u\n";
		vis[w.se]=1;
		for(auto _:g[u]){
			int v=_.fi;
			if(vis[v])continue;
			if(dis[v]>d+_.se){
				dis[v]=d+_.se;
			//	cout<<v<<' '<<dis[v]<<"v\n";
				PQ.push({dis[v],v});
			}
		}
	}
}
void add(int u,int v,int d){
	g[u].pb({v,d});
}
int main(){
	//pre();
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,m){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		rep(j,0,2)rep(k,0,2)add(id(u,j,k),id(v,j,k),c),add(id(v,j,k),id(u,j,k),c);
		rep(j,0,2)add(id(u,0,j),id(v,1,j),0),add(id(v,0,j),id(u,1,j),0);
		rep(j,0,2)add(id(u,j,0),id(v,j,1),2*c),add(id(v,j,0),id(u,j,1),2*c);
		add(id(u,0,0),id(v,1,1),c);
		add(id(v,0,0),id(u,1,1),c);
	}
	dij();
	rep(i,2,n+1){
		printf("%lld ",dis[id(i,1,1)]); 
	} 
}