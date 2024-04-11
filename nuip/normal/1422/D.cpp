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
template<class T,class G>
void dij(vv<pair<G,T>> &g,int s,vector<T> &d){
	const ll INF=1e15;
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
	cauto m=read();
	cauto s=read<pii>({1,1});
	cauto f=read<pii>({1,1});
	cauto ps=readV<pii>(m,{1,1});
	vv<pll> g(m+m+1+1);
	vector<int> inds(m); iota(all(inds),0);
	sort(all(inds),[&](int i,int j){ return ps[i]<ps[j];});
	reps(i,1,m){
		cauto d=ps[inds[i]].X-ps[inds[i-1]].X;
		g[inds[i-1]].eb(inds[i],d);
		g[inds[i]].eb(inds[i-1],d);
	}
	sort(all(inds),[&](auto i,auto j){ return ps[i].Y<ps[j].Y;});
	reps(i,1,m){
		cauto d=ps[inds[i]].Y-ps[inds[i-1]].Y;
		g[m+inds[i-1]].eb(m+inds[i],d);
		g[m+inds[i]].eb(m+inds[i-1],d);
	}
	rep(i,m){
		g[i].eb(m+i,0);
		g[m+i].eb(i,0);
		g[m+m].eb(i,abs(ps[i].X-s.X));
		g[m+m].eb(m+i,abs(ps[i].Y-s.Y));
		g[i].eb(m+m+1,abs(ps[i].X-f.X)+abs(ps[i].Y-f.Y));
	}
	vector<ll> d;
	dij(g,m+m,d);
	ll re=min<ll>(d.back(),abs(s.X-f.X)+abs(s.Y-f.Y));
	cout<<re NL;
  return 0;
}