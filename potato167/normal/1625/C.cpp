#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
const ll mod=1e9+7;
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}


void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,l,k;
	cin>>n>>l>>k;
	vector<int> p(n);
	rep(i,n){
		cin>>p[i];
		if(i) p[i-1]=p[i]-p[i-1];
		if(i==n-1) p[i]=l-p[i];
	}
	vector<int> q(n);
	rep(i,n) cin>>q[i];
	vector<vector<int>> dp(n+1,vector<int>(k+1,INF));
	dp[0][0]=0;
	rep(i,n){
		vector<vector<int>> n_dp(n+1,vector<int>(k+1,INF));
		rep(j,n) rep(c,k+1){
		if(dp[j][c]>=INF) continue;
		if(c!=k) chmin(n_dp[j][c+1],dp[j][c]+q[j]*p[i]);
		chmin(n_dp[i+1][c],dp[j][c]+p[i]*q[j]);
		}
		swap(dp,n_dp);
	}
	int ans=INF;
	rep(c,k+1) chmin(ans,dp[n][c]);
	cout<<ans<<"\n";
}