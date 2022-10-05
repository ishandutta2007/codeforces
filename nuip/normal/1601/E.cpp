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
#define rep(X,Y) for (int X = 0;X < (int)(Y);++X)
#define reps(X,S,Y) for (int X = (int)(S);X < (int)(Y);++X)
#define rrep(X,Y) for (int X = (int)(Y)-1;X >=0;--X)
#define rreps(X,S,Y) for (int X = (int)(Y)-1;X >= (int)(S);--X)
#define repe(X,Y) for (X = 0;X < (Y);++X)
#define peat(X,Y) for (;X < (Y);++X)
#define all(X) X.begin(),X.end()
#define rall(X) X.rbegin(),X.rend()
#define eb emplace_back
#define UNIQUE(X) X.erase(unique(all(X)),X.end())
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
#undef NUIP
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
#ifdef __cpp_deduction_guides
template<typename T> vector<T> readT(int n, T v){ return readV(n,v);}
template <class... Args> auto readT(int n, Args... args){ vector re(1,readT(args...));rep(_,n-1) re.eb(readT(args...));	return re;}
template<class Tuple, size_t... Is> void read_tuple_impl(istream &is, Tuple& t, index_sequence<Is...>){((is >> get<Is>(t)), ...);}
template<class... Args> auto& operator>>(istream &is, tuple<Args...>& t){ read_tuple_impl(is, t, index_sequence_for<Args...>{}); return is;}
template<class T> bool erase(multiset<T> &st, const T &v){if(cauto it=st.find(v); it==st.end()) return false; else{ st.erase(it); return true;}}
#endif
#ifdef __cpp_init_captures
template<typename T, size_t... Is> void addadd(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) += get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator += (tuple<T...>& lhs, const tuple<T...>& rhs){	addadd(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator +(tuple<T...> lhs, const tuple<T...>& rhs){ return lhs += rhs;}
template<typename T, size_t... Is> void subsub(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) -= get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator -= (tuple<T...>& lhs, const tuple<T...>& rhs){	subsub(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator - (tuple<T...> lhs, const tuple<T...>& rhs){ return lhs -= rhs;}
#endif
#define TT cauto TTT=read();rep(_,TTT)
struct sorted_impl{template<class T>friend vector<T>operator-(vector<T>a,sorted_impl){sort(all(a));return a;}}sorted;struct reversed_impl{template<class T>friend vector<T>operator-(vector<T> a,reversed_impl){reverse(all(a));return a;}}reversed;struct distinct_impl{template<class T>friend vector<T>operator-(vector<T> a,distinct_impl){sort(all(a));UNIQUE(a);return a;}}distinct;template<class S>struct sortedWith{const S f;sortedWith(const S &f):f(f){}template<class T>friend vector<T>operator-(vector<T> a,const sortedWith&b){sort(all(a),[&](cauto&i,cauto&j){return b.f(i)<b.f(j);});return a;}};
template<class T>int operator/(const T&v,const vector<T>&vs){return lower_bound(all(vs),v)-vs.begin();}
vector<int> Inds(const int n){vector<int> inds(n);iota(all(inds),0);return inds;}
const ll MOD=1e9+7; //998244353;

template<class T>
struct Sum{
	T v;
	Sum(T v=0):v(v){}
	Sum operator+(const Sum &seg){
		return Sum(v+seg.v);
	}
  static Sum e;
};
template<class T> Sum<T> Sum<T>::e=Sum();
template<class T>ostream&  operator<<(ostream &os, const Sum<T> &seg){ return os<<"("<<seg.v<<")";}

template<class T>
struct Add{
	T ad;
  Add(T ad=0):ad(ad){}
	void operator+=(const Add &lfun){
		ad+=lfun.ad;
	}
	bool operator==(const Add &lfun){ return ad==lfun.ad;}

	void eval(Sum<T> &s,int l,int r){
		s.v+=ad*(r-l);
	}
	static Add e;
};
template<class T> Add<T> Add<T>::e=Add();
template<class T>ostream&  operator<<(ostream &os, const Add<T> &lfun){ return os<<"("<<lfun.ad<<")";}

template<class Seg, class Ope>
struct LazySegTree{
	vector<Seg> segs;
	vector<Ope> opes;
	
	void lazy_eval(int k,int a,int b){
		if(opes[k]==Ope::e) return;
		opes[k].eval(segs[k],a,b);
		if(2*k+2<(int)opes.size()){
			opes[2*k+1]+=opes[k];
			opes[2*k+2]+=opes[k];
		}
		opes[k]=Ope::e;
	}
	void upd_node(int k){segs[k]=segs[2*k+1]+segs[2*k+2];}
	void upd(int l,int r,Ope ope,int k,int a,int b){
		lazy_eval(k,a,b);
		if(b<=l || r<=a) return; 
		if(l<=a && b<=r){
			opes[k]+=ope;
			lazy_eval(k,a,b);
			return;
		}	
		int m=(a+b)/2;
		upd(l,r,ope,2*k+1,a,m);
		upd(l,r,ope,2*k+2,m,b);
		upd_node(k);
	}
	void upd(int l,int r,Ope ope){ upd(l,r,ope,0,0,segs.size()/2);}

	Seg query(int l,int r,int k,int a,int b){
		lazy_eval(k,a,b);
		if(b<=l || r<=a)return Seg::e; 
		if(l<=a && b<=r){return segs[k];}
  
		int m=(a+b)/2;
		Seg vl=query(l,r,2*k+1,a,m);
		Seg vr=query(l,r,2*k+2,m,b);
		upd_node(k);
		return vl+vr;
	}

	LazySegTree(int n){
		int pw=1;
		while(pw<n) pw*=2;
		segs.resize(2*pw);
		opes.resize(2*pw);
	}
	template<class Int>
	LazySegTree(vector<Int> vs){
		int n=vs.size();
		int pw=1;
		while(pw<n) pw*=2;
		segs.resize(2*pw);
		opes.resize(2*pw);
		rep(i,n) segs[pw-1+i]=vs[i];
		rrep(i,pw-1) segs[i]=segs[i*2+1]+segs[i*2+2];
	}
	void operator()(int l,int r,Ope ope){ upd(l,r,ope,0,0,segs.size()/2);};
	void rb(int r,Ope ope){ operator()(0,r,ope); }
	void lb(int l,Ope ope){ operator()(l,segs.size()/2,ope); }
	Seg operator()(int l,int r){ return query(l,r,0,0,segs.size()/2);};
	Seg rb(int r){ return operator()(0,r); }
	Seg lb(int l){ return operator()(l,segs.size()/2); }
	Seg operator()(){ return segs[0];}
};

template<class T> class RMQ{
  vv<T> vals;
public:
  inline T get(int l,int r){//[l,r]
    if(l==r)return vals[0][l];
    const int d=31-__builtin_clz(l^r); //left-most distinct bit
    return min(vals[d][l],vals[d][r]);
  }
  RMQ(const vector<T> &v,T e=MOD){
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


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);

	cauto n=read();
	cauto q=read();
	cauto t=read();
	cauto vs=readV(n);
	cauto qs=readV<pii>(q,{1,0});

	// const ll n=300000,q=300000,t=300000;
	// vector<ll> vs(n,1);
	// vector<pii> qs(q,{3,5});
	
	vv<int> inds(n);
	rep(i,q) inds[qs[i].X].eb(i);
	vv<pll> stks(t);
	rep(i,t) stks[i].eb(-1,n/t+1);
	vector sts(t,LazySegTree<Sum<ll>,Add<ll>>(n/t+3));
	cauto upd=
		[&](const int r,const int i,const ll v){
			auto &stk=stks[r];
			auto &st=sts[r];
			while(stk.back().X>=v){
				cauto [old,l]=stk.back(); stk.pop_back();
				st(l,stk.back().Y,-old);
			}
			st(i,stk.back().Y,v);
			stk.eb(v,i);
			out(r,i,v,1);
		};
	RMQ<ll> rmq(vs);
	vector<ll> re(q);
	rrep(d,n){
		cauto r=d%t;
		auto &st=sts[r];
		upd(r,d/t,vs[d]);
		out(d,stks[r],1);
		for(cauto i:inds[d]){
			cauto rb=qs[i].Y;
			re[i]=st(0,(rb-r-1)/t+1).v;
		}
		if(d-t>=0){
			upd(r,d/t,rmq.get(d-t+1,d));
		}
		out(d,stks[r],1);
	}
	for(cauto &x:re) cout<<x NL;
	return 0;
}