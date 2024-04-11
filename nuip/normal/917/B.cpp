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

int A[30][112][112];
int B[30][112][112];
using Graph=vv<pii>;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>n>>m;
	vv<pii> g(n);
	rep(_,m){
		int a,b;
		char c;
		cin>>a>>b>>c; --a; --b;
		g[a].eb(b,c-'a');
	}
	vector<int> topo;
	{
		vector<int> inds(n);
		rep(v,n)for(auto [w,a]:g[v]) ++inds[w];
		queue<int> que; rep(v,n)if(!inds[v]) que.emplace(v);
		while(que.size()){
			int v=que.front(); que.pop();
			topo.pb(v);
			for(auto [w,a]:g[v])if(--inds[w]==0) que.emplace(w);
		}
	}
	reverse(all(topo));
	out(topo,1);
	rrep(i,26){
		for(auto a:topo)for(auto b:topo){
		// rep(a,n)rep(b,n){
			A[i][a][b]|=A[i+1][a][b];
			for(auto [w,e]:g[a])if(e>=i && B[e][w][b]==0) A[i][a][b]=1;
			B[i][a][b]|=B[i+1][a][b];
			for(auto [w,e]:g[b])if(e>=i && A[e][a][w]==0) B[i][a][b]=1;
		}
		out(A[i][3][3],1);
	}
	rep(i,n){rep(j,n) cout<<"BA"[A[0][i][j]]; cout NL;}
  return 0;
}