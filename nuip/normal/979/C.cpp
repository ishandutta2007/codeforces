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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7;

template<class T> class RMQ{
  vv<T> vals;
public:
  inline T get(int l,int r){//[l,r]
    if(l==r)return vals[0][l];
    const int d=31-__builtin_clz(l^r); //left-most distinct bit
    return min(vals[d][l],vals[d][r]);
  }
  RMQ(){};
  RMQ(vector<T> &v,T e=-MOD){ init(v,e); }
  void init(vector<T> &v,T e){
    int n=v.size();
    int d=1,N=2;
    while(N<n) N*=2, ++d;
    vals.resize(d,vector<T>(N,e));
    rep(i,n) vals[0][i]=v[i];
    reps(i,1,d)rep(j,N){
      const int b=(j>>i|1)<<i;
      vals[i][j]=j>>i&1?get(b,j):get(j,b-1);
    }
  }
};

typedef vv<int> Graph;
class Lca{
public:
  vector<int> dep,cld;
  vector<pii> et;
  vector<int> l,r;
  vector<ll> wdep;
  vector<int> par;
  int weighted;
  vv<int> wei;
  RMQ<pii> rmq;
  void dfs(const Graph &g,int root){
    int n=g.size();
    vector<int> vst(n);
    stack<int> st; st.push(root);
    while(!st.empty()){
      int v=st.top(); st.pop();
      if(vst[v]==1){
	vst[v]=2;
	r[v]=et.size()-1;
	rep(i,g[v].size())if(g[v][i]!=par[v])
	  cld[v]+=cld[g[v][i]]+1;
	if(par[v]>=0) et.eb(dep[par[v]],par[v]);
      }else if(vst[v]==0){
	st.push(v);
	vst[v]=1;
	l[v]=et.size(); et.eb(dep[v],v);
	rep(i,g[v].size())if(!vst[g[v][i]]){
	  dep[g[v][i]]=dep[v]+1;
	  wdep[g[v][i]]=wdep[v]+(weighted?wei[v][i]:1);
	  par[g[v][i]]=v;
	  st.push(g[v][i]);
	}
      }
    }
  }
  
  Lca(const Graph &g,int rt=0):weighted(0){
    int n=g.size();
    par.resize(n);
    dep.resize(n); wdep.resize(n); cld.resize(n); l.resize(n); r.resize(n); dfs(g,rt);
    rmq.init(et,pii(MOD,0));
  }
  Lca(const vv<pii> &h):weighted(1){
    int n=h.size();
    vv<int> g(n);
    wei.resize(n);
    rep(i,n) for(pii x:h[i]){
      g[i].pb(x.X);
      wei[i].pb(x.Y);
    }
    par.resize(n);
    dep.resize(n); wdep.resize(n); cld.resize(n); l.resize(n); r.resize(n); dfs(g,0);
    rmq.init(et,pii(MOD,0));
  }
  
  int LCA(int v,int w){
    v=l[v]; w=l[w];
    if(v>w) swap(v,w);
    return rmq.get(v,w).Y;
  }
  ll dist(int v,int w){return wdep[v]+wdep[w]-2*wdep[LCA(v,w)];}
};



int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n,x,y;
	cin>>n>>x>>y; --x; --y;
	vv<int> g(n);
	rep(i,n-1){
		int x,y;
		cin>>x>>y; --x; --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	vector<int> sz(n);
	function<int(int,int)> dfs=[&](int v,int p){
		int re=1;
		for(int w:g[v])if(w!=p) re+=dfs(w,v);
		return sz[v]=re;
	};
	Lca h(g);
	int p=h.LCA(x,y);
	if(p==x || p==y){ p=h.par[x^y^p]; }
	dfs(p,-1);
	int a=sz[x],b=sz[y];
	ll re=n*(n-1ll);
	if(p==x || p==y){
		ll x=min(a,b);
		re-=x*(n-x);
	}else{
		re-=1ll*a*b;
	}
	out(a,b,x,y,1);
	cout<<re<<endl;
  return 0;
}