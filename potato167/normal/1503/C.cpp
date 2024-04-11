#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}
template<class T> void print(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<endl;}

//main
int main() {
	ll N;
	cin>>N;
	vector<pair<ll,ll>> p(N);
	ll C=0;
	rep(i,N){
		ll a,c;
		cin>>a>>c;
		p[i]={a,c};
		C+=c;
	}	
	So(p);
	ll A=p[0].first+p[0].second;
	rep(i,N-1){
		ll a,c;
		tie(a,c)=p[i+1];
		C+=max(0ll,a-A);
		chmax(A,a+c);
	}
	cout<<C<<endl;
}