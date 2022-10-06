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

const int INF=1e8;

template<class T>
struct MinMax{
	T mn;
	MinMax(T v):mn(v){}
	MinMax():mn(INF){};
	MinMax operator+(const MinMax &seg){
		return MinMax(min(mn,seg.mn));
	}
  static MinMax e;
};
template<class T> MinMax<T> MinMax<T>::e=MinMax();
template<class T>ostream&  operator<<(ostream &os, const MinMax<T> &seg){ return os<<"("<<seg.mn<<")";}

template<class T>
struct Add{
	T ad;
	bool reset;
  Add(T ad=INF,bool f=false):ad(ad),reset(f){}
	void operator+=(const Add &lfun){
		if(lfun.reset){
			*this=lfun;
		}else{
			MN(ad,lfun.ad);
		}
	}
	bool operator==(const Add &lfun){ return ad==lfun.ad && reset==lfun.reset;}

	void eval(MinMax<T> &s,int l,int r){
		if(reset) s.mn=INF;
		MN(s.mn,ad);
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
	void reset(){
		out("reset",1);
		upd(0,segs.size()/2,Ope(INF,true));
		out(operator()(0,1),1);
	}
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto ps=readV<pii>(n,{1,1});
	cauto no=[](){cout<<-1 NL; exit(0);};	
	for(cauto &[a,b]:ps)if(min(a,b)>=n || max(a,b)<n) no();
	vector<pii> vfs(n);
	for(cauto &[a,b]:ps) vfs[max(a,b)-n]={n-min(a,b),a<b};
	out(vfs,1);
	int prv=-1;
	LazySegTree<MinMax<int>,Add<int>> neg(n+1),pos(n+1);
	neg(0,1,0);
	pos(0,1,0);
	int nead=0,poad=0;
	for(cauto &[v,isP]:vfs){
		cauto ne=neg(0,v).mn+isP+nead;
		cauto po=pos(0,v).mn+1-isP+poad;
		if(prv>v){
			neg.reset();
			pos.reset();
		}else{
			if(isP) ++poad;
			else ++nead;
		}
		pos(prv,prv+1,ne-poad);
		neg(prv,prv+1,po-nead);
		out(v,isP,poad,nead,1);
		// rep(i,n+1) cout<<pos(i,i+1); cout NL;
		// rep(i,n+1) cout<<neg(i,i+1); cout NL;
		prv=v;
	}
	int re=n+1;
	MN(re,pos().mn+poad);
	MN(re,neg().mn+nead);
	cout<<(re>n?-1:re) NL;
  return 0;
}