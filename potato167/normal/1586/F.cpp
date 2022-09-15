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



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,k;
	cin>>n>>k;
	vector<vector<int>> G(n,vector<int>(n,1));
	vector<int> p(n);
	rep(i,n) p[i]=i/k;
	int ans=1;
	while(p[n-1]!=0){
		rep(i,n) rep(j,i){
			if(p[i]!=p[j]) G[j][i]++;
		}
		ans++;
		rep(i,n) p[i]/=k;
	}
	cout<<ans<<"\n";
	rep(i,n){
		for(int j=i+1;j<n;j++){
			if(j!=1) cout<<" ";
			cout<<G[i][j];
		}
	}
	cout<<"\n";
}