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
	int N,M;
	cin>>N>>M;
	vector<int> A(M),B(M);
	vector<ll> C(M);
	vector<vector<ll>> G(N,vector<ll>(N,INF));
	rep(i,N) G[i][i]=0;
	rep(i,M){
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--;
		G[A[i]][B[i]]=1,G[B[i]][A[i]]=1;
	}
	rep(k,N) rep(i,N) rep(j,N) chmin(G[i][j],G[i][k]+G[k][j]);
	ll ans=ILL;
	rep(i,M){
		chmin(ans,C[i]*(1+min(G[0][A[i]]+G[B[i]][N-1],G[N-1][A[i]]+G[B[i]][0])));
		rep(j,N){
			chmin(ans,C[i]*(1+G[0][j]+G[N-1][j]+1+min(G[A[i]][j],G[B[i]][j])));
		}
	}
	cout<<ans<<"\n";
}