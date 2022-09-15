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



void solve();
//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n;
	cin>>n;
	vector<ll> p(n),q(n);
	rep(i,n) cin>>p[i];
	rep(i,n) cin>>q[i];
	int M=n*103;
	vector<bool> dp(M);
	dp[0]=1;
	rep(i,n){
		vector<bool> n_dp(M);
		int diff=abs(p[i]-q[i]);
		rep(j,M){
			if(dp[j]){
				n_dp[j+diff]=1;
				n_dp[abs(j-diff)]=1;
			}
		}
		swap(n_dp,dp);
	}
	ll ans=0;
	ll sum=0;
	rep(i,n) sum+=p[i]+q[i],ans+=p[i]*p[i]+q[i]*q[i];
	ll x;
	ans*=(n-2);
	rep(j,M){
		if(dp[j]){
			x=j;
			break;
		}
	}
	ans+=(((sum+x)*(sum+x))+(sum-x)*(sum-x))/4;
	cout<<ans<<"\n";
}