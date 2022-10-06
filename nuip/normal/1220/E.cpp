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
#include "../benri.h"
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
	int n,m;
	cin>>n>>m;
	vector<ll> a(n);
	rep(i,n) cin>>a[i];
	out(accumulate(all(a),0ll)-210,1);
	vv<int> g(n);
	rep(i,m){
		int x,y;
		cin>>x>>y; --x; --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int s;
	cin>>s; --s;
	if(n==1){
		cout<<a[0]<<endl;
		return 0;
	}
	vector<int> deg(n);
	queue<int> que;
	rep(i,n){
		deg[i]=g[i].size();
		if(deg[i]==1){
			que.emplace(i);
		}
	}	
	vector<ll> sum(n);
	vector<int> rm(n);
	while(que.size()){
		int v=que.front(); que.pop();
		out(v,1);
		if(v==s) continue;
		rm[v]=1;
		sum[v]+=a[v];
		for(int w:g[v]){
			--deg[w];
			MX(sum[w],sum[v]);
			if(deg[w]==1){
				que.emplace(w);
			}
		}
	}
	out(sum,1);
	ll re=0;
	ll mx=0;
	rep(i,n)if(!rm[i]){
		re+=a[i];
		for(int v:g[i])if(rm[v]) MX(mx,sum[v]);
	}
	re+=mx;
	cout<<re<<endl;
  return 0;
}