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
const ll MOD=1e9+7; //998244353

const ll INF=1e15;

template<class T,class G>
void dij(vv<pair<G,int>> &g,int s,vector<T> &d){
  typedef pair<T,G> Que;
  priority_queue<Que,vector<Que>,greater<Que> > que;
  int n=g.size();
  d.resize(n);
  fill(all(d),INF);
  d[s]=0;
  que.emplace(0,s);
  while(que.size()){
    Que p=que.top();que.pop();
    if(d[p.Y]<p.X)continue;
    for(auto e:g[p.Y]) if(MN(d[e.X],d[p.Y]+e.Y)) que.emplace(d[e.X],e.X);
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto q=read();
	cauto s=read(1);
	cauto m=17;
	vv<pair<int,int>> g(n+n*m+n*m);
	auto to=[&](int v,int lg){ return n+n*lg+v;};
	auto from=[&](int v,int lg){ return n+n*m+n*lg+v;};
	rep(v,n){
		g[to(v,0)].eb(v,0);
		reps(lg,1,m){
			g[to(v,lg)].eb(to(v,lg-1),0);
			if(auto tmp=v+(1<<(lg-1)); tmp<n) g[to(v,lg)].eb(to(tmp,lg-1),0);
		}
		g[v].eb(from(v,0),0);
		reps(lg,1,m){
			g[from(v,lg-1)].eb(from(v,lg),0);
			if(auto tmp=v+(1<<(lg-1)); tmp<n) g[from(tmp,lg-1)].eb(from(v,lg),0);
		}
	}
	rep(_,q){
		cauto t=read();
		if(t==1){
			cauto v=read(1);
			cauto u=read(1);
			cauto w=read();
			g[v].eb(u,w);
		}else{
			cauto v=read(1);
			cauto l=read(1);
			cauto r=read();
			cauto w=read();
			int lg=0,pw=1;
			while(l+pw*2<=r) pw*=2, ++lg;
			if(t==2){
				g[v].eb(to(l,lg),w);
				g[v].eb(to(r-pw,lg),w);
			}else{
				g[from(l,lg)].eb(v,w);
				g[from(r-pw,lg)].eb(v,w);
			}
		}
	}
	vector<ll> ds;
	dij(g,s,ds);
	rep(i,n) cout<<(ds[i]==INF?-1:ds[i])<<" \n"[i+1==n];
  return 0;
}