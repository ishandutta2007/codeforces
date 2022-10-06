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
#define cauto const auto

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
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(const pair<A,B> &p,const pair<C,D> &q){ p.X+=p.X; q.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(const pair<A,B> &p,const pair<C,D> &q){ p.X-=p.X; q.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T> T read(){ T re; cin>>re; return move(re);}
template<class T> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
const ll MOD=1e9+7; //998244353

int dp[1000][1000][2][2];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);

	dp[0][0][1][0]=1;
	rep(i,1000)rep(j,1000)if(i+j)rep(me,2)rep(op,2)if((i+me+op)%2){
			if(i && dp[i-1][j][op][1-me]==0) dp[i][j][me][op]=1;
			if(j && dp[i][j-1][op][me]==0) dp[i][j][me][op]=1;
	}
	// rep(me,2)rep(op,2)rep(i,100)rep(j,100){
	// 	assert(dp[i][j][me][op]==dp[i+4][j][me][op]);
	// 	assert(dp[i][j][me][op]==dp[i][j+4][me][op]);
	// }
	
	auto T=read<int>();
	while(T--){
		cauto n=read<int>();
		cauto vs=readV<int>(n);
		int s=0;
		for(auto v:vs) s^=v;
		if(s==0){
			cout<<"DRAW" NL;
			continue;
		}
		int d=0;
		rrep(i,30)if(s>>i&1){ d=i; break;}
		int one=0,zero=0;
		for(auto v:vs) ((v>>d&1)?one:zero)++;
		out(one,zero,1);
		cout<<(dp[one%4][zero%4][0][0]?"WIN":"LOSE") NL;
	}
  return 0;
}