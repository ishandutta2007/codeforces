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
#define rep(i,a) for (ll i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}
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
	int N,M,Q;
	cin>>N>>M>>Q;
	vector<int> p(N*M);
	int K=0;
	rep(i,N) rep(j,M){
		char c;
		cin>>c;
		if(c=='*') p[i+j*N]=1,K++;
	}
	int ans=0;
	rep(i,K) if(p[i]==0) ans++;
	rep(i,Q){
		int a,b;
		cin>>a>>b;
		a--,b--;
		int ind=a+b*N;
		if(p[ind]){
			p[ind]=0;
			if(ind<K) ans++;
			K--;
			if(p[K]==0) ans--;
		}else{
			p[ind]=1;
			if(ind<K) ans--;
			if(p[K]==0) ans++;
			K++;
		}
		cout<<ans<<"\n";
	}
}