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
	int n,m,t;
	cin>>n>>m>>t;
	if(4*n*m-2*n-2*m<t){
		cout<<"NO" NL;
		return 0;
	}
	cout<<"YES" NL;
	// if(n==1){
	// 	cout<<"1\n"<<m-1<<" R" NL;
	// 	return 0;
	// }
	// if(m==1){
	// 	cout<<"1\n"<<n-1<<" D" NL;
	// 	return 0;
	// }
	vector<pii> ps;
	rep(_,n-1){
		ps.eb(m-1,'R');
		ps.eb(m-1,'L');
		ps.eb(1,'D');
	}
	rep(_,m-1){
		ps.eb(1,'R');
		ps.eb(n-1,'U');
		ps.eb(n-1,'D');
	}
	ps.eb(m-1,'L');
	ps.eb(n-1,'U');
	out(ps.size(),1);
	vector<pii> re;
	int rem=t;
	for(pii p:ps){
		if(rem==0) break;
		int r=min(rem,p.X);
		if(r) re.eb(r,p.Y);
		rem-=r;
	}
	out(re,1);
	cout<<re.size() NL;
	for(pii p:re) cout<<p.X<<" "<<char(p.Y) NL;
  return 0;
}