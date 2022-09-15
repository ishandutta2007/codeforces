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
	vector<vector<ll>> ans(T);
	rep(l,T){
		ll N;
		cin>>N;
		string S;
		cin>>S;
		vector<ll> p(N+1),q(N+1);
		rep(i,N){
			if(i==0){
				if(S[i]=='L') p[i+1]=1;
			}
			else if(S[i]=='L'){
				if(p[i]!=0) p[i+1]=1;
				else{
					p[i+1]=2+p[i-1];
				}
			}
		}
		for(int i=N;i>0;i--){
			if(i==N){
				if(S[i-1]=='R') q[i-1]=1;
			}
			else if(S[i-1]=='R'){
				if(q[i]!=0) q[i-1]=1;
				else q[i-1]=2+q[i+1];
			}
		}
		rep(i,N+1) ans[l].push_back(p[i]+q[i]+1);
	}
	rep(l,T){
		ll L=ans[l].size();
		rep(i,L){
			cout<<ans[l][i];
			if(i!=L-1) cout<<" ";
			else cout<<endl;
		}
	}
}