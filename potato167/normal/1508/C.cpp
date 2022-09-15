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

struct edge
{
	ll weight;
	ll to;
	ll from;
	bool operator<(const edge &x) const{
		if(weight==x.weight){
			if(to==x.to) return from<x.from;
			return to<x.to;
		}
		return weight<x.weight;
	};
};
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
	//a,b
	void unite(int a,int b){
		a=root(a),b=root(b);
		if(a==b) return;
		if(wei[a]<wei[b]) std::swap(a,b);
		par[b]=a;
		wei[a]+=wei[b];
	}
};
}
using po167::UFtree;

//main
int main() {
	ll N,M;
	cin>>N>>M;
	ll A=0;
	vector<edge> p(M);
	vector<vector<pair<ll,ll>>> G(N);
	rep(i,M){
		ll a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		A^=c;
		if(a<b) swap(a,b);
		p[i]={c,a,b};
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	if(M==0){
		cout<<"0"<<endl;
		return 0;
	}
	So(p);
	if(N*(N-1)/2-M>N){
		UFtree t(N);
		ll B=0,C=I;
		rep(i,N) if(chmin(C,(ll) G[i].size())) B=i;
		rep(i,N) t.par[i]=B;
		t.wei[B]=N-C;
		for(auto x:G[B]){
			t.par[x.first]=x.first;
		}
		for(auto x:G[B]){
			ll a=x.first;
			vector<ll> q(N);
			for(auto x:G[a]) q[x.first]=1;
			rep(i,N){
				if(q[i]==0&&!t.same(i,a)){
					t.unite(i,a);
				}
			}
		}
		ll Z=0;
		rep(i,M){
			ll a=p[i].from,b=p[i].to;
			if(!t.same(a,b)) Z+=p[i].weight,t.unite(a,b);
		}
		cout<<Z<<endl;
	}
	else{
		vector<vector<int>> G(N,vector<int>(N));
		for(auto x:p){
			G[x.to][x.from]=1;
			G[x.from][x.to]=1;
		}
		UFtree t(N),u(N);
		ll L=N;
		rep(i,N){
			rep(j,N){
				if(G[i][j]==0){
					if(!t.same(i,j)){
						L--;
						t.unite(i,j);
					}
				}
			}
		}
		//rep(i,5) cout<<t.root(i)<<" ";
		cout<<endl;
		if(L==1){
			if(M==N*(N-1)/2-N+1) cout<<min(A,(ll) p[0].weight)<<endl;
			else cout<<"0"<<endl;
			return 0;
		}
		ll Z=0,J=0;
		rep(i,M){
			ll a=p[i].from,b=p[i].to,c=p[i].weight;
			if(J==0&&c>=A) u=t,J=1,Z+=A;
			if(u.same(a,b)) continue;
			u.unite(a,b);
			/*rep(i,4){
				cout<<u.root(i)<<" ";
			}
			cout<<endl;*/
			Z+=c;
			if(t.same(a,b)){
				J=1;
				u=t;
			}
			else t.unite(a,b);
		}
		cout<<Z<<endl;
	}
}