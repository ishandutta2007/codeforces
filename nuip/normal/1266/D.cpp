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
	int n,m;
	cin>>n>>m;
	vector<ll> sum(n);
	rep(_,m){
		int a,b,c;
		cin>>a>>b>>c; --a; --b;
		sum[a]+=c;
		sum[b]-=c;
	}
	deque<pll> deq;
	rep(i,n){
		if(sum[i]>0) deq.emplace_front(sum[i],i);
		if(sum[i]<0) deq.emplace_back(-sum[i],i);
	}
	vector<tuple<int,int,ll>> re;
	while(deq.size()){
		out(deq,1);
		while(deq.size() && deq.front().X==0) deq.pop_front();
		while(deq.size() && deq.back().X==0) deq.pop_back();
		ll t=min(deq.front().X,deq.back().X);
		deq.front().X-=t;
		deq.back().X-=t;
		re.eb(deq.front().Y,deq.back().Y,t);
		while(deq.size() && deq.front().X==0) deq.pop_front();
		while(deq.size() && deq.back().X==0) deq.pop_back();
	}
	out(re,1);
	cout<<re.size() NL;
	for(auto tp:re) cout<<get<0>(tp)+1<<" "<<get<1>(tp)+1<<" "<<get<2>(tp) NL;
  return 0;
}