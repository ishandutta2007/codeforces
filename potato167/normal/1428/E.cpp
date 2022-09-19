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

ll f(ll n,ll d){
	if(n<d) return n;
	ll a=n/d,c=n%d,b=d-c;
	return a*a*b+(a+1)*(a+1)*c;
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
	_pq<tuple<ll,ll,ll>> pq;//{diff,a,divide}
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	rep(i,n){
		ll a;
		cin>>a;
		ans+=a*a;
		pq.push({f(a,2)-f(a,1),a,2});
	}
	rep(i,k-n){
		//cout<<ans<<"\n";
		ll a,b,c;
		tie(a,b,c)=pq.top();
		pq.pop();
		ans+=a;
		pq.push({f(b,c+1)-f(b,c),b,c+1});
	}
	cout<<ans<<"\n";
}