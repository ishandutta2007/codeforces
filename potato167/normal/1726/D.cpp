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

namespace po167{
struct UFtree
{
	int _n;
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):_n(n),wei(n),component(n),par(n){
		for(int i=0;i<n;i++){
			wei[i]=1,par[i]=i;
		}
	}
	void intialize(){
		for(auto x:q){
			wei[root(x)]=1;
			par[x]=x;
		}
		component=(int)par.size();
		q={};
	}
	//
	int root(int a){
		assert(0<=a&&a<_n);
		if(a==par[a]) return a;
		return par[a]=root(par[a]);
	}
	//true1,false0
	int same(int a,int b){
		assert(0<=a&&a<_n);
		assert(0<=b&&b<_n);
		if(root(a)==root(b)) return 1;
		else return 0;
	}
	//a,b,true
	bool unite(int a,int b){
		a=root(a),b=root(b);
		if(a==b) return false;
		if(wei[a]<wei[b]) std::swap(a,b);
		par[b]=a;
		q.push_back(b);
		wei[a]+=wei[b];
		component--;
		return true;
	}
	private:
	std::vector<int> par;
};
}
using po167::UFtree;



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
	int n,m;
	cin>>n>>m;
	string ans;
	UFtree T(n);
	vector<int> A(m),B(m);
	vector<pair<int,int>> p;
	vector<vector<int>> G(n);
	set<int> s;
	rep(i,m){
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		if(T.unite(A[i],B[i])){
			G[A[i]].push_back(B[i]);
			G[B[i]].push_back(A[i]);
			ans+='1';
		}else{
			p.push_back({A[i],B[i]});
			ans+='0';
			s.insert(A[i]);
			s.insert(B[i]);
		}
	}
	if((int)(p.size())!=3||(int)(s.size())!=3){
		cout<<ans<<"\n";
		return;
	}
	UFtree U(n);
	U.unite(p[0].first,p[0].second);
	rep(i,m){
		if(A[i]==p[0].first&&B[i]==p[0].second){
			ans[i]='1';
		}else if(U.unite(A[i],B[i])){
			ans[i]='1';
		}else{
			ans[i]='0';
		}
	}
	cout<<ans<<"\n";/*
	UFtree X(n),Y(n);
	rep(i,m){
		if(ans[i]=='1') X.unite(A[i],B[i]);
		else Y.unite(A[i],B[i]);
	}
	assert(X.component+Y.component==2*n-m);
	cout<<"ok"<<endl;*/
}