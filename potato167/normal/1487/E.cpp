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
	vector<ll> p(4);
	rep(i,4) cin>>p[i];
	vector<vector<ll>> r(4);
	vector<vector<pair<ll,ll>>> q(4);
	vector<vector<ll>> dp(4);
	set<tuple<ll,ll,ll>> s;
	rep(i,4){
		dp[i].resize(p[i]);
		q[i].resize(p[i]);
		r[i].resize(p[i]);
		rep(j,p[i]){
			ll a;
			cin>>a;
			r[i][j]=a;
			if(i==0) dp[i][j]=a,q[i][j]={a,j};
			else dp[i][j]=I;
		}
	}
	rep(i,3){
		ll m;
		cin>>m;
		rep(j,m){
			ll a,b;
			cin>>a>>b;
			a--,b--;
			s.insert({a,b,i});
		}
	}
	rep(i,3){
		So(q[i]);
		rep(j,p[i+1]){
			rep(k,p[i]){
			ll a=q[i][k].second;
			if(!s.count({a,j,i})){
				dp[i+1][j]=dp[i][a]+r[i+1][j];
				q[i+1][j]={dp[i+1][j],j};
				break;
			}
			if(k==p[i]-1) q[i+1][j]={I,j};
			}
		}
	}
	So(q[3]);
	if(q[3][0].first>=I) cout<<"-1"<<endl;
	else cout<<q[3][0].first<<endl;
}