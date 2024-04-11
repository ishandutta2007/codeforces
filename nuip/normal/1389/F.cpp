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
template<class A,class B,class C,class D> pair<A,B>& operator+=(const pair<A,B> &p,const pair<C,D> &q){ p.X+=p.X; q.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(const pair<A,B> &p,const pair<C,D> &q){ p.X-=p.X; q.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T> T read(){ T re; cin>>re; return move(re);}
template<class T> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
const ll MOD=1e9+7; //998244353

template<class T>
struct Max{
	T mx;
	Max(T v=0):mx(v){}
	Max operator+(const Max &seg){
		return Max(max(mx,seg.mx));
	}
  static Max e;
};
template<class T> Max<T> Max<T>::e=Max();
template<class T>ostream&  operator<<(ostream &os, const Max<T> &seg){ return os<<"("<<seg.mx<<")";}

template<class T>
struct Add{
	T ad;
  Add(T ad=0):ad(ad){}
	void operator+=(const Add &lfun){
		ad+=lfun.ad;
	}
	bool operator==(const Add &lfun){ return ad==lfun.ad;}

	void eval(Max<T> &s,int l,int r){
		s.mx+=ad;
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
		if(2*k+2<opes.size()){
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
	Seg operator()(int l,int r){ return query(l,r,0,0,segs.size()/2);};
	Seg operator()(){ return segs[0];};
};


int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read<int>();
	vector<tuple<int,int,int>> tps(n);
	for(auto &[r,l,t]:tps) cin>>l>>r>>t, --t;
	int m;
	{
		vector<int> xs;
		for(auto [l,r,ignore]:tps){
			xs.pb(l);
			xs.pb(r);
		}
		sort(all(xs)); UNIQUE(xs);
		for(auto &[l,r,ignore]:tps){
			l=lower_bound(all(xs),l)-xs.begin();
			r=lower_bound(all(xs),r)-xs.begin();
		}
		m=xs.size();
	}
	sort(all(tps));
	vector dp(2,LazySegTree<Max<int>,Add<int>>(m+5));
	for(cauto [r,l,t]:tps){
		dp[t](0,l+1,1);
		auto mx=dp[t]().mx;
		auto cur=dp[1-t](r+1,r+2).mx;
		if(cur<mx) dp[1-t](r+1,r+2,mx-cur);
		out(l,r,t,1);
		// rep(i,2){rep(j,m+5) cout<<dp[i](j,j+1); cout NL;} cout NL;
	}
	cout<<max(dp[0]().mx,dp[1]().mx) NL;
  return 0;
}