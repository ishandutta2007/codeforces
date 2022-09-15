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


namespace po167{
struct combination{
	std::vector<long long> fact;
	std::vector<long long> rev;
	std::vector<long long> fact_rev;
	long long MOD;
	combination(int max,long long mod):MOD(mod),fact(max+1),rev(max+1),fact_rev(max+1){
		for(long long i=0;i<=max;i++){
			if(i<2){
				fact[i]=1;
				fact_rev[i]=1;
				rev[i]=1;
				continue;
			}
			fact[i]=(fact[i-1]*i)%mod;
			rev[i]=mod-((mod/i)*rev[mod%i])%mod;
			fact_rev[i]=(fact_rev[i-1]*rev[i])%mod;
		}
	}
	long long Comb(int x,int y){
		if (x<y||y<0||x<0) return 0;
		return (((fact_rev[y]*fact_rev[x-y])%MOD)*fact[x])%MOD;
	}
};
}
using po167::combination;

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
	ll n,x,M=510;
	cin>>n>>x;
	vector<vector<ll>> dp(n+1,vector<ll>(x+1));
	vector<vector<ll>> p(M,vector<ll>(M));
	combination table(n+x,mod);
	rep(i,M) rep(j,M){
		if(j==0) p[i][j]=1;
		else p[i][j]=(p[i][j-1]*i)%mod;
	}
	rep(i,n+1) rep(j,x+1){
		if(i*j==0||i==1) continue;
		if(i>j) dp[i][j]=((p[j][i]-p[j-1][i])*table.Comb(n,i))%mod;
	}
	ll ans=0;
	rep(i,n+1) rep(j,x+1){
		if(i*j==0||i==1) continue;
		dp[i][j]%=mod;
		for(int k=i;k+j-1<=x&&k<=n;k++){
			dp[k][k+j-1]+=(((dp[i][j]*p[k-1][k-i])%mod)*table.Comb(n-i,k-i))%mod;
		}
		if(i==n) ans+=dp[i][j];
	}
	/*rep(i,n+1){
		rep(j,x+1) cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
	cout<<(ans%mod+mod)%mod<<"\n";
}