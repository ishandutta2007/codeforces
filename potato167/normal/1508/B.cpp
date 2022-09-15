#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
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
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

vector<ll> solve(){
	ll N,K;
	cin>>N>>K;
	ll X=K;
	rep(i,N-1) X/=2;
	vector<ll> ans(N);
	if(X!=0){
		ll A=1;
		rep(i,N-1) A*=2;
		if(A==K){
			rep(i,N) ans[i]=N-i;
		}
		else return{-1};
		return ans;
	}
	vector<ll> p(N);
	X=K-1;
	rep(i,N-1){
		p[N-2-i]=X%2;
		X/=2;
	}
	ll k=0;
	rep(i,N){
		if(p[i]==0){
			for(int j=k;j<=i;j++) ans[j]=i+k-j+1;
			k=i+1;
		}
	}
	return ans;
}

//main
int main() {
	ll T;
	cin>>T;
	vector<vector<ll>> ans(T);
	rep(i,T) ans[i]=solve();	
	rep(i,T){
		rep(j,ans[i].size()){
			cout<<ans[i][j];
			if(j!=ans[i].size()-1) cout<<" ";
			else cout<<"\n";
		}
	}
}