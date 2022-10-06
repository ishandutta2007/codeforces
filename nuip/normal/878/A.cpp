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

int memo[10][2];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	rep(i,10) memo[i][1]=1;
	rep(_,n){
		char c;
		int x;
		cin>>c>>x;
		if(c=='&'){
			rep(i,10)rep(j,2) memo[i][j]=(x>>i&1)&memo[i][j];
		}else if(c=='|'){
			rep(i,10)rep(j,2) memo[i][j]=(x>>i&1)|memo[i][j];
		}else{
			rep(i,10)rep(j,2) memo[i][j]=(x>>i&1)^memo[i][j];
		}
	}
	cout<<3<<endl;
	//00&0
	{
		int t=1023;
		rep(i,10)if(!memo[i][0] && !memo[i][1]) t^=1<<i;
		cout<<"& "<<t NL;
	}
	//01
	//10^1
	{
		int t=0;
		rep(i,10)if(memo[i][0] && !memo[i][1]) t^=1<<i;
		cout<<"^ "<<t NL;
	}
	//11|1
	{
		int t=0;
		rep(i,10)if(memo[i][0] && memo[i][1]) t|=1<<i;
		cout<<"| "<<t NL;
	}
	// rep(i,1024){
	// 	int e=((i&1)&3)&5;
	// 	int a=((i&1)^0)|0;
	// 	if(e!=a){
	// 		out(i,e,a,1);
	// 		return 0;
	// 	}
	// }
  return 0;
}