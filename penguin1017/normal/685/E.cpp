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
const int N=1009;
const ll mod=998244353;
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
*/
int u[200009],v[200009];
int dis[N][N];
vi g[200009];
int ans[200009],r[200009],s[200009],t[200009];
int main(){
	//pre();
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,m+1){
		scanf("%d%d",&u[i],&v[i]);
	}
	rep(i,0,q){
		int l;
		scanf("%d%d%d%d",&l,&r[i],&s[i],&t[i]);
		g[l].pb(i);
	}
	rep(i,1,n+1)rep(j,1,n+1)dis[i][j]=1000000000;
	per(i,1,m+1){
		rep(j,1,n+1)dis[j][j]=i;
		rep(j,1,n+1)dis[u[i]][j]=dis[v[i]][j]=min(dis[u[i]][j],dis[v[i]][j]);
		for(auto v:g[i])if(dis[s[v]][t[v]]<=r[v])ans[v]=1;
	}
	rep(i,0,q)if(ans[i])printf("Yes\n");
	else printf("No\n");
}