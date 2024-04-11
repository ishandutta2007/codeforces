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

int dp[312345][3];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	ll e=0,o=0;
	for(auto x:a){
		e+=x/2;
		o+=(x+1)/2;
		swap(e,o);
	}
	cout<<min(e,o) NL;
	// fill(dp[0],dp[312345],-MOD);
	// dp[0][0]=0;
	// rep(i,n){
	// 	MX(dp[i+1][0],dp[i][0]+a[i]/2);
	// 	MX(dp[i+1][1],dp[i][0]+(a[i]-1)/2);
	// 	if(a[i]>=2) MX(dp[i+1][2],dp[i][0]+(a[i]-2)/2);
	// 	MX(dp[i+1][0],dp[i][1]+a[i]/2);
	// 	MX(dp[i+1][0],dp[i][1]+(a[i]-1)/2+1);
	// 	if(a[i]>=2) MX(dp[i+1][2],dp[i][1]+(a[i]-2)/2+1);
	// 	MX(dp[i+1][0],dp[i][2]+a[i]/2);
	// 	if(a[i]>=2){
	// 		MX(dp[i+1][0],dp[i][2]+(a[i]-2)/2+1);
	// 		MX(dp[i+1][1],dp[i][2]+(a[i]-2)/2+1);
	// 	}
	// }
	// // rep(i,n+1) cout<<dp[i][0]<<","<<dp[i][1]<<","<<dp[i][2] NL;
	// cout<<*max_element(dp[n],dp[n+1]) NL;
  return 0;
}