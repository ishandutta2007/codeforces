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

int main() {
	ll T;
	cin>>T;	
	vector<ll> ans(T);
	rep(l,T){
		ll a,b,k=0;
		cin>>a>>b;
		if(b==1) k=1;
		ll D=I;
		while(D>k){
			ll c=b+k,d=a,L=k;
			while(d>0) d/=c,L++;
			chmin(D,L);
			k++;
		}
		ans[l]=D;
	}
	print(ans);
}