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
	cauto s=read<string>();
	vector<pll> ints{{-1,-1}};
	rep(i,n){
		if(s[i]=='1'){
			if(ints.back().X<0) ints.back().X=i;
			ints.back().Y=i;
		}else{
			if(ints.back().X>=0) ints.eb(-1,-1);
		}
	}
	if(ints.back().X<0) ints.pop_back();
	out(ints,1);
	vector<pll> stk;
	ll re=0;
	cauto ad=
		[&](ll lb,ll ub,ll a,ll b,ll c){ // (lb,ub]
			out(lb,ub,a,b,c,1);
			reps(i,lb+1,ub+1){
				ll tmp=(a*i+b)*i+c;
				out(i,tmp,1);
				re+=tmp;
			}
			return;
			re+=(ub-lb)*c;
			re+=(ub-lb)*(ub+lb-1)*b;
			re+=ub*(ub+1)*(2*ub+1)/6*a;
			re-=lb*(lb+1)*(2*lb+1)/6*a;
		};
	for(cauto &[l,r]:ints){
		out(l,r,1);
		cauto len=r-l+1;
		ll lb=0;
		while(stk.size() && stk.back().X<len){
			cauto x=l-stk.back().Y-1;
			cauto ub=stk.back().X; // (lb,ub]
			stk.pop_back();
			out(lb,ub,x,1);
			ad(lb,ub,4,2*(x-2+x-1),(x-2)*(x-1));
			lb=ub;
		}
		if(stk.empty()){
			cauto x=l;
			out(lb,len,x,1);
			ad(lb,len,1,(x+x-1),x*(x-1));
		}else{
			cauto x=l-stk.back().Y-1;
			out(lb,len,x,1);
			ad(lb,len,4,2*(x-2+x-1),(x-2)*(x-1));
		}
		stk.eb(len,r);
	}
	ll lb=0;
	while(stk.size()){
		cauto x=n-stk.back().Y-1;
		cauto ub=stk.back().X; // (lb,ub]
		stk.pop_back();
		out(lb,ub,x,1);
		ad(lb,ub,1,(x+x-1),x*(x-1));
		lb=ub;
	}
	ad(lb,n,0,0,n*(n+1));
	out(re,1);
	re=n*(n+1)/2*n-re/2;
	cout<<re NL;
  return 0;
}