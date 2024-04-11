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

void solve(const vv<int> &g,const vector<pii> &es){
	const int n=g.size();
	vector<int> vst(n);
	vector<pii> re;
	vector<int> usd(es.size());
	cauto dfs=
		[&](auto &&dfs,int v,int pe)->bool{
			if(!MX(vst[v],1)) return true;
			int rem=-1;
			for(cauto &e:g[v]){
				if(!MX(usd[e],1)) continue;
				cauto u=es[e].X^es[e].Y^v;
				out(v,u,e,1);
				if(dfs(dfs,u,e)){
					if(rem>=0){
						re.eb(rem,e);
						rem=-1;
					}else{
						rem=e;
					}
				}
			}
			if(rem<0 || pe<0) return true;
			re.eb(rem,pe);
			return false;
		};
	rep(v,n) dfs(dfs,v,-1);
	out(re,1);
	cout<<re.size() NL;
	for(cauto &[a,b]:re) cout<<a+1<<" "<<b+1 NL;
}

void solve(vector<pii> es,int n){
	vv<int> g(n);
	rep(i,es.size()){
		g[es[i].X].eb(i);
		g[es[i].Y].eb(i);
	}
	solve(g,es);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	// solve({{0,1},{1,2},{1,2},{2,3}},4);
	// solve({{0,1},{1,2},{0,2},{2,3},{3,4},{4,5},{5,6},{6,3}},8);
	// return 0;
	cauto n=read();
	vector<pll> ps;
	map<pll,int> inv;
	vv<int> g;
	vector<pii> es;
	cauto get=
		[&](pll p){
			cauto [it,f]=inv.emplace(p,ps.size());
			if(f){
				ps.eb(p);
				g.eb();
			}
			return it->Y;
		};
	rep(e,n){
		cauto a=read();
		cauto b=read();
		cauto c=read();
		cauto d=read();
		int u,v;
		{
			cauto p=c*b;
			cauto q=d*(a+b);
			cauto g=__gcd(p,q);
			u=get({p/g,q/g});
		}
		{
			cauto p=(c+d)*b;
			cauto q=d*a;
			cauto g=__gcd(p,q);
			v=get({p/g,q/g});
		}
		g[u].eb(e);
		g[v].eb(e);
		es.eb(u,v);
	}
	out(g,1);
	solve(g,es);
  return 0;
}