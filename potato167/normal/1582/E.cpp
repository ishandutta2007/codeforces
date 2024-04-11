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
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<ll> p(n);
	rep(i,n) cin>>p[n-i-1];
	vector<ll> sum(n+1);
	rep(i,n) sum[i+1]=sum[i]+p[i];
	int B=450;
	vector<vector<ll>> dp(B,vector<ll>(n+1,-1));
	int ans=0;
	dp[0][0]=INF;
	rep(i,B-1){
		rep(j,n+1){
			if(j) chmax(dp[i][j],dp[i][j-1]);
			if(j+i+1<=n){
				ll tmp=sum[j+i+1]-sum[j];
				if(tmp<dp[i][j]){
					dp[i+1][j+i+1]=tmp;
				}
			}
			if(dp[i][j]!=-1) ans=i;
		}
	}
	cout<<ans<<"\n";
}