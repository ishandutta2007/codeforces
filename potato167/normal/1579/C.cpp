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
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}



//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t){
		int n,m,k;
		cin>>n>>m>>k;
		vector<vector<int>> p(n+2,vector<int>(m+2));
		rep(i,n) rep(j,m){
			char a;
			cin>>a;
			if(a=='*') p[i+1][j+1]=1;
		}
		vector<vector<int>> x(n+2,vector<int>(m+2,-1));
		auto y=x;
		rep(i,n+2) rep(j,m+2){
			if(p[i][j]==0) continue;
			x[i][j]=x[i-1][j+1]+1;
			y[i][j]=y[i-1][j-1]+1;
		}
		vector<vector<int>> ans(n+2,vector<int>(m+2));
		rep(i,n+2) rep(j,m+2){
			if(min(x[i][j],y[i][j])>=k){
				rep(k,1+min(x[i][j],y[i][j])){
					ans[i-k][j+k]=1;
					ans[i-k][j-k]=1;
				}
			}
		}
		yneos(ans==p);
	}
}