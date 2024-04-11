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
#define out
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m,t,q;
	cin>>n>>m>>t>>q;
	vector<int> lb(n,m),rb(n,-1);
	int h=-1;
	rep(i,t){
		int a,b;
		cin>>a>>b; --a; --b;
		MX(h,a);
		MN(lb[a],b);
		MX(rb[a],b);
	}
	out(lb,rb,1);
	vector<int> cols(q);
	rep(i,q) cin>>cols[i], --cols[i];
	sort(all(cols));
	const ll INF=1e15;
	auto dst=
		[&](int x,int y,int i){
			if(i==0) return llabs(x-y);
			ll re=INF;
			auto it=lower_bound(all(cols),x);
			if(it!=cols.end()){
				MN(re, llabs(x-*it)+llabs(y-*it));
			}
			if(it!=cols.begin()){
				--it;
				MN(re, llabs(x-*it)+llabs(y-*it));
			}
			out(x,y,re,1);
			return re;
		};
	pll dpl(0,0),dpr(0,0);
	rep(i,n)if(lb[i]<=rb[i]){
		pll nxl(lb[i],INF),nxr(rb[i],INF);
		ll d=rb[i]-lb[i];
		MN(nxl.Y, dpl.Y+dst(dpl.X, nxr.X,i)+d);
		MN(nxl.Y, dpr.Y+dst(dpr.X, nxr.X,i)+d);
		MN(nxr.Y, dpl.Y+dst(dpl.X, nxl.X,i)+d);
		MN(nxr.Y, dpr.Y+dst(dpr.X, nxl.X,i)+d);
		dpl=nxl; dpr=nxr;
		out(dpl,dpr,1);
	}
	cout<<h+min(dpl.Y,dpr.Y)<<endl;
  return 0;
}