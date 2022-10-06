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

using AR=array<pll,20>;
const ll INF=1e17;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int last=0,cnt=1;
	int q;
	cin>>q;
	vv<int> g(1);
	AR e; fill(all(e),pll(-1,INF));
	out(e,1);
	vector<int> ws{0};
	vector<AR> ancs(1,e);
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			ll p_,q_;
			cin>>p_>>q_;
			int p=p_^last; --p;
			ll w=q_^last;
			int v=cnt; ++cnt;
			out(p,w,1);
			g[p].pb(v);
			ws.pb(w);
			ancs.eb(e);
			g.eb();
			if(ws[p]>=ws[v]){
				ancs.back()[0]=pll(p,ws[p]);
			}else{
				int w=p;
				out(p,ancs[w][0],1);
				rrep(i,20)if(ancs[w][i].X>=0 && ws[ancs[w][i].X]<ws[v]) w=ancs[w][i].X;
				out(w,1);
				w=ancs[w][0].X;
				out(w,1);
				if(w>=0){
					ancs.back()[0]=pll(w,ws[w]);
				}
			}
			auto &anc=ancs.back();
			rep(i,19){
				if(anc[i].X<0) break;
				anc[i+1].X=ancs[anc[i].X][i].X;
				out(i,anc[i],ancs[anc[i].X][i],1);
				MN(anc[i+1].Y=ancs[anc[i].X][i].Y,INF);
				MN(anc[i+1].Y+=anc[i].Y,INF);
			}
			out(anc,1);
		}else{
			ll p_,q_;
			cin>>p_>>q_;
			int v=p_^last; --v;
			ll w=q_^last;
			out(v,w,1);
			w-=ws[v];
			ll re=0;
			if(w>=0){
				++re;
				out(w,1);
				rrep(i,19){
					out(i,v,w,ancs[v][i],1);
					if(w>=ancs[v][i].Y){
						re+=(1<<i);
						w-=ancs[v][i].Y;
						v=ancs[v][i].X;
					}
				}
			}
			cout<<re NL;
			last=re;
		}
	}
  return 0;
}
//0 3 3 1 2