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

template<class T,T INF>
struct Mm{
	T mx,mn;
	Mm(const T &mx=-INF
		 ,const T &mn=INF):mx(mx),mn(mn){}
	Mm operator+(const Mm &seg){
		return Mm(max(mx,seg.mx),min(mn,seg.mn));
	}
  static Mm e;
};
template<class T,T INF> Mm<T,INF> Mm<T,INF>::e=Mm();
template<class T, T INF>
ostream&  operator<<(ostream &os, const Mm<T,INF> &mm){ return os<<"("<<mm.mx<<","<<mm.mn<<")";}

template<class T>
struct Ad{
	T ad;
	Ad(T ad=0):ad(ad){}
	void operator+=(const Ad &a){
		ad+=a.ad;
	}
	bool operator==(const Ad &a){ return ad==a.ad;}

	template<T INF>
	void eval(Mm<T,INF> &s,int l,int r){
		s.mx+=ad;
		s.mn+=ad;
	}
	static Ad e;
};
template<class T> Ad<T> Ad<T>::e=Ad();
// template<class T>
// ostream&  operator<<(ostream &os, const Lfun<T> &lfun){ return os<<"("<<lfun.a<<","<<lfun.b<<")";}

template<class Seg, class Ope>
struct SegTree{
	vector<Seg> segs;
	vector<Ope> opes;
	int N=1;
	
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
		while(N<n) N*=2;
		segs.resize(2*N);
		opes.resize(2*N);
	}
	void operator()(int ind,const Seg &seg){ segs[ind+N-1]=seg;}
	void init(){ rrep(i,N-1) upd_node(i);}
	void operator()(int l,int r,Ope ope){ upd(l,min(N,r),ope,0,0,N);};
	Seg operator()(int l,int r){ return query(l,min(N,r),0,0,N);};
};


int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	string s;
	cin>>n>>s;
	SegTree<Mm<int,(int)MOD>,Ad<int>> st(n/2+10);
	rep(i,n/2+10) st(i,{0,0});
	st.init();
	string str(n,' ');
	int ind=0;
	for(char c:s){
		if(c=='L'){
			ind=max(0,ind-1);
		}else if(c=='R'){
			++ind;
		}else{
			if(str[ind]=='('){
				st(ind+1,MOD,-1);
			}else if(str[ind]==')'){
				st(ind+1,MOD,1);
			}
			str[ind]=c;
			if(str[ind]=='('){
				st(ind+1,MOD,1);
			}else if(str[ind]==')'){
				st(ind+1,MOD,-1);
			}
		}
		int re=-1;
		if(st(n/2+3,n/2+4).mx==0){
			auto s=st(0,n/2+3);
			if(s.mn>=0) re=s.mx;
		}
		// out(re,str,1);
		// cout<<st(0,n) NL;
		// rep(i,n) cout<<st(i,i+1).mx<<","; cout<<st(0,n) NL;
		cout<<re<<" ";
	}
	cout<<endl;
  return 0;
}