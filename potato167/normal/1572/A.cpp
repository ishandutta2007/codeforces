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
ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
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
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> G(n);
	vector<int> dp(n,1);
	queue<int> q;
	vector<int> seen(n);
	rep(i,n){
		cin>>seen[i];
		rep(j,seen[i]){
			int a;
			cin>>a;
			a--;
			G[a].push_back(i);
		}
		if(seen[i]==0) q.push(i);
	}
	int c=0;
	int ans=0;
	while(!q.empty()){
		c++;
		int a=q.front();
		q.pop();
		chmax(ans,dp[a]);
		for(auto x:G[a]){
			seen[x]--;
			int b=0;
			if(a>x) b++;
			chmax(dp[x],dp[a]+b);
			if(seen[x]==0) q.push(x);
		}
	}
	if(c==n) cout<<ans<<"\n";
	else cout<<"-1\n";
}