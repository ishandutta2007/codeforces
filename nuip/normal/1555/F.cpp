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
void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return re;}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return re;}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return re;}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return g;}
vv<int> readG(const int &n){ return readG(n,n-1);}
vv<int> readD(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); } return g;}
vv<int> readD(const int &n){ return readD(n,n-1);}
template<class T> vv<pair<int,T>> readG(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); g[b].eb(a,c);} return g;}
template<class T> vv<pair<int,T>> readG(const int &n){ return readG<T>(n,n-1);}
template<class T> vv<pair<int,T>> readD(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); } return g;}
template<class T> vv<pair<int,T>> readD(const int &n){ return readD<T>(n,n-1);}
#ifdef __cpp_init_captures
template<typename T> vector<T> readT(int n, T v){ return readV(n,v);}
template <class... Args> auto readT(int n, Args... args){ vector re(1,readT(args...));rep(_,n-1) re.eb(readT(args...));	return re;}
template<typename T, size_t... Is> void addadd(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) += get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator += (tuple<T...>& lhs, const tuple<T...>& rhs){	addadd(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator +(tuple<T...> lhs, const tuple<T...>& rhs){ return lhs += rhs;}
template<typename T, size_t... Is> void subsub(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) -= get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator -= (tuple<T...>& lhs, const tuple<T...>& rhs){	subsub(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator - (tuple<T...> lhs, const tuple<T...>& rhs){ return lhs -= rhs;}
template<class Tuple, size_t... Is> void read_tuple_impl(istream &is, Tuple& t, index_sequence<Is...>){((is >> get<Is>(t)), ...);}
template<class... Args> auto& operator>>(istream &is, tuple<Args...>& t){ read_tuple_impl(is, t, index_sequence_for<Args...>{}); return is;}
#endif
#define TT cauto TTT=read();rep(_,TTT)
const ll MOD=1e9+7; //998244353;

struct UF{
  vector<int> data;
  UF(const int &size):data(size,-1){}
  int unite(int x, int y){
    x=root(x); y=root(y);
    if(x==y) return 0;
		if(-data[y]>-data[x]) swap(x,y);
		data[x]+=data[y]; data[y]=x;
    return y+1;
  }
  bool findSet(const int &x, const int &y){ return root(x)==root(y);}
  int root(const int &x){ return data[x]<0?x:data[x]=root(data[x]);}
  int size(const int &x){ return -data[root(x)];}
	int size(){ return count_if(all(data),[](const int &x){ return x<0;});}; //unverified
	int operator()(const int &x, const int &y){ return unite(x,y);}
	int operator()(const pii &xy){ return unite(xy.X,xy.Y);}
	int operator[](const int &x){ return root(x);}
	bool operator[](const pii &xy){ return findSet(xy.X,xy.Y);}
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
	vector<int> pathp(int v,int p){
		vector<int> re;
		out(v,p,par,1);
		for(int i=v;i!=p;i=par[i]) re.pb(i);
		re.pb(p);
		return re;
	}
	vector<int> path(int v,int w){
		int p=LCA(v,w);
		vector<int> a=pathp(v,p);
		vector<int> b=pathp(w,p);
		b.pop_back();
		reverse(all(b));
		a.insert(a.end(),all(b));
		return a;
	}
};

struct Seg{
	int mx;
  Seg(int d=-MOD):mx(d){}
  static Seg e;
};
Seg Seg::e=Seg();

Seg operator+(const Seg &l,const Seg &r){
  return max(l.mx,r.mx);
}

template<class Seg>
struct CoSegTree{
	vector<Seg> segs;
	void add(int k,Seg a){
		k+=segs.size()/2-1;
		segs[k]=segs[k]+a;
		upd(k);
	}
	void assign(int k,Seg a){
		k+=segs.size()/2-1;
		segs[k]=a;
		upd(k);
	}
	void upd(int k){
		while(k>0){
			k=(k-1)/2;
			segs[k]=segs[k*2+1]+segs[k*2+2];
		}
	}
	void upd(){	rrep(k,segs.size()/2-1) segs[k]=segs[k*2+1]+segs[k*2+2];}
	
	//(l,r,0,0,nn)
	void upd(int a,int b,const Seg &seg){
		upd(a,b,seg,0,0,segs.size()/2);
	}
	void upd(int a,int b,const Seg &seg,int k,int l,int r){
		if(r<=a || b<=l) return;
		if(a<=l && r<=b){
			out(l,r,1);
			segs[k]=segs[k]+seg;
			return;
		}
		upd(a,b,seg,k*2+1,l,(l+r)/2);
		upd(a,b,seg,k*2+2,(l+r)/2,r);
	}
	Seg query(int x){
		x+=segs.size()/2-1;
		auto re=segs[x];
		while(x>0){
			x=(x-1)/2;
			re=re+segs[x];
		}
		return re;
	}

	CoSegTree(int n){
		int pw=1;
		while(pw<n) pw*=2;
		segs.resize(2*pw);
	}
	void operator()(int l,int r,const Seg &seg){ upd(max(0,l),min((int)segs.size()/2,r),seg);}
	Seg operator[](const int &i){ return query(i);}
	Seg rb(int r){ return operator()(0,r); }
	Seg lb(int l){ return operator()(l,segs.size()/2); }
};


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto m=read();
	cauto es=readV<tuple<int,int,int>>(m,{1,1,0});
	vector<int> re(m);
	vv<int> g(n);
	vector<int> vals(n),deps(n);
	vector<int> et,ls(n),rs(n);
	{
		vv<pii> G(n);
		UF uf(n);
		rep(i,m){
			cauto &[a,b,c]=es[i];
			if(uf(a,b)){
				re[i]=1;
				g[a].eb(b);
				g[b].eb(a);
				G[a].eb(b,c);
				G[b].eb(a,c);
			}
		}
		rep(v,n)if(uf(0,v)){
			G[0].eb(v,0);
			G[v].eb(0,0);
			g[0].eb(v);
			g[v].eb(0);
		}
		cauto dfs=
			[&](auto &&dfs,int v,int p)->void{
				ls[v]=et.size();
				et.eb(v);
				for(cauto &[u,c]:G[v]){
					if(u==p) continue;
					vals[u]=vals[v]^c;
					deps[u]=deps[v]+1;
					dfs(dfs,u,v);
				}
				rs[v]=et.size();
			};
		dfs(dfs,0,-1);
	}
	CoSegTree<Seg> st(n);
	Lca h(g);
	// rep(v,n)for(cauto &u:g[v])if(v<u) cout<<v<<" "<<u NL;
	out(et,1);
	rep(i,m)if(!re[i]){
		cauto &[a,b,c]=es[i];
		if((vals[a]^vals[b]^c)==0) continue;
		cauto p=h.LCA(a,b);
		if(st[ls[a]].mx>=deps[p]) continue;
		if(st[ls[b]].mx>=deps[p]) continue;
		re[i]=1;
		// cout<<a<<" "<<b NL;
		out(a,b,p,1);
		for(auto v=a;v!=p;v=h.par[v]) st(ls[v],rs[v],deps[v]-1);
		for(auto v=b;v!=p;v=h.par[v]) st(ls[v],rs[v],deps[v]-1);
	}
	for(cauto &x:re) cout<<(x?"YES":"NO") NL;
	return 0;
}