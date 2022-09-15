#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (int i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}


void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> p(n);
	rep(i,n){
		cin>>p[i];
		if(i) p[i]+=p[i-1];
	}
	vector<vector<int>> dp(m+1,vector<int>(m+1,INF));
	rep(i,m+1) dp[0][i]=0;
	rep(i,n){
		vector<vector<int>> n_dp(m+1,vector<int>(m+1,INF));
		rep(j,m+1) rep(k,m+1){
			if(j-k>=0){
				chmin(n_dp[j][k],dp[j-k][k]+abs(p[i]-j));
			}
		}
		rep(j,m+1) for(int k=m-1;k>=0;k--) chmin(n_dp[j][k],n_dp[j][k+1]);
		swap(dp,n_dp);
	}
	cout<<dp[m][0]<<"\n";
}