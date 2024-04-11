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

namespace po167{
struct UFtree
{
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):par(n),wei(n),component(n){
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
//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<tuple<int,int,int>> e(m);
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		e[i]={c,a,b};
	}
	vector<int> B;
	rep(i,m) rep(j,i+1){
		B.push_back((get<0>(e[i])+get<0>(e[j])+1)/2);
	}
	B.push_back(0);
	So(B);
	B.push_back(INF);
	vector<ll> X,Y; 
	rep(i,(int)(B.size())-1){
		sort(e.begin(),e.end(),[&](auto l,auto r){
			if(abs(get<0>(l)-B[i])!=abs(get<0>(r)-B[i])){
				return abs(get<0>(l)-B[i])<abs(get<0>(r)-B[i]);
			}
			return l>r;
		});
		UFtree T(n);
		ll x=0,y=0;
		rep(j,m){
			ll c,a,b;
			tie(c,a,b)=e[j];
			if(T.unite(a,b)){
				if(c<=B[i]) x++,y-=c;
				else x--,y+=c;
			}
		}
		X.push_back(x);
		Y.push_back(y);
	}
	ll p,k,a,b,c;
	cin>>p>>k>>a>>b>>c;
	ll q;
	ll ans=0;
	rep(i,k){
		if(i<p) cin>>q;
		else q=(q*a+b)%c;
		int ind=UB(B,(int)q);
		ind--;
		ll tmp=X[ind]*q+Y[ind];
		ans^=tmp;
	}
	cout<<ans<<"\n";
}