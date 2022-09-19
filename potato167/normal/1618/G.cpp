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

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m,q;
	cin>>n>>m>>q;
	ll ans=0;
	vector<ll> A(n),B(m);
	rep(i,n) cin>>A[i],ans+=A[i];
	rep(i,m) cin>>B[i];
	vector<pair<int,int>> query(q);
	rep(i,q){
		int k;
		cin>>k;
		query[i]={k,i};
	}
	So(query);
	vector<pair<ll,int>> p(n+m);
	rep(i,n+m){
		if(i<n) p[i]={A[i],1};
		else p[i]={B[i-n],0};
	}
	So(p);
	UFtree T(n+m);
	rep(i,n+m) T.wei[i]=p[i].second;
	vector<pair<ll,int>> diff(n+m,{INF,INF});
	rep(i,n+m-1) diff[i]={p[i+1].first-p[i].first,i};
	So(diff);
	vector<ll> sum(n+m+1),val(q);
	rep(i,n+m) sum[i+1]=sum[i]+p[i].first;
	int ind=0;
	rep(i,q){
		while(query[i].first>=diff[ind].first){
			int a=diff[ind].second;
			int b=T.root(a+1);
			ans+=sum[b+1-T.wei[b]];
			ans-=sum[b+1-T.wei[b]-T.wei[a]];
			ans-=sum[a+1]-sum[a+1-T.wei[a]];
			T.unite(a,b);
			ind++;
		}
		val[query[i].second]=ans;
	}
	rep(i,q) cout<<val[i]<<"\n";
	return ;
}