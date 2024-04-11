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
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}



ll jyo(ll a,ll b){
	if(b==0) return 1;
	if(b&1) return (a*jyo(a,b^1))%mod;
	return jyo((a*a)%mod,b>>1);
}

void solve();

//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n,k;
	cin>>n>>k;
	if(k==0){
		cout<<"1\n";
		return;
	}
	if(n&1){
		cout<<jyo(1+jyo(2,n-1),k)<<"\n";
	}
	else{
		ll ans=0;
		ll x=jyo(2,n-1)-1;
		ll y=1;
		ll z=jyo(2,n);
		rep(i,k){
			ans+=(y*jyo(z,k-1-i))%mod;
			ans%=mod;
			y*=x;
			y%=mod;
		}
		ans+=y;
		cout<<(ans+mod)%mod<<"\n";
	}
}