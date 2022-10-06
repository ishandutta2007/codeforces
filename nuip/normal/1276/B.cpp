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
#include "benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

struct Art {
  int n;
  vector<int> arts;
  vv<int> bcc;
  vv<int> tree;
  vector<int> isArt;

  Art(const vv<int> &g):n(g.size()), isArt(n){
    vector<int> num(n), low(n), S;

    function<void(int,int,int&)> dfs = [&](int p, int u, int &t) { 
      num[u] = low[u] = ++t; 
      S.push_back(u);
      for (int v: g[u]) {
        if (v == p) continue;
        if (num[v] == 0) {
          dfs(u, v, t);
          low[u] = min(low[u], low[v]);
          if (num[u] <= low[v]) {
            if (num[u] != 1 || num[v] > 2) {
							if(p>=0 || g[u].size()>1) arts.pb(u);
            }
						bcc.eb(1,u);
            vector<int> &C=bcc.back(); // biconnected component
            while (C.back() != v) {
              C.push_back(S.back());
              S.pop_back();
            }
          }
        } else low[u]=min(low[u], num[v]);
      }
    };
    for(int u=0, t; u<n; ++u)if(!num[u]) dfs(-1, u, t=0);
    rep(i,n)if(g[i].size()==0) bcc.eb(1,i);
    sort(all(arts)); UNIQUE(arts);
    int m=bcc.size();
    rep(i,arts.size()) isArt[arts[i]]=1;
    tree.resize(n+m);
    rep(i,m)for(int v:bcc[i]){
      tree[i+n].pb(v);
      tree[v].pb(i+n);
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		int n,m,a,b;
		cin>>n>>m>>a>>b; --a; --b;
		vv<int> g(n);
		rep(i,m){
			int x,y;
			cin>>x>>y; --x; --y;
			g[x].pb(y);
			g[y].pb(x);
		}
		rep(v,n){ sort(all(g[v])); UNIQUE(g[v]); }
		Art h(g);
		ll re=1;
		function<int(int,int,int)> dfs=
			[&](int v,int p,int tgt){
				int ret=(v<n);
				for(int w:h.tree[v])if(w!=p) ret+=dfs(w,v,tgt);
				if(v==tgt) re*=ret-1;
				return ret;
			};
		dfs(a,-1,b);
		dfs(b,-1,a);
		cout<<re NL;
	}
  return 0;
}