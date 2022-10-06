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

struct Seg{
	int mx;
  Seg(int d=0):mx(d){}
  static Seg e;
};
Seg Seg::e=Seg();

Seg operator+(const Seg &l,const Seg &r){
  return max(l.mx,r.mx);
}


template<class SegTree>
struct SegTreeUpdater{
	SegTree *st;
	int i;
	SegTreeUpdater(SegTree *st,int i):st(st),i(i){}
	template<class Seg> void operator+=(const Seg &seg){ st->add(i,seg);}
	template<class Seg> void operator=(const Seg &seg){	st->assign(i,seg);}
};

template<class Seg>
struct SegTree{
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
	template<class T=Seg> T query(int a,int b,int k,int l,int r){
		if(r<=a || b<=l)return T::e;
		if(a<=l && r<=b) return segs[k];
		T lv=query(a,b,k*2+1,l,(l+r)/2) ,rv= query(a,b,k*2+2,(l+r)/2,r);
		return lv+rv;
	}

	SegTree(int n){
		int pw=1;
		while(pw<n) pw*=2;
		segs.resize(2*pw);
	}
	SegTreeUpdater<SegTree<Seg>> operator[](int i){ return {this,i};}
	Seg operator()(int l,int r){ return query(max(0,l),min((int)segs.size()/2,r),0,0,segs.size()/2);};
	Seg& operator()(int i){ return segs[segs.size()/2-1+i];}
	Seg operator()(){ return segs[0];}
	Seg rb(int r){ return operator()(0,r); }
	Seg lb(int l){ return operator()(l,segs.size()/2); }
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto vs=readV(n,1);
	if(n<=2){
		cout<<n NL;
		return 0;
	}
	SegTree<Seg> st(n);
	int ad=1;
	reps(i,1,n){
		cauto prv=vs[i-1];
		cauto cur=vs[i];
		cauto v=(st.rb(cur)+st.lb(cur+1)).mx+ad+1;
		cauto w=st(cur).mx+ad;
		out(i,v,1);
		ad+=prv!=cur;
		st[prv]+=max(v,w)-ad;
		// rep(i,n) cout<<st(i).mx+ad<<","; cout NL;
	}
	cout<<st().mx+ad NL;
  return 0;
}