#include <bits/stdc++.h>
using namespace std;
using std::cout;
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

//167
int main(){
	ll T;
	cin>>T;
	rep(l,T){
		ll n,m;
		cin>>n>>m;
		vector<ll> p(n);
		ll a;
		vector<vector<ll>> G(m);
		rep(i,m){
			ll k;
			cin>>k;
			rep(j,k) cin>>a,G[i].push_back(a-1);
			if(k==1) p[a-1]++;
		}
		ll J=0;
		rep(i,n) if(p[i]>(m+1)/2) J=1;
		if(J==1){
			cout<<"NO"<<endl;
			continue;
		}
		vector<ll> ans(m);
		rep(i,m){
			ll k=G[i].size();
			if(k==1){
				ans[i]=G[i][0];
				continue;
			}
			ll a=0;
			rep(j,k-1){
				if(p[G[i][a]]>p[G[i][j+1]]) a=j+1;
			}
			ans[i]=G[i][a];
			p[G[i][a]]++;
		}
		cout<<"YES"<<endl;
		rep(i,m){
			cout<<ans[i]+1;
			if(i!=m-1) cout<<" ";
			else cout<<endl;
		}
	}
}