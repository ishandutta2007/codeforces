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

int dist(string s,string t){
	int n=s.size();
	int m=t.size();
	vv<int> dp(n+1,vector<int>(m+1,MOD)); dp[0][0]=0;
	rep(i,n+1)rep(j,m+1){
		if(i<n) MN(dp[i+1][j],dp[i][j]+1);
		if(j<m) MN(dp[i][j+j],dp[i][j]+1);
		if(i<n&&j<m) MN(dp[i+1][j+1], dp[i][j]+1-(s[i]==t[j]));
	}
	return dp[n][m];
}

int ask(string s){
	assert(s.size()>0);
	cout<<s<<endl;cout.flush();
	int re;
	cin>>re;
	if(re<0) exit(0);
	return re;
}

int main(){
	int T;
	T=1;
	while(T--){
		int t=ask("a");
		if(!t) exit(0);
		int a=ask(string(t,'b'));
		if(!a) exit(0);
		int n=t+1;
		int b=n-a;
		string s(n,'a');
		string cand(n,'a');
		reps(i,2,n){
			s[i]++;
			if(ask(s)<b) cand[i]++;
			s[i]--;
		}
		rep(i,2)rep(j,2){
			cand[0]+=i; cand[1]+=j;
			if(count(all(cand),'a')==a && ask(cand)==0) exit(0);
			cand[0]-=i; cand[1]-=j;
		}
	}
  return 0;
}