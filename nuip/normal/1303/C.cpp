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

string solve(const vv<int> &g){
	rep(i,26)if(g[i].size()>2) return "";
	vector<int> usd(26);
	string re;
	rep(c,26)if( g[c].size()==1 && MX(usd[c],1)){
		re+=char(c+'a');
		for(char nxt=g[c][0],prv=c;;){
			re+=char(nxt+'a');
			usd[nxt]=1;
			if(g[nxt].size()==1) break;
			char tmp=g[nxt][g[nxt][0]==prv];
			prv=nxt;
			nxt=tmp;
		}
	}
	rep(c,26)if(g[c].size()==0 && MX(usd[c],1)) re+=char(c+'a');
	out(usd,g,1);
	if(*min_element(all(usd))==0) return "";
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		vv<int> g(26);
		reps(i,1,s.size()){
			int a=s[i-1]-'a';
			int b=s[i]-'a';
			g[a].pb(b);
			g[b].pb(a);
		}
		rep(i,26){
			sort(all(g[i]));
			UNIQUE(g[i]);
		}
		string re=solve(g);
		if(re.empty()) cout<<"NO" NL;
		else cout<<"YES" NL << re NL;
	}
  return 0;
}