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

int sumc[4][512][512];
const int SQ=50;
int sum[SQ][512][512];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m,q;
	cin>>n>>m>>q;
	vector<string> mp(n);
	rep(i,n) cin>>mp[i];
	const string S="RGYB";
	rep(c,4){
		rep(i,n)rep(j,m)if(mp[i][j]==S[c]) ++sumc[c][i+1][j+1];
		rep(i,n+1)rep(j,m+1) sumc[c][i][j+1]+=sumc[c][i][j];
		rep(i,n+1)rep(j,m+1) sumc[c][i+1][j]+=sumc[c][i][j];
	}
	auto Sumc=[&](int c,int x,int y,int X,int Y){
							clamp(x,0,m); clamp(X,0,m);
							clamp(y,0,n); clamp(Y,0,n);
						 if(x>X) return 0;
						 if(y>Y) return 0;
						 return sumc[c][Y][X]+sumc[c][y][x]-sumc[c][y][X]-sumc[c][Y][x];};
	auto isLogo=
		[&](int x,int y,int l){
			++x; ++y;
			if(x-l<0 || y-l<0 || x+l>m || y+l>n) return 0;
			if(Sumc(0,x-l,y-l,x,y)<l*l) return 0;
			if(Sumc(1,x,y-l,x+l,y)<l*l) return 0;
			if(Sumc(2,x-l,y,x,y+l)<l*l) return 0;
			if(Sumc(3,x,y,x+l,y+l)<l*l) return 0;
			return 1;
		};
	vector<tuple<int,int,int>> tps;
	rep(i,n)rep(j,m)if(isLogo(j,i,1)){
		int mx;
		reps(sz,1,n){
			if(!isLogo(j,i,sz)) break;
			out(i,j,sz,1);
			mx=sz;
			if(sz<SQ){
				++sum[sz][i+1][j+1];
			}
		}
		if(mx>=SQ) tps.eb(j,i,mx);
	}
	rep(sz,SQ){
		rep(i,n+1)rep(j,m+1) sum[sz][i][j+1]+=sum[sz][i][j];
		rep(i,n+1)rep(j,m+1) sum[sz][i+1][j]+=sum[sz][i][j];
	}
	auto Sum=[&](int c,int x,int y,int X,int Y){
						 if(x>X) return 0;
						 if(y>Y) return 0;
						 return sum[c][Y][X]+sum[c][y][x]-sum[c][y][X]-sum[c][Y][x];};
	while(q--){
		int r,c,R,C;
		cin>>r>>c>>R>>C; --r; --c;
		int re=0;
		rreps(sz,1,SQ){
			int x=c+sz-1;
			int X=C-sz;
			int y=r+sz-1;
			int Y=R-sz;
			if(Sum(sz,x,y,X,Y)){
				re=sz;
				break;
			}
		}
		for(auto [x,y,sz]:tps){
			MX(re,min({sz,x-c+1,C-x-1,y-r+1,R-y-1}));
		}
		cout<<4ll*re*re NL;
	}
  return 0;
}