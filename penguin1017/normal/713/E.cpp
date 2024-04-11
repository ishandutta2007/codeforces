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
const ll mod=998244353;
const int Inf=1e9;
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
int n,m;
int a[N];
int dp[N][2];
bool check(int x){
	int st0=0,st1=0;
	for(;st0<=x;){
		dp[0][0]=st0?st0:-x;
		dp[0][1]=st1;
		rep(i,1,n+1)dp[i][0]=Inf,dp[i][1]=0;
		rep(i,0,n){
			if(dp[i][0]>x)return 0;
			//l1 i+1i 
			int l1=a[i+1]-a[i]+dp[i][0];
			if(l1>0&&dp[i][0]<=0)--l1;
			if(l1<=0)dp[i+1][0]=-x;
			else dp[i+1][0]=min(dp[i+1][0],l1);
			int l2=a[i+1]-a[i]+dp[i][1];
			if(l2>0)--l2;
			if(l2<=0)dp[i+1][0]=-x;
			else dp[i+1][0]=min(dp[i+1][0],l2);
			if(l1<=x)dp[i+1][1]=min(dp[i+1][1],a[i+1]-a[i]-x);
			dp[i+1][1]=min(dp[i+1][1],l2);
		}
		if(dp[n][0]<=st0&&dp[n][1]<=st1)return 1;
		st0=dp[n][0],st1=dp[n][1]; 
	}
	return 0;
}
int main(){
	//pre();
	scanf("%d%d",&m,&n);
	rep(i,0,n)scanf("%d",&a[i]);
	a[n]=a[0]+m;
	int l=0,r=m;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<r;
}