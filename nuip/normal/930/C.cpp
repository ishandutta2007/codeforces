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

void solve(const vector<int> &vs,vector<int> &re){
	int n=vs.size();
	re.resize(n);
	vector<int> dp(n+1,MOD); dp[0]=0;
	rep(i,n){
		int j=upper_bound(all(dp),vs[i])-dp.begin();
		re[i]=j;
		MN(dp[j],vs[i]);
	}
	rep(i,n-1) MX(re[i+1],re[i]);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>m>>n;
	vector<int> cnt(n+1);
	rep(_,m){
		int l,r;
		cin>>l>>r; --l;
		++cnt[l];
		--cnt[r];
	}
	rep(i,n) cnt[i+1]+=cnt[i];
	cnt.pop_back();
	out(cnt,1);
	vector<int> L,R;
	solve(cnt,L);
	reverse(all(cnt));
	solve(cnt,R);
	reverse(all(R));
	int re=0;
	reps(i,1,n) MX(re,L[i-1]+R[i]);
	cout<<re NL;
  return 0;
}