#include <bits/stdc++.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end());reverse(v.begin(),v.end());}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}

namespace po167{
struct UFtree
{
	std::vector<int> par;
	std::vector<int> wei;
	UFtree(int n):par(n),wei(n){
		for(int i=0;i<n;i++){
			wei[i]=1,par[i]=i;
		}
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
		return true;
	}
};
}
using po167::UFtree;

vector<vector<ll>> tree(ll N){
	vector<vector<ll>> F(N);
	for(int i=0;i<N-1;i++){
		ll a,b;
		cin>>a>>b;
		a--,b--;
		F[a].push_back(b);
		F[b].push_back(a);
	}
	return F;
}

vector<vector<pair<ll,ll>>> tree_dis(ll N){
		vector<vector<pair<ll,ll>>> F(N);
	for(int i=0;i<N-1;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		F[a].push_back({b,c});
		F[b].push_back({a,c});
	}
	return F;
}

//-2
template<class T> tuple<vector<int>,vector<int>> tree_dp(vector<vector<T>> &G,int nekko){
	ll N=G.size();
	vector<int> oya(N,-1);
	oya[nekko]=-2;
	vector<int> jyun={nekko};
	for(int i=0;i<N;i++){
		int a=jyun[i];
		for(auto y:G[a]){
			auto x=y; //T
			if(oya[x]==-1) jyun.push_back(x),oya[x]=a;
		}
	}
	return {oya,jyun};
}

//main
int main() {
	ll N,M,X;
	cin>>N>>M>>X;
	map<pair<int,int>,int> m;
	vector<ll> p(N);
	vector<vector<int>> G(N);
	UFtree A(N);
	ll S=0;
	rep(i,N) cin>>p[i],S+=p[i];
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		if(A.unite(a,b)){
			G[a].push_back(b);
			G[b].push_back(a);
			m[{a,b}]=i+1;
			m[{b,a}]=i+1;
		}
	}
	if(S<X*(N-1)){
		cout<<"NO"<<endl;
		return 0;
	}
	vector<int> oya,jyun;
	tie(oya,jyun)=tree_dp(G,0);
	cout<<"YES"<<"\n";
	for(int i=N-1;i>0;i--){
		int a=jyun[i];
		if(p[a]>X){
			cout<<m[{a,oya[a]}]<<"\n";
			p[oya[a]]+=p[a]-X;
			p[a]=-1;
		}
	}
	for(int i=1;i<N;i++){
		int a=jyun[i];
		if(p[a]!=-1){
			cout<<m[{a,oya[a]}]<<"\n";
		}
	}
	return 0;
}