#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto q=read();
	vv<pii> g(n);
	/**/
	rep(i,n-1){
		cauto v=read(1);
		cauto w=read(1);
		cauto c=read<char>();
		g[v].eb(w,c);
		g[w].eb(v,c);
	}
	auto qs=readV<pii>(q,{1,1});
	/*/
	vector<int> ind(n); iota(all(ind),0);
	mt19937 rand(2); shuffle(all(ind),rand);
	rep(i,n-1){
		cauto v=ind[i];
		cauto w=ind[i+1];
		cauto c='a';
		g[v].eb(w,c);
		g[w].eb(v,c);
	}
	vector<pii> qs(q);
	rep(i,q) qs[i]={i,0};
	/**/

	{
		vector<int> seq(n);
		vector<int> inv(n,-1);
		seq.resize(1); seq[0]=0;
		fill(all(inv),-1); inv[0]=0;
		rep(v,n){
			cauto v0=seq[v];
			for(auto [w0,c]:g[v0])if(inv[w0]<0){
					int w=seq.size();
					seq.pb(w0);
					inv[w0]=w;
				}
		}
		vv<pii> h=g;
		rep(v,n) g[v].clear();
		rep(v,n)for(auto [w,c]:h[v]) g[inv[v]].eb(inv[w],c);
		for(auto &[v,w]:qs) v=inv[v], w=inv[w];
	}
	out(g,1);
	
	vv<int> invs(n);
	rep(i,q) invs[qs[i].X].pb(i);
	vector<int> re(q);
	vector<int> deps(n);
	vector<pii> pars(n);
	vector<int> seq(n);
	vector<int> inv(n,-1);
	vector<int> invd(n);
	rep(rt,n)if(invs[rt].size()){
		deps[rt]=0;
		seq.resize(1); seq[0]=rt;
		fill(all(inv),-1); inv[rt]=0;
		invd.resize(1);
		rep(v,n){
			cauto v0=seq[v];
			for(auto [w0,c]:g[v0])if(inv[w0]<0){
					int w=seq.size();
					seq.pb(w0);
					inv[w0]=w;
					deps[w]=deps[v]+1;
					pars[w]={v,c};
					if(deps[w]!=deps[w-1]) invd.pb(w);
				}
		}
		invd.pb(n);
		out(deps,pars,seq,1);
		for(int i:invs[rt]){
			auto v=inv[qs[i].Y];
			const int d=deps[v];
			vector<tuple<int,int,int>> subs(n);
			reps(i,0,invd[d]) ++get<0>(subs[i]);
			reps(i,invd[d],invd[d+1]) ++get<1>(subs[i]);
			reps(i,invd[d+1],n) ++get<2>(subs[i]);
			out(v,d,1);
			rreps(w,1,n){
				if(deps[w]<deps[v]) v=pars[v].X;
				cauto c=(deps[w]>deps[v]?0:pars[v].Y);
				cauto [p,d]=pars[w];
				out(w,c,p,d,1);
				cauto &[x,y,z]=subs[w];
				if(c<d){
					get<2>(subs[p])+=x+y+z;
				}else if(c==d){
					get<0>(subs[p])+=x;
					get<1>(subs[p])+=y;
					get<2>(subs[p])+=z;
				}else{
					get<0>(subs[p])+=x+y+z;
				}
			}
			out(subs,1);
			re[i]=get<0>(subs[0]);
		}
	}
	out(re,1);
	for(auto x:re) cout<<x-1 NL;
  return 0;
}