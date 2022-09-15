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
const ll mod=1e9+7;
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
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n,p;
	cin>>n>>p;
	vector<int> A(n);
	rep(i,n){
		cin>>A[i];
	}
	So(A);
	vector<ll> dp(p+1);
	set<int> s;
	rep(i,n){
		int D=A[i];
		while(D){
			if(s.count(D)) break;
			if(D&1) D/=2;
			else if(D%4!=0){
				D=-1;
				break;
			}else D/=4;
		}
		if(D>0) continue;
		s.insert(A[i]);
		int c=0;D=A[i];
		while(D) D/=2,c++;
		if(c<=p) dp[c]++;
	}
	rep(i,p-1){
		dp[i+2]+=(dp[i+1]+dp[i])%mod;
	}
	ll ans=0;
	rep(i,p+1) ans=(ans+dp[i])%mod;//cout<<dp[i]<<"\n";
	cout<<(ans%mod+mod)%mod<<"\n";
}