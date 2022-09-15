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


namespace po167{
struct UFtree
{
	std::vector<int> wei;
	int component;
	UFtree(int n):par(n),wei(n),component(n){
		for(int i=0;i<n;i++){
			wei[i]=1,par[i]=i;
		}
	}
	void intialize(){
		for(int i=0;i<(int) par.size();i++){
			wei[i]=1,par[i]=i;
		}
		component=(int)par.size();
	}
	//
	int root(int a){
		if(a==par[a]) return a;
		return par[a]=root(par[a]);
	}
	//true1,false0
	int same(int a,int b){
		if(root(a)==root(b)) return 1;
		else return 0;
	}
	//a,b,true
	bool unite(int a,int b){
		a=root(a),b=root(b);
		if(a==b) return false;
		if(wei[a]<wei[b]) std::swap(a,b);
		par[b]=a;
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

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;


	rep(i,t) solve();
}

void solve(){
	int n,q;
	cin>>n>>q;
	UFtree T(n);
	int ans=1;
	int d=1;
	rep(rop,q){
		int a,b;
		cin>>a>>b;
		a--,b--;
		if(!T.unite(a,b)) d++;
		vector<int> p;
		rep(i,n){
			if(T.root(i)==i) p.push_back(T.wei[i]);
		}
		Sore(p);
		ans=-1;
		rep(k,d) ans+=p[k];
		cout<<ans<<"\n";
	}
}