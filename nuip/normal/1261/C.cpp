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
	// n=1000; m=1000;
	vector<string> mp(n); //,string(m,'X'));
	rep(i,n) cin>>mp[i];
	vv<int> cnt(n+1,vector<int>(m+1));
	rep(i,n)rep(j,m)if(mp[i][j]=='X') ++cnt[i+1][j+1];
	rep(i,n+1)rep(j,m) cnt[i][j+1]+=cnt[i][j];
	rep(i,n)rep(j,m+1) cnt[i+1][j]+=cnt[i][j];
	auto get=[&](int x,int y,int X,int Y){ return cnt[Y][X]+cnt[y][x]-cnt[y][X]-cnt[Y][x];};
	auto ok=[&](int x,int y,int r){
						if(x<r || y<r) return false;
						if(x+r>=m || y+r>=n) return false;
						return get(x-r,y-r,x+r+1,y+r+1)==(2*r+1ll)*(2*r+1);
					};
	int l=0,r=1123;
	while(r-l>1){
		int med=(l+r)/2;
		vv<int> mrk(n+1,vector<int>(m+1,0));
		rep(i,n)rep(j,m)if(ok(j,i,med)){
			++mrk[i-med][j-med];
			++mrk[i+med+1][j+med+1];
			--mrk[i+med+1][j-med];
			--mrk[i-med][j+med+1];
		}
		rep(i,n+1)rep(j,m) mrk[i][j+1]+=mrk[i][j];
		rep(i,n)rep(j,m+1) mrk[i+1][j]+=mrk[i][j];
		int ok=1;
		rep(i,n)rep(j,m)if((mrk[i][j]>0)!=(mp[i][j]=='X')){ ok=0; break;}
		(ok?l:r)=med;
	}
	cout<<l<<endl;
	rep(i,n){rep(j,m) cout<<".X"[ok(j,i,l)]; cout NL;}
  return 0;
}