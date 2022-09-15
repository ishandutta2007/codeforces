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
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}


vector<ll> p(200100);
ll f(int a,int b,int c){
	return (p[a]-p[b])*(p[b]-p[c]);
}
void solve();
//
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	rep(i,T) solve();
}

void solve(){
	int n;
	cin>>n;
	rep(i,n) cin>>p[i];
	ll ans=n*2-1;
	rep(i,n-2){
		if(f(i,i+1,i+2)<0) ans++;
	}
	rep(i,n-3){
		int J=1;
		if(f(i,i+1,i+2)>=0) J=0;
		if(f(i,i+2,i+3)>=0) J=0;
		if(f(i,i+1,i+3)>=0) J=0;
		if(f(i+1,i+2,i+3)>=0) J=0;
		ans+=J;
	}
	cout<<ans<<"\n";
	return ;
}