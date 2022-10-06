#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#include<random>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(-data[y]>-data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
	bool operator()(int x,int y){ return findSet(x,y);}
	int operator[](int x){ return root(x);}
	bool unti(int x,int y){ return unite(x,y);}
};

struct graph {
  int n;
  struct edge { int src, dst, rev, id; };
  vector<vector<edge>> adj;
  graph() : n(0) { }
  //graph(int n) : n(n), adj(n) { }

  void add_edge(int src, int dst,int e,int f) {
    n = max(n, max(src, dst)+1);
    if (adj.size() < n) adj.resize(n);
    adj[src].push_back({src, dst, (int)adj[dst].size(), e});
    adj[dst].push_back({dst, src, (int)adj[src].size()-1, f});
  }

  // destructive
  vector<pii> path;
  void visit(int u,int e) {
    while (!adj[u].empty()) {
      auto e = adj[u].back();
      adj[u].pop_back();
      if (e.src >= 0) {
        adj[e.dst][e.rev].src = -1;
        visit(e.dst,e.id);
      }
    }
    path.eb(u,e);
  }
  vector<pii> eulerian_tour() {
    int m = 0, s = 0;
    for (int u = 0; u < n; ++u) {
      m += adj[u].size();
      if (adj[u].size() > 0) s = u;
    }
    path.clear(); visit(s,-1);
		out(s,path,1);
    if (path.size() != m/2 + 1 || path[0].X != path.back().X) return {};
    return path;
  }
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<pii> ps(n);
	for(auto &[a,b]:ps) cin>>a>>b;
	rrep(d,21){
		int msk=(1<<d)-1;
		vector<int> deg(msk+1);
		UF uf(msk+1);
		for(auto [a,b]:ps){
			a&=msk; b&=msk;
			uf.unite(a,b);
			++deg[a];
			++deg[b];
		}
		int cc=0;
		rep(i,msk+1)if(uf.root(i)==i && deg[i]) ++cc;
		int cy=1;
		rep(i,msk+1)if(deg[i]%2) cy=0;
		out(cc,cy,1);
		if(cc==1 && cy){
			cout<<d NL;
			graph g;
			reps(i,0,n){
				auto [a,b]=ps[i];
				a&=msk; b&=msk;
				g.add_edge(a,b,i,i+n);
			}
			auto path=g.eulerian_tour();
			reverse(all(path));
			vector<int> re;
			reps(i,1,path.size()){
				int b=path[i].Y;
				if(b<n){
					int x=b;
					re.eb(2*x);
					re.eb(2*x+1);
				}else{
					int x=b-n;
					re.eb(2*x+1);
					re.eb(2*x);
				}
			}
			out(re,1);
			rep(i,re.size()) cout<<re[i]+1<<" "; cout NL;
			
			return 0;
		}
	}
  return 0;
}