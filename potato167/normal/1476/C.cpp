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

int main() {
	ll T;
	cin>>T;
	vector<ll> ans(T);
	rep(l,T){
		ll N;
		cin>>N;
		vector<ll> c(N),a(N),b(N);
		rep(i,N) cin>>c[i];
		rep(i,N) cin>>a[i];
		rep(i,N) cin>>b[i];
		ll Z=0,A=c[N-1]-1;
		for(int i=N-1;i>0;i--){
			ll X=abs(a[i]-b[i]);
			chmax(Z,A+2+X);
			if(X!=0){
				A+=2;
				A+=c[i-1]-X-1;
				chmax(A,c[i-1]-1);
			}
			else{
				A=c[i-1]-1;
			}
		}
		ans[l]=Z;
	}
	rep(l,T) cout<<ans[l]<<endl;
}