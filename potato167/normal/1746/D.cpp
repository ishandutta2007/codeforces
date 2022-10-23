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
#define rep(i,a) for (ll i=0;i<a;i++)
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
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	ll K;
	cin>>K;
	vector<vector<int>> G(n);
	vector<int> pare(n,-1);
	rep(i,n-1){
		int a;
		cin>>a;
		G[a-1].push_back(i+1);
		pare[i+1]=a-1;
	}
	vector<int> order={0};
	rep(i,n){
		for(auto x:G[order[i]]) order.push_back(x);
	}
	vector<ll> S(n);
	rep(i,n) cin>>S[i];
	vector<ll> X(n);
	X[0]=K;
	for(auto i:order){
		if(i==0) continue;
		X[i]=X[pare[i]]/(ll)(G[pare[i]].size());
	}
	vector<ll> dp1(n),dp2(n);
	reverse(all(order));
	for(int i:order){
		ll L=G[i].size();
		if(L==0){
			dp1[i]=S[i]*X[i];
			dp2[i]=S[i]*(X[i]+1);
			continue;
		}
		vector<ll> diff;
		ll tmp=X[i]*S[i];
		for(auto x:G[i]){
			tmp+=dp1[x];
			diff.push_back(dp2[x]-dp1[x]);
		}
		Sore(diff);
		int b=X[i]%L;
		rep(j,b) tmp+=diff[j];
		dp1[i]=tmp;
		dp2[i]=tmp+diff[b]+S[i];
	}
	cout<<dp1[0]<<"\n";
}