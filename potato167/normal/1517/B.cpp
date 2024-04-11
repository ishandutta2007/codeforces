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

vector<vector<ll>> solve(){
	ll N,M;
	cin>>N>>M;
	vector<vector<ll>> p(N,vector<ll>(M));
	rep(i,N) rep(j,M) cin>>p[i][j];
	auto ans=p;
	rep(i,N) So(p[i]);
	vector<ll> q(N);
	rep(j,M){
		ll A=0,B=I;
		rep(i,N){
			if(chmin(B,p[i][q[i]])) A=i;
		}
		rep(i,N){
			if(i==A) ans[i][j]=p[i][q[i]],q[i]++;
			else ans[i][j]=p[i][M-1-j+q[i]];
		}
	}
	return ans;
}

//main
int main() {
	ll T;
	cin>>T;
	vector<vector<vector<ll>>> ans(T);
	rep(i,T) ans[i]=solve();
	rep(i,T){
		rep(j,ans[i].size()){
			rep(k,ans[i][j].size()){
				cout<<ans[i][j][k];
				if(k!=ans[i][j].size()-1) cout<<" ";
				else cout<<"\n";
			}
		}
	}
}