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
// #undef NUIP
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

vector<tuple<int,int,int,int>> solve(const vv<int> &g0){
	const int n=g0.size();
	vv<int> g(n);
	vector<tuple<int,int,int,int>> re;
	{
		vector<pii> es;
		cauto dfs=
			[&](auto &&dfs,int v,int p)->void{
				for(cauto &u:g0[v])if(u!=p){
						dfs(dfs,u,v);
					}
				if(p>=0) es.eb(v,p);
			};
		dfs(dfs,0,-1);
		out(es,1);
		UF uf(n);
		vector<int> degs(n);
		rep(v,n) degs[v]=g0[v].size();
		out(degs,1);
		vector<pii> rms;
		for(cauto &[u,v]:es){
			if(degs[v]>=3 && degs[u]>=3){
				rms.eb(u,v);
				--degs[v];
				--degs[u];
			}else{
				g[v].eb(u);
				g[u].eb(v);
				uf(v,u);
			}
		}
		vv<int> mems(n);
		cauto get=
			[&](cauto &v){
				auto &vec=mems[uf[v]];
				out(v,vec,1);
				while(g[vec.back()].size()>1) vec.pop_back();
				return vec.back();
			};
		rep(v,n)if(g[v].size()==1) mems[uf[v]].eb(v);
		out(rms,g,mems,1);
		for(cauto &[u,v]:rms){
			cauto a=get(u);
			cauto b=get(v);
			re.eb(u,v,a,b);
			g[a].eb(b); ++degs[a];
			g[b].eb(a); ++degs[b];
			{
				auto x=uf[a];
				auto y=uf[b];
				uf(a,b);
				cauto z=uf[a];
				if(x!=z) swap(x,y);
				if(mems[x].size()<mems[y].size()) swap(mems[x],mems[y]);
				mems[x].insert(mems[x].end(),all(mems[y]));
			}
		}
	}
	// out(re,1);
	int last=-1;
	cauto dfs=
		[&](auto &&dfs,int v,int p)->void{
			int leaf=1;
			for(cauto &u:g[v])if(u!=p){
					if(!leaf){
						re.eb(v,u,u,last);
					}
					leaf=0;
					dfs(dfs,u,v);
				}
			if(leaf) last=v;
		};
	rep(v,n)if(g[v].size()==1){
		dfs(dfs,v,-1);
		break;
	}
	return re;
}

namespace random_graph{
	mt19937 rand(123);
	vv<int> tree(int n){
		vv<int> g(n);
		vector<int> ind(n); iota(all(ind),0);
		shuffle(all(ind),rand);
		reps(i,1,n){
			int a=ind[i];
			int b=ind[rand()%i];
			g[a].pb(b);
			g[b].pb(a);
		}
		return g;
	}
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	if(0){
		reps(n,2,200)rep(_,1000){
			cauto g=random_graph::tree(n);
			cauto re=solve(g);
		}
		return 0;
	}
	TT{
		cauto n=read();
		cauto g=readG(n);
		cauto re=solve(g);
		cout<<re.size() NL;
		for(cauto &[a,b,c,d]:re) cout<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1 NL;
	}
  return 0;
}