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

ll solve(vector<pii> ps){ //[0,200000]
	int n=ps.size();
	out(ps,1);
	const int N=202345;
	vv<int> xs(212345);
	for(auto p:ps) xs[p.Y].pb(p.X);
	vector<int> ltl(212345),ltr(212345);
	{
		int l=MOD,r=-MOD;
		rep(i,N){
			ltl[i]=l; ltr[i]=r;
			for(auto x:xs[i]){
				MN(l,x);
				MX(r,x);
			}
		}
	}
	vector<int> gel(212345),ger(212345);
	{
		int l=MOD,r=-MOD;
		rrep(i,N){
			for(auto x:xs[i]){
				MN(l,x);
				MX(r,x);
			}
			gel[i]=l; ger[i]=r;
		}
	}
	ll re=0;
	rep(y,N){
		if(ltl[y]>ltr[y]) continue;
		if(gel[y]>ger[y]) continue;
		re+=max(0,min(ltr[y],ger[y])-max(ltl[y],gel[y]));
	}
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<pii> ps(n);
	for(auto &p:ps) cin>>p.X>>p.Y;
	vv<pii> vs(2);
	for(auto p:ps){
		int x=p.X+p.Y+200000;
		int y=p.X-p.Y+200000;
		vs[x%2].eb(x/2,y/2);
	}
	ll re=0;
	rep(i,2) re+=solve(vs[i]);
	cout<<re NL;
  return 0;
}