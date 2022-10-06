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

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int x=MOD,y=MOD,X=-MOD,Y=-MOD;
	rep(_,4){
		int a,b;
		cin>>a>>b;
		MN(x,a); MN(y,b);
		MX(X,a); MX(Y,b);
	}
	int s=MOD,d=MOD,S=-MOD,D=-MOD;
	rep(_,4){
		int u,t;
		cin>>u>>t;
		int a=u+t,b=u-t;
		MN(s,a); MN(d,b);
		MX(S,a); MX(D,b);
	}
	out(s,d,S,D,x,y,X,Y,1);
	reps(b,-300,300)reps(a,-300,300){
		if(a<x || X<a) continue;
		if(b<y || Y<b) continue;
		if(a+b<s || S<a+b) continue;
		out(3,1);
		if(a-b<d || D<a-b) continue;
		out(4,1);
		cout<<"YES" NL;
		return 0;
	}
	cout<<"NO" NL;
  return 0;
}