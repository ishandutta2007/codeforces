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

template<class T>
struct Seg{
	T s;
	Seg (T s=MOD):s(s){}
	Seg operator+(const Seg &seg){
		return min(s,seg.s);
	}
  static Seg e;
};
template<class T> Seg<T> Seg<T>::e=Seg();
template<class T>ostream&  operator<<(ostream &os, const Seg<T> &seg){ return os<<"("<<seg.s<<")";}

template<class T>
struct Lfun{
	T ad;
  Lfun(T a=0):ad(a){}
	void operator+=(const Lfun &lfun){
		ad+=lfun.ad;
	}
	bool operator==(const Lfun &lfun){ return ad==lfun.ad;}

	void eval(Seg<T> &s,int l,int r){
		s.s+=ad;
	}
	static Lfun e;
};
template<class T> Lfun<T> Lfun<T>::e=Lfun();
template<class T>ostream&  operator<<(ostream &os, const Lfun<T> &lfun){ return os<<"("<<lfun.a<<","<<lfun.b<<")";}

template<class Seg, class Ope>
struct SegTree{
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

	SegTree(int n){
		int pw=1;
		while(pw<n) pw*=2;
		segs.resize(2*pw);
		opes.resize(2*pw);
		rep(i,n) segs[pw-1+i]=0;
		rrep(i,pw-1) segs[i]=segs[i*2]+segs[i*2+1];
	}
	void operator()(int l,int r,Ope ope){ upd(l,r,ope,0,0,segs.size()/2);};
	Seg operator()(int l,int r){ return query(l,r,0,0,segs.size()/2);};
};

vector<int> solve(vector<int> a,vector<int> b){
	int n=a.size();
	vector<int> inv(n);
	rep(i,n) inv[a[i]]=i;
	SegTree<Seg<int>,Lfun<int>> st(n);
	vector<int> re(n);
	rep(i,n){
		re[i]=inv.size();
		st(0,b[i]+1,1);
		// rep(i,n) cout<<st(i,i+1).s<<","; cout NL;
		// out(inv.back(),1);
		while(inv.size()){
			st(0,inv.back()+1,-1);
			if(st(0,n).s<0){
				st(0,inv.back()+1,1);
				break;
			}
			// out("rm",inv.back(),1);
			// rep(i,n) cout<<st(i,i+1).s<<","; cout NL;
			inv.pop_back();
		}
	}
	// out(re,1);
	return re;
}

vector<int> bf(vector<int> a,vector<int> b){
	int n=a.size();
	vector<int> bm(n);
	vector<int> re(n);
	rep(i,n){
		priority_queue<int> pq;
		rep(i,n){
			pq.emplace(a[i]);
			if(bm[i]) pq.pop();
		}
		re[i]=pq.top()+1;
		bm[b[i]]=1;
	}
	return re;
}

int main(){
	if(0){
		rep(_,10000){
			int n=rand()%100+2;
			vector<int> a(n),b(n);
			iota(all(a),0); random_shuffle(all(a));
			iota(all(b),0); random_shuffle(all(b));
			auto act=solve(a,b);
			auto exp=bf(a,b);
			if(act!=exp){
				out(a,b,act,exp,1);
				return 0;
			}
		}
		out(solve({1,2,0},{1,2,0}),1);
		return 0;
	}
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(auto &x:a) cin>>x, --x;
	for(auto &x:b) cin>>x, --x;
	out(a,b,1);
	auto re=solve(a,b);
	for(int x:re) cout<<x<<" ";
  return 0;
}