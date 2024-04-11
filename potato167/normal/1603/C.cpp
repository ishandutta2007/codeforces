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

int m=1e5+10;
vector<ll> q1(m);
vector<ll> q2(m);
vector<bool> cou(m);

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	bool T=1;
	int t=1;
	if(T) cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n;
	cin>>n;
	vector<int> p(n);
	rep(i,n) cin>>p[n-i-1];
	vector<int> r;
	ll ans=0;
	rep(i,n){
		ll tmp=0;
		vector<int> n_r;
		for(auto x:r){
			ll c=(p[i]+x-1)/x-1;
			tmp+=(c*q1[x])%mod;
			ll a=p[i]/(c+1);
			q2[a]+=q1[x];
			q1[x]=0;
			if(!cou[a]){
				cou[a]=1;
				n_r.push_back(a);
			}
			//cout<<x<<" "<<c<<"\n";
		}
		//cout<<"\n";
		ans+=(tmp*(n-i))%mod;
		ans%=mod;
		q2[p[i]]++;
		if(!cou[p[i]]) n_r.push_back(p[i]);
		swap(q1,q2);
		swap(r,n_r);
		for(auto x:r) cou[x]=0;
	}
	for(auto x:r) q1[x]=0;
	cout<<ans<<"\n";
}