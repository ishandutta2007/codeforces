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

ll fun(int n){
	if(n<=2) return 0;
	ll re=0;
	rep(i,n){
		int rem=n-1-i;
		re+=max(0,rem-(i+1));
	}
	return re;
}

ll fun(vector<int> a){
	int n=a.size();
	ll re=0;
	rep(k,n)rep(j,k)rep(i,j)if(a[i]+a[j]==a[k]) ++re;
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	vector<int> val(5123);
	rep(i,5123) val[i]=fun(i);
	int n,m;
	cin>>n>>m;
	int len=n;
	if(val[len]<m){
		cout<<-1 NL;
		return 0;
	}
	while(len>0 && val[len-1]>=m) --len;
	vector<int> re(len); iota(all(re),1);
	int cur=val[len];
	while(cur!=m){
		re.back()+=2;
		cur--;
	}
	rep(i,n-len) re.pb(1000000000-i*5123);
	sort(all(re));
	rep(i,n) cout<<re[i]<<" \n"[i+1==n];
#ifdef NUIP
	assert(fun(re)==m);
#endif
	// out(val[5000],1);
	// {
	// 	vector<int> a(100); iota(all(a),1);
	// 	rep(i,110){
	// 		++a.back();
	// 		if(i%2==0 && fun(a)+i/2!=2450) out(fun(a),i,1);
	// 	}
	// }
	// out(val[100],val[99],1);
  return 0;
}