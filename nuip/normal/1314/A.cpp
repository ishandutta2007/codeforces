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
	vector<int> a(n),t(n);
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>t[i];
	map<int,pair<priority_queue<int>,ll>> mp;
	rep(i,n){
		mp[a[i]].Y+=t[i];
		mp[a[i]].X.emplace(t[i]);
	}
	ll re=0;
	while(mp.size()){
		if(mp.begin()->Y.X.size()==1){
			mp.erase(mp.begin());
			continue;
		}
		int i=mp.begin()->X;
		{
			auto t=mp[i].X.top(); mp[i].X.pop();
			mp[i].Y-=t;
		}
		mp[i+1].Y+=mp[i].Y;
		re+=mp[i].Y;
		auto &lhs=mp[i+1].X;
		auto &rhs=mp[i].X;
		if(lhs.size()<rhs.size()) swap(lhs,rhs);
		while(rhs.size()){
			lhs.emplace(rhs.top()); rhs.pop();
		}
		mp.erase(mp.begin());
	}
	cout<<re NL;
  return 0;
}