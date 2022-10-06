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
template<class T=ll> T read(){ T re; cin>>re; return move(re);}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
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

using tp=tuple<int,int,int>;

ll naive(const int n, const vector<tp> &es){
	auto g=table(n,n,0);
	int x=0;
	for(cauto [u,v,w]:es){
		x^=w;
		g[u][v]=g[v][u]=w;
	}
	ll re=1e18;
	rep(i,n)rep(j,i){
		if(g[i][j]) continue;
		g[i][j]=x;
		vector<tp> es;
		rep(i,n)rep(j,i) es.eb(g[i][j],i,j);
		sort(all(es));
		ll sum=0;
		UF uf(n);
		for(cauto &[w,u,v]:es)if(uf(u,v)) sum+=w;
		MN(re,sum);
		g[i][j]=0;
	}
	return re;
}
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

ll solve(const int n, const vector<tp> &es){
	const int m=es.size();
	vv<pii> g(n);
	ll x=0;
	set<tuple<int,int,int>> une;
	for(cauto &[u,v,w]:es){
		g[u].eb(v,w);
		g[v].eb(u,w);
		x^=w;
		une.emplace(w,min(u,v),max(u,v));
	}
	set<int> unu; reps(i,1,n) unu.emplace(i);
	queue<int> que; que.emplace(0);
	priority_queue<tp,vector<tp>,greater<tp>> pq;
	int zeros=0;
	ll re=0;
	vv<int> tree(n);
	vector<int> sums(n);
	while(1){
		while(que.size()){
			cauto v=que.front(); que.pop();
			set<int> ban;
			for(cauto [u,w]:g[v]){
				cauto it=unu.find(u);
				if(it==unu.end()) continue;
				pq.emplace(w,u,v);
				unu.erase(it);
				ban.emplace(u);
			}
			for(cauto &u:unu){
				++zeros;
				que.emplace(u);
				tree[v].eb(u);
				sums[u]=sums[v]+1;
			}
			unu=ban;
		}
		if(unu.empty()) break;
		while(que.empty()){
			cauto [w,u,v]=pq.top(); pq.pop();
			cauto it=unu.find(u);
			if(it==unu.end()) continue;
			unu.erase(it);
			que.emplace(u);
			une.erase(une.find({w,min(u,v),max(u,v)}));
			tree[v].eb(u);
			sums[u]=sums[v];
			re+=w;
		}
	}
	if(n*(n-1ll)/2==m+zeros){
		int mn=x;
		// out(mn,sums,1);
		Lca lca(tree);
		for(cauto [w,u,v]:une){
			// out(u,v,w,lca.LCA(u,v),sums[u]+sums[v]-2*sums[lca.LCA(u,v)],1);
			if(sums[u]+sums[v]-2*sums[lca.LCA(u,v)]){
				MN(mn,w);
				break;
			}
		}
		re+=mn;
	}
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	if(0){
		reps(n,2,10)rep(_,1000){
			vector<tp> es;
			rep(i,n)rep(j,i) es.eb(i,j,rand()%10+1);
			random_shuffle(all(es));
			es.pop_back();
			while(es.size()){
				cauto act=solve(n,es);
				cauto exp=naive(n,es);
				if(act!=exp){
					out(act,exp,n,es,1);
					return 0;
				}
				es.pop_back();
			}
		}
		return 0;
	}
	cauto n=read();
	cauto m=read();
	vector<tp> es(m);
	for(auto &[a,b,c]:es) cin>>a>>b>>c, --a, --b;
	cout<<solve(n,es) NL;
  return 0;
}