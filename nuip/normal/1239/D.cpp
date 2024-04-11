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
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
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
#include "../benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

typedef vv<int> Graph;
struct Scc{
  stack<int> S;
  vector<int> inS,low,num;
  int time=0;
public:
  Graph dag;
  vector<int> inv;
  vv<int> scc;
  void visit(const Graph &g, int v){
    low[v] = num[v] = ++time;
    S.push(v); inS[v]=1;
    for(const int  &w:g[v]){
      if(!num[w]){
				visit(g,w);
				low[v]=min(low[v],low[w]);
      }else if(inS[w]) low[v]=min(low[v],num[w]);
    }
    if(low[v]==num[v]){
      scc.eb();
      while(1){
				int w = S.top(); S.pop(); inS[w]=0;
				scc.back().pb(w);
				if(v==w) break;
      }
    }
  }
  Scc(const Graph &g) {
    const int n = g.size();
    num.resize(n); low.resize(n); inS.resize(n);
    rep(u,n)if(!num[u]) visit(g,u);
    reverse(all(scc));
    
    inv.resize(n); dag.resize(scc.size());
    rep(i,scc.size())for(auto v:scc[i]) inv[v]=i;
    rep(i,scc.size())for(auto v:scc[i])for(auto e:g[v])
			if(inv[e]!=i)	dag[i].pb(inv[e]);
  }
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		vector<pii> ps; ps.reserve(m);
		rep(i,m){
			int x,y;
			cin>>x>>y; --x; --y;
			ps.eb(x,y);
		}
		vv<int> g(n);
		for(pii p:ps){
			g[p.X].pb(p.Y);
		}
		Scc h(g);
		for(int w:h.dag[0]) assert(0<w);
		if(h.scc.size()==1){
			cout<<"No" NL;
		}else{
			cout<<"Yes" NL;
			int t=h.scc[0].size();
			cout<<n-t<<" "<<t NL;
			rep(i,n)if(h.inv[i]) cout<<i+1<<" ";cout NL;
			rep(i,n)if(!h.inv[i]) cout<<i+1<<" ";cout NL;
		}
	}
  return 0;
}