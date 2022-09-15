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
	vector<vector<int>> G(n+1);
	vector<int> p(n);
	rep(i,n){
		cin>>p[i];
		G[p[i]].push_back(i);
	}
	vector<int> use;
	vector<int> ind(n+1);
	vector<int> order(n);
	rep(i,n+1){
		if(!G[i].empty()) use.push_back(i);
	}
	for(int i=(int)(use.size())-2;i>=0;i--){
		if(G[use[i]].size()<G[use[i+1]].size()){
			swap(use[i],use[i+1]);
		}
	}
	rep(i,n){
		int a=use[i];
		order[i]=G[a][ind[a]];
		ind[a]++;
		if((int)(G[a].size())>ind[a]) use.push_back(a);
	}
	auto tran=order;
	rep(i,n-1){
		if(p[tran[i]]!=p[tran[i+1]]) swap(tran[i],tran[i+1]);
	}
	vector<int> ans(n);
	rep(i,n){
		ans[order[i]]=p[tran[i]];
	}
	vec_out(ans);
}