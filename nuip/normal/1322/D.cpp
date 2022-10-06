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
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"

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
const ll MOD=1e9+7; //998244353

struct Seg{
	int mx;
  Seg(int d=-MOD):mx(d){}
  static Seg e;
};
Seg Seg::e=Seg();

Seg operator+(Seg &l,Seg &r){
  return max(l.mx,r.mx);
}

template<class SegTree>
struct SegTreeUpdater{
	SegTree *st;
	int i;
	SegTreeUpdater(SegTree *st,int i):st(st),i(i){}
	template<class Seg>
	void operator+=(const Seg &seg){
		st->add(i,seg);
	}
	void operator=(const Seg &seg){
		st->assign(i,seg);
	}
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
	Seg operator()(int i){ return segs[segs.size()/2-1+i];}
	Seg operator()(){ return segs[0];}
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>n>>m;
	vector<pii> acs(n);
	rep(i,n) cin>>acs[i].X, --acs[i].X;
	rep(i,n) cin>>acs[i].Y;
	vector<int> pros(n+m);
	rep(i,n+m) cin>>pros[i];
	reverse(all(acs));

	vector segs(2123,SegTree<Seg>(2000));
	for(auto [agg,cost]:acs){
		rreps(i,1,n){
			int v=segs[agg](i).mx;
			for(int l=i*2,r=i*2+2,a=agg-1;l<n&&a>=0;l*=2,MN(r*=2,n),--a){
				MX(v,segs[a](l,r).mx);
			}
			if(v==-MOD) continue;
			out(agg,cost,i,v,1);
			v-=cost;
			for(int st=i^(i+1),d=agg;st;st/=2,++d) v+=pros[d];
		  // segs[agg].upd(i+1,Seg(v));
		  segs[agg][i+1]+=Seg(v);
		}
		int v=0;
		int ub=1;
		rrep(a,agg){
			MN(ub*=2,n);
			MX(v,segs[a](0,ub).mx);
		}
		out(agg,cost,v,1);
		v+=pros[agg]-cost;
		segs[agg][1]+=Seg(v);
		// rep(i,6){rep(j,6) cout<<dats[i][nn-1+j].mx<<",";cout NL;} cout NL;
	}
	int re=0;
	rep(i,segs.size()) MX(re,segs[i]().mx);
	cout<<re NL;
  return 0;
}