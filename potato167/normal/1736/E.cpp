#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}



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
	int n;
	cin>>n;
	vector<int> A(n);
	rep(i,n) cin>>A[i];
	/*
	dp[now+1][use][op+1]<-A[use]+dp[now][use][op]
	dp[now+1][use][op+use-now]<-A[use]+dp[now][any][op]
	(any<use)
	*/
	vector<vector<int>> dp(n,vector<int>(n+1,-INF));
	dp[0][0]=A[0];
	dp[1][1]=A[1];
	for(int i=1;i<n;i++){
		vector<vector<int>> n_dp(n,vector<int>(n+1,-INF));
		rep(j,n) rep(k,n+1){
			if(j!=n-1&&k+max(i,j+1)-i<=n) chmax(n_dp[max(i,j+1)][k+max(i,j+1)-i],dp[j][k]);
		}
		rep(j,n-1) rep(k,n){
			chmax(n_dp[j+1][k+1],n_dp[j][k]);
		}
		rep(j,n) rep(k,n){
			chmax(n_dp[j][k+1],dp[j][k]);
		}
		rep(j,n) rep(k,n+1){
			if(k>i+1) n_dp[j][k]=-INF;
			if(n_dp[j][k]!=-INF) n_dp[j][k]+=A[j];
		}
		swap(n_dp,dp);/*
		cout<<dp[2][1]<<" ";
		cout<<dp[4][3]<<" ";
		cout<<dp[4][4]<<"\n";*/
	}
	int ans=0;
	rep(i,n) rep(j,n+1) chmax(ans,dp[i][j]);
	cout<<ans<<"\n";
}