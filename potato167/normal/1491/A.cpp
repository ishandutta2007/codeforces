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
	ll T,N;
	cin>>N>>T;
	vector< ll >ans;
	vector<ll> p(N);
	ll A=0;
	rep(i,N) cin>>p[i],A+=p[i];
	rep(l,T){
		ll t,x;
		cin>>t>>x;
		if(t==1){
			x--;
			A-=p[x];
			p[x]^=1;
			A+=p[x];
		}
		else{
			if(A>=x) ans.push_back(1);
			else ans.push_back(0);
		}
	}
	print(ans);
}