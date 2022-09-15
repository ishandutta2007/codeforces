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
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}



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
	int n;
	cin>>n;
	vector<pair<ll,ll>> p(n);
	rep(i,n){
		ll a;
		cin>>a;
		p[i]={a,i};
	}
	Sore(p);
	ll val=0;
	vector<ll> ans(n);
	rep(i,n){
		ll a,ind;
		tie(a,ind)=p[i];
		ans[ind]=(i+2)/2;
		if(i%2) ans[ind]*=-1;
		val+=a*((i+2)/2);
	}
	cout<<val*2ll<<"\n0";
	rep(i,n) cout<<" "<<ans[i];
	cout<<"\n";
}