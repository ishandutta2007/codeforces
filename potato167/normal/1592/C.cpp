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
ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

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
	int n,k;
	cin>>n>>k;
	vector<int> p(n);
	int all=0;
	vector<vector<int>> G(n);
	rep(i,n) cin>>p[i],all^=p[i];
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(all!=0&&k==2){
		yneos(0);
		return ;
	}
	vector<int> value(n),order={0},pare(n,-1),dp(n);
	pare[0]=-2;
	rep(i,n){
		int a=order[i];
		for(auto x:G[a]){
			if(pare[x]==-1){
				pare[x]=a;
				order.push_back(x);
			}
		}
	}
	rep(i,n){
		int a=order[n-i-1];
		value[a]^=p[a];
		chmin(dp[a],2);
		if(dp[a]==0&&value[a]==all) dp[a]++;
		if(dp[a]==1&&value[a]==0) dp[a]++;
		if(a){
			value[pare[a]]^=value[a];
			dp[pare[a]]+=dp[a];
		}
	}
	yneos(dp[0]==2);
}