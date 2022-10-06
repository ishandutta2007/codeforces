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

void solve(vector<int> a){
	int n=a.size();
	vector<pii> ps;
	{
		unordered_map<int,int> mp;
		for(int x:a) ++mp[x];
		for(auto p:mp) ps.eb(p.Y,p.X);
		sort(all(ps));
	}
	// out(ps,1);
	int rem=ps.size();
	int t=0;
	int sum=n;
	int mx=0,mxi,mxj;
	rreps(i,1,1123){
		while(rem && ps[rem-1].X>i){
			++t;
			--rem;
			sum-=ps[rem].X;
		}
		int j=(sum+i*t)/i;
		if(j<i) continue;
		if(MX(mx,i*j)) mxi=i, mxj=j;
	}
	out(mx,mxi,1);
	vv<int> re(mxi,vector<int>(mxj));
	int cnt=0;
	rrep(i,ps.size()){
		auto p=ps[i];
		// out(p,min(mxi,p.X),1);
		rep(_,min(mxi,p.X)){
			if(cnt>=mxi*mxj) break;
			re[cnt%mxi][cnt/mxi]=p.Y;
			++cnt;
		}
		if(cnt>=mxi*mxj) break;
	}
	assert(cnt==mxi*mxj);
	// out(re,1);
	rep(i,mxi-1){
		int d=i+1;
		auto tmp=re[i];
		rep(j,mxj-d) re[i][j+d]=tmp[j];
		reps(j,mxj-d,mxj) re[i][j+d-mxj]=tmp[j];
	}
	// out(re,1);
	cout<<mxi*mxj NL;
	cout<<mxi<<" "<<mxj NL;
	rep(i,mxi)rep(j,mxj) cout<<re[i][j]<<" \n"[j+1==mxj];
	// 	vector<set<int>> is(mxi),js(mxj);
	// rep(i,mxi)rep(j,mxj) js[j].emplace(re[i][j]), is[i].emplace(re[i][j]);
	// rep(j,mxj) assert(js[j].size()==mxi);
	// rep(i,mxi) assert(is[i].size()==mxj);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	if(0){
		vector<int> a(1); iota(all(a),1);
		solve(a);
		return 0;
	}
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	solve(a);
  return 0;
}