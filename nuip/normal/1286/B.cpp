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
	int n;
	cin>>n;
	vv<int> g(n);
	vector<int> cs(n);
	int rt;
	rep(v,n){
		int p;
		cin>>p;	--p;
		if(p>=0) g[p].pb(v);
		else rt=v;
		cin>>cs[v];
	}
	vv<int> re(n);
	function<void(int)> dfs=
		[&](int v){
			for(auto w:g[v]){
				dfs(w);
				if(re[v].size()<re[w].size()) swap(re[w],re[v]);
				re[v].insert(re[v].end(),all(re[w]));
			}
			if(cs[v]>re[v].size()){
				cout<<"NO"<<endl;
				exit(0);
			}
			out(re[v],v,1);
			re[v].insert(re[v].begin()+cs[v],v);
			return;
		};
	dfs(rt);
	out(re[rt],1);
	vector<int> inv(n);
	rep(i,n) inv[re[rt][i]]=i;
	cout<<"YES" NL;
	rep(i,n) cout<<inv[i]+1<<" "; cout NL;
  return 0;
	
}