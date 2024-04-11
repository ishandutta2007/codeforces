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
	int n,m;
	cin>>n>>m;
	ll A,B;
	cin>>A>>B;
	vector<vector<char>> p(n,vector<char>(m));
	rep(i,n) rep(j,m) cin>>p[i][j];
	string S="DURLDDRLUURL";
	vector<int> dx={2,-2,0,0,1,1,1,1,-1,-1,-1,-1},dy={0,0,2,-2,1,-1,1,-1,1,-1,1,-1};
	_pq<pair<ll,int>> pq;
	vector<vector<ll>> dp(n,vector<ll>(m,ILL));
	rep(i,n) rep(j,m){
		if(p[i][j]=='.') dp[i][j]=0,pq.push({0,i*m+j});
	}
	while(!pq.empty()){
		ll cost;
		int tmp;
		tie(cost,tmp)=pq.top();
		int x=tmp/m,y=tmp%m;
		pq.pop();
		if(dp[x][y]!=cost) continue;
		rep(k,(int)(dx.size())){
			int s=x+dx[k],t=y+dy[k];
			if(min(s,t)<0||s>=n||t>=m) continue;
			//cout<<s<<" "<<t<<" "<<p[s][t]<<" "<<S[k]<<"\n";
			if(p[s][t]!=S[k]) continue;
			ll n_cost=cost;
			if(k<4) n_cost+=B;
			else n_cost+=A;
			if(chmin(dp[s][t],n_cost)) pq.push({n_cost,s*m+t});
		}
	}
	ll ans=ILL;
	rep(i,n) rep(j,m){
		if(j) chmin(ans,dp[i][j-1]+dp[i][j]);
		if(i) chmin(ans,dp[i-1][j]+dp[i][j]);
	}
	if(ans==ILL) cout<<"-1\n";
	else cout<<ans<<"\n";
	return;
	rep(i,n){
		rep(j,m){
			if(dp[i][j]==ILL) cout<<"# ";
			else cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
}