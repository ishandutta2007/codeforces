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
#define cauto const auto

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
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return move(re);}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
const ll MOD=1e9+7; //998244353

#define fst first
#define snd second

const long long INF = (1ll << 50);
struct graph {
  typedef long long flow_type;
  struct edge {
    int src, dst;
    flow_type capacity, flow;
    size_t rev;
  };
  int n;
  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) { }
  void add_edge(int src, int dst, flow_type capacity) {
		// out(src,dst,capacity,1);
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
  }
  flow_type max_flow(int s, int t) {
    vector<int> level(n), iter(n);
    function<int(void)> levelize = [&]() { // foward levelize
      level.assign(n, -1); level[s] = 0;
      queue<int> Q; Q.push(s);
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t) break;
        for (auto &e: adj[u]) {
          if (e.capacity > e.flow && level[e.dst] < 0) {
            Q.push(e.dst);
            level[e.dst] = level[u] + 1;
          }
        }
      }
      return level[t];
    };
    function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
      if (u == t) return cur;
      for (int &i = iter[u]; i < adj[u].size(); ++i) {
        edge &e = adj[u][i], &r = adj[e.dst][e.rev];
        if (e.capacity > e.flow && level[u] < level[e.dst]) {
          flow_type f = augment(e.dst, min(cur, e.capacity - e.flow));
          if (f > 0) {
            e.flow += f;
            r.flow -= f;
            return f;
          }
        }
      }
      return flow_type(0);
    };
    for (int u = 0; u < n; ++u) // initialize
      for (auto &e: adj[u]) e.flow = 0;

    flow_type flow = 0;
    while (levelize() >= 0) {
      fill(all(iter), 0);
      for (flow_type f; (f = augment(s, INF)) > 0; )
        flow += f;
    }
    return flow;
  }
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto m=read();
	cauto mp=readV<string>(n);
	graph g(n*m+n*(m-1)+(n-1)*m+2);
	cauto node=[&](int i,int j){ return i*m+j;};
	cauto yoko=[&](int i,int j){ return n*m + i*(m-1)+j;};
	cauto tate=[&](int i,int j){ return n*m + n*(m-1) + i*m+j;};
	cauto S=n*m+n*(m-1)+(n-1)*m;
	cauto T=n*m+n*(m-1)+(n-1)*m+1;
	int mx=0;
	int blk=0;
	rep(i,n)rep(j,m)if(mp[i][j]=='#'){
		g.add_edge(S,node(i,j),1);
		g.add_edge(node(i,j),T,1);
		++blk;
		++mx;
		if(j+1<m && mp[i][j+1]=='#'){
			cauto v=yoko(i,j);
			g.add_edge(node(i,j),v,INF);
			g.add_edge(node(i,j+1),v,INF);
			g.add_edge(v,T,1);
			++mx;
		}
		if(i+1<n && mp[i+1][j]=='#'){
			cauto v=tate(i,j);
			g.add_edge(S,v,1);
			g.add_edge(v,node(i,j),INF);
			g.add_edge(v,node(i+1,j),INF);
			++mx;
		}
	}
	cauto flow=g.max_flow(S,T);
	out(flow,mx,blk-(mx-flow),1);
	cout<<blk-(mx-flow) NL;
	// auto re=mp;
	// for(auto e:g.adj[S])if(e.flow==e.capacity){
	// 		auto v=e.dst;
	// 		if(v<n*m){
	// 			out(v/m,v%m,1);
	// 			re[v/m][v%m]='-';
	// 		}else{
	// 			v-=n*m;
	// 			if(m-1 && v<n*(m-1)){
	// 				out(2,v/(m-1),v%(m-1),1);
	// 				//re[v/(m-1)][v%(m-1)]='-';
	// 			}else{
	// 				v-=n*(m-1);
	// 				if(n-1 && v<(n-1)*m) out(3,v/m,v%m,1);
	// 				//re[v/m][v%m]='-';
	// 			}
	// 		}
	// 	}
	// for(auto s:re) cout<<s NL;
	return 0;
}