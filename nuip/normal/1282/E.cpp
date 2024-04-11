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

using TP=tuple<int,int,int>;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<TP> tris;
		map<pii,int> st;
		vv<int> g(n-2);
		auto add=
			[&](int a,int b,int i){
				if(a>b) swap(a,b);
				auto p=st.emplace(pii(a,b),i);
				if(!p.Y){
					int j=p.X->Y;
					g[i].pb(j);
					g[j].pb(i);
					st.erase(p.X);
				}
			};
		rep(i,n-2){
			int a,b,c;
			cin>>a>>b>>c; --a; --b; --c;
			tris.eb(a,b,c);
			add(a,b,i); add(b,c,i); add(a,c,i);
		}
		vector<pii> ps(n,pii(-1,-1));
		vector<int> seq(2);
		for(auto pp:st){
			int a,b; tie(a,b)=pp.X;
			if(ps[a].X<0) ps[a].X=b; else ps[a].Y=b;
			if(ps[b].X<0) ps[b].X=a; else ps[b].Y=a;
			seq[0]=a; seq[1]=b;
		}
		seq.reserve(n+1);
		while(seq.size()<=n){
			int p=seq[seq.size()-2];
			int c=seq.back();
			seq.pb(ps[c].X==p?ps[c].Y:ps[c].X);
		}
		out(seq,1);
		vector<int> ord;
		function<void(int,int)> dfs=
			[&](int v,int p){
				for(int w:g[v])if(w!=p) dfs(w,v);
				ord.pb(v);
			};
		dfs(0,-1);
		out(ord,1);
		rep(i,n) cout<<seq[i]+1<<" \n"[i+1==n];
		rep(i,n-2) cout<<ord[i]+1<<" \n"[i+1==n-2];
	}
  return 0;
}