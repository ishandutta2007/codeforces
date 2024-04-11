#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int Lcm(int a,int b){
	return a*b/gcd(a,b);
}

ll my_pow(ll a,ll b){
	if(b==0) return 1;
	if(b&1) return (a*my_pow(a,b^1))%mod;
	return my_pow((a*a)%mod,b>>1);
}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n,a,x,y,k,M;
	cin>>n>>a>>x>>y>>k>>M;
	ll rev=my_pow(n,mod-2);
	int X=1;
	rep(i,k-1) X=Lcm(X,(int)i+1);
	vector<ll> dp(X);
	ll base=0;
	rep(i,n){
		dp[a%X]++;
		base=(a+base)%mod;
		a=(a*x+y)%M;
	}
	ll ans=0;
	for(int i=1;i<=k;i++){
		ans+=base;
		ans%=mod;
		//cout<<ans<<endl;
		vector<ll> n_dp(X);
		rep(j,X){
			n_dp[j]+=(((dp[j]*(n-1))%mod)*rev)%mod;
			n_dp[j-j%i]+=(dp[j]*rev)%mod;
			n_dp[j]%=mod;
			base-=(((dp[j]*rev)%mod)*(j%i))%mod;
		}
		base%=mod;
		swap(n_dp,dp);
	}
	rep(i,k-1) ans=(ans*n)%mod;
	cout<<(ans+mod)%mod<<"\n";
}