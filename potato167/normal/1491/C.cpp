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

//main
int main() {
	ll T;
	cin>>T;
	vector< ll >ans(T);
	rep(l,T){
		ll N;
		cin>>N;
		vector<ll> p(N);
		vector<ll> q(N+1);
		rep(i,N) cin>>p[i];
		ll A=0;
		rep(i,N){	
			A+=max(0LL,p[i]-q[i]-1);
			if(q[i]>=p[i]){
				q[i+1]+=(q[i]-p[i]+1);
			}
			for(ll j=i+2;j<min(N,i+p[i]+1);j++){
				q[j]++;
			}
		}
		ans[l]=A;
	}
	print(ans);
}