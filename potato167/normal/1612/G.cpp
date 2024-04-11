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
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	rep(i,t) solve();
}

void solve(){
	int m,N=1e6+5;
	ll cou=1,ans=0,len=0;
	cin>>m;
	vector<int> fact(m+1);
	vector<ll> p(N);
	fact[0]=1;
	rep(i,m) fact[i+1]=(fact[i]*(i+1))%mod;
	rep(i,m){
		int c;
		cin>>c;
		len+=c;
		p[c-1]++;
	}
	for(ll i=N-3;i>=0;i--){
		p[i]+=p[i+2];
		cou=(cou*fact[p[i]])%mod;
		if(i) cou=(cou*fact[p[i]])%mod;
		ans+=(((p[i]*((len-p[i])%mod))%mod)*i)%mod;
		ans%=mod;
		len-=p[i]*2;
		len%=mod;
	}
	cout<<(ans+mod)%mod<<" "<<cou<<"\n";
}