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

int dp[11234][1123];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>n>>m;
	vector<int> ds(m);
	for(auto &d:ds) cin>>d;
	sort(all(ds)); UNIQUE(ds);
	m=ds.size();
	int g,r;
	cin>>g>>r;
	fill(dp[0],dp[11234],MOD);
	dp[0][0]=0;
	deque<pii> que; que.emplace_front(0,0);
	while(que.size()){
		auto [v,t]=que.front(); que.pop_front();
		if(t==g){
			if(MN(dp[v][0], dp[v][t]+1)) que.emplace_back(v,0);
			continue;
		}
		if(v){
			int dst=ds[v]-ds[v-1];
			if(t+dst<=g && MN(dp[v-1][t+dst], dp[v][t])) que.emplace_front(v-1,t+dst);
		}
		if(v+1<m){
			int dst=ds[v+1]-ds[v];
			if(t+dst<=g && MN(dp[v+1][t+dst], dp[v][t])) que.emplace_front(v+1,t+dst);
		}
	}
	const ll INF=1e18;
	ll re=INF;
	rep(i,g+1)if(dp[m-1][i]!=MOD) MN(re, dp[m-1][i]*ll(g+r)+i);
	cout<<(re==INF?-1ll:re) NL;
  return 0;
}