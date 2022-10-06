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

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1,0};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	T=1;
	while(T--){
		int n,m,q;
		cin>>n>>m>>q;
		vector<string> mp(n);
		for(auto &s:mp) cin>>s;
		vector dst(n,vector<ll>(m,2e18));
		rep(i,n)reps(j,1,m)if(mp[i][j]==mp[i][j-1]) dst[i][j]=dst[i][j-1]=1;
		reps(i,1,n)rep(j,m)if(mp[i][j]==mp[i-1][j]) dst[i][j]=dst[i-1][j]=1;
		queue<pii> que;
		rep(i,n)rep(j,m)if(dst[i][j]==1) que.emplace(j,i);
		while(que.size()){
			auto [x,y]=que.front(); que.pop();
			rep(d,4){
				int nx=dx[d]+x;
				int ny=dy[d]+y;
				if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
				if(MN(dst[ny][nx],dst[y][x]+1)) que.emplace(nx,ny);
			}
		}
		// rep(i,n){rep(j,m)cout<<dst[i][j];cout<<endl;}
		while(q--){
			int y,x;
			ll t;
			cin>>y>>x>>t; --y; --x;
			int flip=0;
			if(t>=dst[y][x] && t%2==dst[y][x]%2) flip=1;
			cout<<char(mp[y][x]^flip) NL;
		}
	}
  return 0;
}