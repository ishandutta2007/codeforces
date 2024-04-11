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

ll dp[11][112][1<<10];

ll fun(int b,ll n){
	ll d=1,len=0;
	while(d*b<=n) d*=b, ++len;
	int st=0;
	int init=1;
	ll re=0;
	// rep(i,len)reps(j,1,b) out(i,j,dp[b][i][1<<j],1);
	rep(i,len)reps(j,1,b) re+=dp[b][i][1<<j];
	for(;d;d/=b,--len){
		reps(i,init,n/d) re+=dp[b][len][st^(1<<i)];
		st^=1<<(n/d);
		n%=d;
		init=0;
	}
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	reps(b,2,11){
		dp[b][0][0]=1;
		rep(i,100)rep(st,1<<b)rep(k,10) dp[b][i+1][st^(1<<k)]+=dp[b][i][st];
	}
	// rep(i,10){rep(j,1<<2) cout<<dp[2][i][j]<<",";cout NL;}
	// out(fun(2,10),1); return 0;
	int q;
	cin>>q;
	rep(_,q){
		int b;
		ll l,r;
		cin>>b>>l>>r; ++r;
		cout<<fun(b,r)-fun(b,l) NL;
	}
  return 0;
}