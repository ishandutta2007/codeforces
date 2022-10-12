//https://atcoder.jp/contests/arc115/submissions/20642348
//https://atcoder.jp/contests/arc115/tasks/arc115_e
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<math.h>
#include<unordered_set>
#include<unordered_map>
#include<iomanip>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define rrep(i,l,r) for(int i=l;i<=r;i++)
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define all(x) x.begin(),x.end()
#define unq(x) sort(all(x));x.erase(unique(all(x)),x.end())
//#define mod 1000000007
#define mod 998244353
#define ad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
void readv(vector<ll> &a,ll n){
	rep(i,n){
		ll x;
		cin>>x;
		a.push_back(x);
	}
}
void outv(vector<ll> &a,ll n){
	rep(i,n){
		if(i>0)cout<<" ";
		cout<<a[i];
	}
	cout<<"\n";
}
ll po(ll x,ll y){
	ll res=1;
	for(;y;y>>=1){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
	}
	return res;
}
ll gcd(ll a,ll b){
	return (b?gcd(b,a%b):a);
}
#define FACMAX 200010
ll fac[FACMAX],inv[FACMAX],ivf[FACMAX];
void initfac(){
	fac[0]=ivf[0]=inv[1]=1;
	for(ll i=1;i<FACMAX;i++)fac[i]=fac[i-1]*i%mod;
	for(ll i=1;i<FACMAX;i++){
		if(i>1)inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
		ivf[i]=po(fac[i],mod-2);
	}
}
ll P(ll n,ll k){
	if(n<0||n<k)return 0;
	return fac[n]*ivf[n-k]%mod;
}
ll C(ll n,ll k){
	if(k<0||n<k)return 0;
	return fac[n]*ivf[n-k]%mod*ivf[k]%mod;
}
ll H(ll n,ll k){
	return C(n+k-1,k);
}

pll pllcon(ll a,ll b){return make_pair(a,b);}

#define N 500010
ll n,a[N];
ll l[N],r[N];
ll dp[N][2];

ll rui[N][2];
void initrui(){
    rep(k,2)rui[0][k]=0;
}
void setvalue(ll k,ll i,ll x){
    rui[i+1][k]=(rui[i][k]+x)%mod;
}
ll rangesum(ll k,ll l,ll r){
    return rui[r+1][k]-rui[l][k];
}

ll val[2],dif[N][2];
void initimos(){
    rep(k,2)val[k]=0;
    rep(i,N)rep(k,2)dif[i][k]=0;
}
void rangeadd(ll k,ll l,ll r,ll x){
    ad(dif[l][k],x);
    ad(dif[r+1][k],-x);
}
ll takevalue(ll k,ll i){
    ad(val[k],dif[i][k]);
    return val[k];
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[0]=a[n+1]=0;

	stack<ll> st;
	st.push(0);
	for(int i=1;i<=n;i++){
	    while(pllcon(a[st.top()],st.top())>pllcon(a[i],i))st.pop();
	    l[i]=st.top();
	    st.push(i);
	}

	while(!st.empty())st.pop();
	st.push(n+1);
	for(int i=n;i>=1;i--){
	    while(pllcon(a[st.top()],st.top())>pllcon(a[i],i))st.pop();
	    r[i]=st.top();
	    st.push(i);
	}

	//for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<endl; cout<<"l,r"<<endl;

	dp[0][0]=1,dp[0][1]=0;

	initrui();
	setvalue(0,0,1);
	setvalue(0,1,0);

	initimos();

	for(int i=1;i<=n;i++){
	    rep(k,2){
		rangeadd(k^1,i,r[i]-1,rangesum(k,l[i],i-1)*a[i]);
	    }
	    rep(k,2){
		dp[i][k]=takevalue((i+k)%2,i);
		setvalue((i+k)%2,i,dp[i][k]);
	    }
	}

	//for(int i=0;i<=n;i++)cout<<dp[i][0]<<" "<<dp[i][1]<<endl;

	ll ans=(dp[n][0]-dp[n][1])%mod;
	if(ans<0)ans+=mod;
	cout<<ans<<endl;
}