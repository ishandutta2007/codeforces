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

template<class T>
struct MinMax{
	T sum;
	MinMax(T v=0):sum(v){}
	MinMax operator+(const MinMax &seg){
		return MinMax(sum+seg.sum);
	}
  static MinMax e;
};
template<class T> MinMax<T> MinMax<T>::e=MinMax();
template<class T>ostream&  operator<<(ostream &os, const MinMax<T> &seg){ return os<<"("<<seg.sum<<")";}

template<class T>
struct Add{
	T ad;
  Add(T ad=-1):ad(ad){}
	void operator+=(const Add &lfun){
		if(lfun.ad>=0) ad=lfun.ad;
	}
	bool operator==(const Add &lfun){ return ad==lfun.ad;}

	void eval(MinMax<T> &s,int l,int r){
		if(ad>=0) s.sum=ad*(r-l);
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

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	TT{
		cauto n=read();
		cauto q=read();
		cauto s=read<string>();
		cauto t=read<string>();
		cauto ps=readV<pii>(q,{1,0});
		vector<int> vs(n);
		rep(i,n) vs[i]=t[i]-'0';
		LazySegTree<MinMax<int>,Add<int>> st(vs);
		int ng=0;
		rrep(i,q){
			cauto [l,r]=ps[i];
			cauto one=st(l,r).sum;
			cauto zero=r-l-one;
			if(one==zero){ ng=1; break;}
			st(l,r,(one<zero?0:1));
			// rep(i,n)cout<<st(i,i+1).sum;cout NL;
		}
		if(!ng) rep(i,n)if(s[i]-'0'!=st(i,i+1).sum){ ng=1; break;}
		cout<<(ng?"NO":"YES") NL;
	}
  return 0;
}