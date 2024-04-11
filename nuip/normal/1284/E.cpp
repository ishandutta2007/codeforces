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

struct P{
	ll X,Y;
	P(ll x=0,ll y=0):X(x),Y(y){}
	P operator-(const P &p)const{ return P(X-p.X,Y-p.Y);}
	P operator+(const P &p){ return P(X+p.X,Y+p.Y);}
};
ostream& operator<<(ostream& os, const P &p){ return os<<"("<<p.X<<","<<p.Y<<")";}

ll cros(const P &a,const P &b){ return a.X*b.Y-a.Y*b.X;}

bool argCmp(const P& a,const P&b){
  if(a.Y*b.Y<0)
    return b.Y<0;
  if(!a.Y && !b.Y)
    return a.X>=0 || b.X<0;
  if(!a.Y)
    return a.X>=0 || b.Y<0;
  if(!b.Y)
    return a.Y>0 && b.X<0;
  return cros(a,b)>0;
}

ll fun(vector<P> &ps){
	int n=ps.size();
	sort(all(ps),argCmp);
	ps.reserve(n+n);
	rep(i,n) ps.pb(ps[i]);
	int r=0;
	ll re=0;
	out(ps,1);
	rep(l,n){
		MX(r,l+1);
		while(r-l<n && cros(ps[l],ps[r])>0) ++r;
		ll t=r-l-1;
		re+=t*(t-1)/2;
		out(r,t,1);
	}
	return re;
}


int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<P> ps(n);
	rep(i,n) cin>>ps[i].X>>ps[i].Y;
	ll re=0;
	rep(i,n){
		vector<P> pts;
		rep(j,n)if(i!=j) pts.pb(ps[j]-ps[i]);
		out(ps[i],1);
		re+=(n-1ll)*(n-2)*(n-3)/6-fun(pts);
		out(re,1);
	}
	re*=n-4;
	assert(re%2==0);
	cout<<re/2 NL;
  return 0;
}