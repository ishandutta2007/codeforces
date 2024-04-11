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

struct sepDec:public vector<int>{
  struct Rec {
    int root, count, par;
    explicit Rec(int r = 0, int c = 0, int p = 0):root(r), count(c), par(p){}
  };
  struct DFS {
    int u, i, p;
    explicit DFS(int ver = 0, int ind = 0, int pa = 0): u(ver), i(ind), p(pa) {}
  };
  vector<int> dep,par;
  const int n;
  
  void sep_dec(const vv<int> &conn){
    vector<bool> picked(n);
    vector<int> cnt(n); //num_children
    stack<Rec> recs;
    recs.emplace(0, n, -1);
    while(!recs.empty()){
      const Rec rf = recs.top();
      const int lb = rf.count / 2;
      recs.pop();
      int sep = rf.root;
      stack<DFS> dfss;
      dfss.emplace(rf.root, 0, rf.root);
      while(!dfss.empty()){
				DFS df = dfss.top();
				dfss.pop();
				if(df.i >= conn[df.u].size()){
					cnt[df.u] = 1;
					for(const int &v:conn[df.u]){
						if(picked[v] || v == df.p) continue;
						cnt[df.u] += cnt[v];
					}
					if(cnt[df.u] > lb){
						sep = df.u;
						cnt[df.p] = rf.count - cnt[df.u];
						break;
					}
				}else{
					dfss.emplace(df.u, df.i + 1, df.p);
					const int v = conn[df.u][df.i];
					if(!picked[v] && v != df.p){
						dfss.emplace(v, 0, df.u);
					}
				}
      }
      par[sep] = (rf.par < 0 ? sep : rf.par);
      picked[sep] = true;
      for(const int &v:conn[sep])if(!picked[v])	recs.emplace(v, cnt[v], sep);
    }
  }
  
  int dfs(int v){ return dep[v]>=0?dep[v]:dep[v]=(par[v]==v?v:dfs(par[v])+1);}

  sepDec(const vv<int> &g):n(g.size()){
    dep.resize(n,-1); par.resize(n);
    sep_dec(g);
    resize(n);
    rep(i,n)if(dep[i]<0) dfs(i);
    iota(all(*this),0);
    sort(all(*this),[&](int i,int j){return dep[i]>dep[j];});
  }
};


int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vv<int> g(n);
		rep(i,n-1){
			int a,b;
			cin>>a>>b; --a; --b;
			g[a].pb(b);
			g[b].pb(a);
		}
		int t0;
		cin>>t0;
		vector<int> vs0(t0);
		rep(i,t0) cin>>vs0[i], --vs0[i];
		int t1;
		cin>>t1;
		vector<int> vs1(t1);
		rep(i,t1) cin>>vs1[i], --vs1[i];
		int x=0;
		{
			cout<<"B "<<vs1[0]+1<<endl;
			cin>>x; --x;
		}
		vector<int> in(n);
		for(int x:vs0) in[x]=1;
		int w;
		{
			queue<int> que; que.emplace(x);
			vector<int> usd(n); usd[x]=1;
			while(que.size()){
				int v=que.front(); que.pop();
				if(in[v]){
					w=v;
					break;
				}
				for(int w:g[v])if(MX(usd[w],1)) que.emplace(w);
			}
		}
		int y=0;
		{
			cout<<"A "<<w+1<<endl;
			cin>>y; --y;
		}
		cout<<"C "<<(count(all(vs1),y)?w+1:-1)<<endl;
	}
  return 0;
}