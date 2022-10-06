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
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const deque<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class S, class T,class U,class V,class W> ostream& operator<<(ostream &os, const tuple<S,T,U,V,W> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<","<<get<4>(t)<<")";}
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

// par[] : sep.dec tree
// for(int v: [sepDec] ) dfs
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
  
  Lca():weighted(0){}
	void gen(const Graph &g){
    int n=g.size();
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

Lca h;

vector<int> memo(212345,-1);
vector<pii> his;
vv<int> g;
//int ans=114;

int dist(int v){
	if(memo[v]>=0) return memo[v];
	// int n=his.size();
	// rep(i,n)rep(j,i){
	// 	int v,d,V,D;
	// 	tie(v,d)=his[i];
	// 	tie(V,D)=his[j];
	// 	if(d>D){ swap(v,V); swap(d,D);}
	// 	if(d+D==h.dist(v,V)){ // v--x--V

	// 	}else if(d+h.dist(v,V)==D){ // V--v--x

	// 	}
	// }
	cout<<"d "<<v+1<<endl;
	int re;
	cin>>re;
	// re=abs(ans-v);
	if(re<0) exit(0);
	if(!re){
		cout<<"! "<<v+1<<endl;
		exit(0);
	}
	his.eb(v,re);
	return memo[v]=re;
}
vector<int> memod(212345,-1);
int dwn(int v){
	if(memod[v]>=0) return memod[v];
	if(g[v].size()==1) return g[v][0];
	cout<<"s "<<v+1<<endl;
	int re;
	cin>>re;
	if(re<0) exit(0);
	--re;
	return memod[v]=re;
}


int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	g.resize(n);
	rep(i,n-1){
		int a,b;
		// a=i; b=i+1;
		cin>>a>>b; --a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	sepDec sd(g);
	h.gen(g);
	vector<int> vs=sd; reverse(all(vs));
	vector<int> dep(n);
	function<void(int,int,int)> dfs=
		[&](int v,int p,int d){
			dep[v]=d;
			for(int w:g[v])if(w!=p) dfs(w,v,d+1);
		};
	// iota(all(dep),0);
	dfs(0,-1,0);
	// out(vs,dep,1);
	vector<int> ex(n,1);
	int prv=-1,prvd;
	{
		int v=vs[0];
		while(1){
			out(v,1);
			ex[v]=0;
			int d0=dist(v);
			int mn=dep[v],W=-1;
			for(int w:g[v])if(MN(mn,dep[w])) W=w;
			int nxt;
			if(W<0){
				nxt=dwn(v);
				if(prv<0){prv=v; prvd=d0;	}
			}else{
				int d1;
				if(prv<0){
					d1=dist(W);
				}else{
					if(prvd==h.dist(prv,v)+d0){
						d1=d0+1;
					}else{
						d1=d0-1;
					}
				}
				if(d1<d0){
					nxt=W;
				}else{
					nxt=dwn(v);
					if(prv<0){prv=v; prvd=d0;	}
				}
			}
			vector<int> vst(n); vst[nxt]=1;
			queue<int> que; que.emplace(nxt);
			while(que.size()){
				int w=que.front(); que.pop();
				if(sd.par[w]==v){ nxt=w; break;}
				for(int u:g[w])if(ex[u] && MX(vst[u],1)) que.emplace(u);
			}
			v=nxt;
		}
	}
  return 0;
}