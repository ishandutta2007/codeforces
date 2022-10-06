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

ll get(vector<int> sq,int f=0){
	map<int,int> sz;
	for(auto x:sq) ++sz[x];
	out(sq,sz,1);
	ll cnt=0,re=1;
	sort(rall(sq));
	int N=sq.size();
	rep(i,N){
		int ub=i+2;
		while(sq.size() && sq.back()<ub){
			++cnt;
				sq.pop_back();
		}
		out(ub,cnt,1);
		re*=cnt;
		--cnt;
	}
	out(re,1);
	for(auto p:sz)rep(i,p.Y) re/=i+1;
	out(re,1);
	return re;
}		

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		vector<int> sq;
		reps(i,2,100){
			sq.pb(n%i);
			n/=i;
			if(n==0) break;
		}
		out(sq,1);
		sort(rall(sq));
		ll re=get(sq);
		if(sq.back()==0){
			sq.pop_back();
			re-=get(sq,1);
		}
		cout<<re-1 NL;
	}
  return 0;
}