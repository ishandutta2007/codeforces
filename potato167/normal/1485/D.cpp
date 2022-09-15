#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}
template<class T> void print(vector<T> v) {rep(i,v.size()) cout<<v[i]<<endl;}

ll f(ll a){
	return a*a*a*a;
}

int main() {
	ll N,M,K=720720;
	cin>>N>>M;
	vector<vector<ll>> p(N,vector<ll>(M));
	rep(i,N){
		rep(j,M) cin>>p[i][j];
	}
	rep(i,N){
		rep(j,M){
			if((i+j)%2==0) cout<<K;
			else cout<<K-f(p[i][j]);
			if(j!=M-1) cout<<" ";
			else cout<<endl;
		}
	}
}