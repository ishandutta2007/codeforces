#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll mod=998244353;
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

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T=1;
	rep(i,T) solve();
}

void solve(){
	int N;
	cin>>N;
	vector<ll> x(N),y(N),t(N);
	rep(i,N) cin>>x[i]>>y[i]>>t[i];
	vector<ll> rui(N+1);
	vector<ll> dp(N);
	rep(i,N){
		dp[i]=x[i]-y[i];
		int b=LB(x,y[i]);
		dp[i]+=rui[i]-rui[b];
		dp[i]%=mod;
		rui[i+1]=(rui[i]+dp[i])%mod;
	}
	ll ans=x[N-1]+1;
	rep(i,N){
		if(t[i]==1){
			ans+=dp[i];
			ans%=mod;
		}
	}
	cout<<(ans+mod)%mod<<"\n";
}