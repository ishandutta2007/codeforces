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

using AR=array<int,5>;
AR cnt[212345];
AR cntp[212345];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,t;
	cin>>n>>t;
	vv<int> g(n);
	reps(i,1,n){
		int a,b;
		cin>>a>>b; --a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<int> dep(n);
	{
		auto dfs=
			[&](auto &&dfs,int v,int p)->void{
				for(int w:g[v])if(w!=p){
						dep[w]=dep[v]+1;
						dfs(dfs,w,v);
						rep(i,t) cnt[v][(i+1)%t]+=cnt[w][i];
					}
				++cnt[v][0];
			};
		dfs(dfs,0,-1);
	}
	{
		auto dfs=
			[&](auto &&dfs,int v,int p)->void{
				for(int w:g[v])if(w!=p){
						auto tmp=cnt[v];
						rep(i,t) tmp[i]+=cntp[v][i];
						rep(i,t) tmp[(i+1)%t]-=cnt[w][i];
						rep(i,t) cntp[w][(i+1)%t]=tmp[i];
						dfs(dfs,w,v);
					}
			};
		dfs(dfs,0,-1);
	}

	ll re=0;
	reps(v,1,n){
		ll sz=0;
		rep(i,t) sz+=cnt[v][i];
		re+=cnt[v][0]*(n-sz);
		re+=cntp[v][(t>1)]*sz;
		out(v,cnt[v],cntp[v],sz,1);
	}
	out(re,1);
	cout<<re/2 NL;
  return 0;
}