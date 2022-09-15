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
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}

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
		if(a<b) std::swap(a,b);
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
	vector<ll> p(n+1);
	UFtree T(n+1);
	rep(i,n){
		ll a;
		cin>>a;
		p[i+1]=a;
	}
	rep(i,n){
		ll b;
		cin>>b;
		p[i+1]-=b;
		p[i+1]+=p[i];
	}
	vector<vector<int>> G(n+1);
	vector<int> l(m),r(m),c(m);
	vector<int> op;
	rep(i,m){
		cin>>l[i]>>r[i];
		l[i]--;
		G[l[i]].push_back(i);
		G[r[i]].push_back(i);
	}
	rep(i,n+1){
		if(p[i]==0){
			for(auto x:G[i]) c[x]++;
			if(i!=n&&p[i+1]==0) T.unite(i,i+1);
		}
	}
	rep(i,m){
		if(c[i]==2) op.push_back(i);
	}
	rep(i,m){
		if((int)(op.size())==i){
			cout<<"NO\n";
			return ;
		}
		int a=op[i];
		int ind=T.root(l[a]);
		while(ind<r[a]){
			ind++;
			T.unite(ind-1,ind);
			if(p[ind]!=0){
				p[ind]=0;
				for(auto x:G[ind]){
					c[x]++;
					if(c[x]==2) op.push_back(x);
				}
			}else{
				ind=T.root(ind);
			}
		}
	}
	rep(i,n+1){
		if(p[i]!=0){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}