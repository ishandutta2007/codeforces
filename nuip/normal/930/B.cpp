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

int cnt[26][5123][26];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(10);
	string s;
	cin>>s;
	int n=s.size();
	s+=s;
	rep(i,n)reps(j,1,n){
		cnt[s[i]-'a'][j][s[i+j]-'a']++;
	}
	vector<long double> prob(26);
	rep(i,26)rep(j,n){
		// int c=0;
		// rep(k,26)if(cnt[i][j][k]) ++c;
		// // if(c && c==accumulate(cnt[i][j],cnt[i][j+1],0)) prob[i]=1;
		// MX(prob[i],(long double)c/accumulate(cnt[i][j],cnt[i][j+1],0));
		int c=0;
		rep(k,26)if(cnt[i][j][k]==1) ++c;
		MX(prob[i],(long double)c/accumulate(cnt[i][j],cnt[i][j+1],0));
	}
	out(prob,1);
	long double re=0;
	rep(i,n) re+=prob[s[i]-'a'];
	cout<<re/n NL;
  return 0;
}