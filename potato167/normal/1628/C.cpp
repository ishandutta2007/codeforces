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
	int n;
	cin>>n;
	vector<vector<int>> p(n,vector<int>(n));
	rep(i,n) rep(j,n) cin>>p[i][j];
	int ans=0;
	for(int t=0;t<n/2;t+=2){
		int ind=0;
		for(int a=t;a<n-t-1;a++){
			if(ind%4<2) ans^=p[a][t];
			ind++;
		}
		for(int b=t;b<n-t-1;b++){
			if(ind%4<2) ans^=p[n-t-1][b];
			ind++;
		}
		for(int a=n-t-1;a>t;a--){
			if(ind%4<2) ans^=p[a][n-t-1];
			ind++;
		}
		for(int b=n-t-1;b>t;b--){
			if(ind%4<2) ans^=p[t][b];
			ind++;
		}
	}
	cout<<ans<<"\n";
}