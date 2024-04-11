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

struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(data[y]<data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
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
  
  Lca(const Graph &g):weighted(0){
    int n=g.size();
    par.resize(n);
    dep.resize(n); wdep.resize(n); cld.resize(n); l.resize(n); r.resize(n); dfs(g,0);
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

vector<int> dep,par,ind;
vector<pii> upd[512345];
vector<int> mnv[512345];

void dfs(const vv<int> &g,int v,int p,int id,int d){
	dep[v]=d;
	par[v]=p;
	ind[v]=id;
	rep(i,g[v].size())if(g[v][i]!=p) dfs(g,g[v][i],v,i,d+1);
}
priority_queue<pii,vector<pii>,greater<pii>> ques[512345];
ll re;
int inf;
void dfs(const vv<int> &g,int v,int p){
	mnv[v].resize(g[v].size());
	sort(all(upd[v]));
	int t=MOD;
	for(auto p:upd[v])if(MN(t,p.Y)) ques[v].emplace(p);
	upd[v].clear();
	for(int w:g[v])if(w!=p){
			dfs(g,w,v);
			while(ques[w].size() && ques[w].top().Y>=dep[w]) ques[w].pop();
			if(ques[v].size()<ques[w].size()) swap(ques[v],ques[w]);
			while(ques[w].size()){
				auto p=ques[w].top(); ques[w].pop();
				if(p.Y>=dep[v]) continue;
				ques[v].emplace(p);
			}
		}
	while(ques[v].size() && ques[v].top().Y>=dep[v]) ques[v].pop();
	if(p>=0 && ques[v].size()) mnv[p][ind[v]]=ques[v].top().X;
	// if(p>=0){
	// 	if(ques[v].size()){
	// 		re+=ques[v].top().X;
	// 	}else{
	// 		inf=1;
	// 	}
	// }
}

signed main(){
	int n,t,m;
	scanf("%d%d%d",&n,&t,&m);
	dep.resize(n);
	par.resize(n);
	ind.resize(n);
	vv<int> g(n);
	UF uf(n);
	rep(i,t){
		int a,b;
		scanf("%d%d",&a,&b);
	  --a; --b;
		g[a].pb(b);
		g[b].pb(a);
		uf.unite(a,b);
	}
	vector<int> deg(n);
	rep(i,n) deg[i]=g[i].size();
	vector<pair<pii,int>> qs;
	rep(i,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a; --b;
		if(uf.unite(a,b)){
			g[a].pb(b);
			g[b].pb(a);
		}else{
			qs.eb(pii(a,b),c);
		}
	}
	dfs(g,0,-1,0,0);
	{
		Lca h(g);
		for(auto pp:qs){
			int a,b; tie(a,b)=pp.X;
			int p=h.LCA(a,b);
			if(p!=a) upd[a].eb(pp.Y,dep[p]);
			if(p!=b) upd[b].eb(pp.Y,dep[p]);
		}
	}
	dfs(g,0,-1);
	rep(i,n) out(i,g[i],mnv[i],1);
	ll re=0,inf=0;
	rep(i,n)rep(j,deg[i]){
		re+=mnv[i][j];
		if(mnv[i][j]==0 && par[i]!=g[i][j]) inf=1;
	}
	if(inf){
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",re);
  return 0;
}