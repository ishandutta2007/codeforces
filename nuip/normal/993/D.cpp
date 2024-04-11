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
	int n;
	cin>>n;
	vector<pii> ps(n);
	rep(i,n) cin>>ps[i].X;
	rep(i,n) cin>>ps[i].Y;
	map<int,vector<int>> mp;
	rep(i,n) mp[ps[i].X].pb(ps[i].Y);
	ll l=0,r=1e15;
	array<ll,30> init; fill(all(init),-1e18);
	while(r-l>1){
		ll m=(l+r)/2;
		// m=9001;
		auto dp=init; dp[0]=0;
		for(auto &p:mp){
			auto &v=p.Y;
			sort(rall(v));
			int inc=v.size(),dec=0;
			ll sum=0;
			auto nxt=init;
			rep(i,25-inc) MX(nxt[i+inc],dp[i]);
			for(auto b:v){
				--inc; ++dec;
				sum+=-1000ll*p.X+m*b;
				rep(i,25){
					int j=max(0,i-dec)+inc;
					if(j<25) MX(nxt[j],dp[i]+sum);
				}
			}
			// out(p,nxt,1);
			dp=nxt;
		}
		// out(dp,1);
		// return 0;
		(dp[0]>=0?r:l)=m;
	}
	cout<<r<<endl;
  return 0;
}