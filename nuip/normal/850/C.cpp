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

unordered_map<int,int> memo;
int fun(int i){
	if(memo.count(i)) return memo[i];
	vector<int> gr{MOD};
	rep(k,30)if(i>>k){
		int nxt=(i>>(k+1));
		nxt|=i&((1<<k)-1);
		gr.pb(fun(nxt));
	}
	sort(all(gr)); UNIQUE(gr);
	rep(j,gr.size())if(j!=gr[j]){
		return memo[i]=j;
	}
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	// out(0b100,1);
	// out(fun(0b010101010101010101010101010101),1);
	// return 0;
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	map<int,int> cnts;
	for(auto x:a){
		for(int i=2;i*i<=x;++i){
			int cnt=0;
			while(x%i==0) ++cnt, x/=i;
			if(cnt) out(i,cnt,1);
			if(cnt) cnts[i]|=1<<(cnt-1);
		}
		if(x>1) cnts[x]|=1;
	}
	int gr=0;
	for(auto [a,cnt]:cnts){
		out(cnt,fun(cnt),1);
		gr^=fun(cnt);
	}
	cout<<(gr?"Mojtaba":"Arpa") NL;
	return 0;
	vector<int> dp(100);
	reps(i,1,dp.size()){
		vector<int> gr{MOD};
		rep(k,30)if(i>>k){
			int nxt=(i>>(k+1));
			nxt|=i&((1<<k)-1);
			gr.pb(dp[nxt]);
		}
		sort(all(gr)); UNIQUE(gr);
		rep(j,gr.size())if(j!=gr[j]){
			dp[i]=j;
			break;
		}
	}
	rep(k,100)rep(i,dp.size())if(dp[i]==k){
		cout<<dp[i]<<"\t";
		rep(d,10) cout<<(i>>d&1); cout NL;
	}
  return 0;
}