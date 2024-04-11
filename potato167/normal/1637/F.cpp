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
const ll mod=998244353;
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
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	int ind=0;
	vector<ll> p(n);
	rep(i,n){
		cin>>p[i];
		if(p[ind]<p[i]) ind=i;
	}
	vector<int> order={ind},pare(n,-2);
	pare[ind]=-1;
	vector<vector<int>> G(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i,n){
		int a=order[i];
		for(auto x:G[a]){
			if(pare[x]==-2){
				pare[x]=a;
				order.push_back(x);
			}
		}
	}
	vector<ll> dp(n);
	ll ans=0;
	for(int i=n-1;i>=0;i--){
		int a=order[i];
		if(i!=0){
			for(auto x:G[a]){
				if(x!=pare[a]){
					if(dp[a]<dp[x]){
						ans+=dp[a];
						dp[a]=dp[x];
					}else{
						ans+=dp[x];
					}
				}
			}
			chmax(dp[a],p[a]);
		}else{
			ll A=0,B=0;
			for(auto x:G[a]){
				if(B<dp[x]){
					ans+=B;
					B=dp[x];
					if(A<B) swap(A,B);
				}else{
					ans+=dp[x];
				}
			}
			ans+=p[a]*2ll;
		}
	}
	cout<<ans<<"\n";
}