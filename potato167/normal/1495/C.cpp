#include <bits/stdc++.h>
using namespace std;
using std::cout;
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
	vector<vector<vector<char>>> ans(T);
	rep(l,T){
		ll N,M;
		cin>>N>>M;
		vector<vector<char>> p(N,vector<char>(M));
		rep(i,N) rep(j,M){
			cin>>p[i][j];
		}
		rep(i,N){
			if(i%3==0) rep(j,M) p[i][j]='X';
		}
		for(int i=1;i<N;i+=3){
			ll k=0;
			rep(j,M) if(p[i][j]=='X') k=j;
			if(i+1!=N) rep(j,M) if(p[i+1][j]=='X') k=j; 
			if(i+1!=N) p[i][k]='X',p[i+1][k]='X';
		}
		if(N%3==0){
			ll i=N-1;
			rep(j,M) if(p[i][j]=='X') p[i-1][j]='X';
		}
		ans[l]=p;
	}
	rep(l,T){
		ll N=ans[l].size(),M=ans[l][0].size();
		rep(i,N){
			rep(j,M) cout<<ans[l][i][j];
			cout<<endl;
		}
	}
}