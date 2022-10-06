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

int dst[3123][3123];
int sz[3123][3123];
ll dp[3123][3123];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vv<int> g(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b; --a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep(s,n){
		queue<int> que; que.emplace(s);
		fill(dst[s],dst[s+1],MOD); dst[s][s]=0;
		while(que.size()){
			int v=que.front(); que.pop();
			for(int w:g[v])if(MN(dst[s][w],dst[s][v]+1)) que.emplace(w);
		}
		function<void(int,int)> dfs=
			[&](int v,int p){
				sz[s][v]=1;
				for(int w:g[v])if(w!=p){
						dfs(w,v);
						sz[s][v]+=sz[s][w];
					}
			};
		dfs(s,-1);
	}
	// rep(v,n){rep(w,n) cout<<dst[v][w]<<","; cout NL;} cout NL;
	vv<pii> dsts(n+1);
	rep(i,n)rep(j,n) dsts[dst[i][j]].eb(i,j);
	rep(d,n)for(auto p:dsts[d]){
		int v,w; tie(v,w)=p;
		for(int u:g[v])if(dst[u][w]==d+1){
				ll val=dp[v][w]+ll(sz[w][v]-sz[w][u])*sz[u][w]*d;
				MX(dp[u][w],val);
				MX(dp[w][u],val);
			}
	}
	// rep(v,n){rep(w,n) cout<<dp[v][w]<<","; cout NL;} cout NL;
	ll re=0;
	rep(i,n)rep(j,n) MX(re,dp[i][j]+dst[i][j]);
	cout<<re NL;
  return 0;
}