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
		ll N;
		cin>>N;
		vector<ll> p(N),dp1(N),dp2(N);
		rep(i,N) cin>>p[i];
		ll S=p[0],K=0;
		dp1[0]=1;
		map<ll,ll> m;
		m[0]=1;
		for(int i=1;i<N;i++){
			ll A=0;
			if(m.count(S)) A=m[S]%Q;
			dp1[i]=(dp1[i-1]+dp2[i-1])%Q;
			dp2[i]=(dp1[i]-A+Q)%Q;
			m[S]+=dp2[i];
			S+=p[i];
		}
		ans[l]=(dp1[N-1]+dp2[N-1])%Q;
	}
	print(ans);
}