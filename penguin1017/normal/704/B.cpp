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
const int N=5e3+9;
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
ll dp[N][N];
int x[N],a[N],b[N],c[N],d[N];
void upd(ll &a,const ll b){
	if(a>b)a=b;
}
int main(){
	//pre();
	int n,s,e;
	scanf("%d%d%d",&n,&s,&e);
	rep(i,1,n+1)scanf("%d",&x[i]);
	rep(i,1,n+1)scanf("%d",&a[i]);
	rep(i,1,n+1)scanf("%d",&b[i]);
	rep(i,1,n+1)scanf("%d",&c[i]);
	rep(i,1,n+1)scanf("%d",&d[i]);
	rep(i,0,N)rep(j,0,N)dp[i][j]=Inf;
	dp[0][0]=0;
	rep(i,1,n+1){
		int l=i!=1;
		rep(j,l,n+1){
			if(dp[i-1][j]==Inf)continue;
			if(i==s){
				upd(dp[i][j+1],dp[i-1][j]-x[i]+d[i]);
				if(j)upd(dp[i][j-1],dp[i-1][j]+x[i]+c[i]);
			}
			else if(i==e){
				upd(dp[i][j+1],dp[i-1][j]-x[i]+b[i]);
				if(j)upd(dp[i][j-1],dp[i-1][j]+x[i]+a[i]);
			}
			else{
				upd(dp[i][j+2],dp[i-1][j]-2*x[i]+d[i]+b[i]);
				if(j>=2)upd(dp[i][j-2],dp[i-1][j]+2*x[i]+c[i]+a[i]);
				if(i>s||j>1)upd(dp[i][j],dp[i-1][j]+a[i]+d[i]);
				if(i>e||j>1)upd(dp[i][j],dp[i-1][j]+b[i]+c[i]);
			}
		//	cout<<i<<' '<<j<<' '<<dp[i][j]<<"check\n";
		}
	} 
	printf("%lld\n",dp[n][0]);
}