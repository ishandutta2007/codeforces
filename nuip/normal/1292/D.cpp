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
#undef NUIP
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

vector<int> fval(5123,MOD);
vector<int> primes,pinv(5123);
array<array<int,700>,5123> cnt;

vector<int> sz,dep;
vv<pii> g(1);

int dfssz(int v,int de){
	dep[v]=de;
	for(pii e:g[v]) sz[v]+=dfssz(e.X,de+e.Y);
	return sz[v];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	reps(i,2,5023)if(fval[i]==MOD){
		pinv[i]=primes.size();
		primes.pb(i);
		for(int j=i;j<5123;j+=i) MN(fval[j],i);
	}
	// rep(i,10) out(i,fval[i],1);
	// out(primes.size(),1);
	reps(i,2,5023){
		cnt[i]=cnt[i-1];
		for(int t=i;t>1;t/=fval[t]) ++cnt[i][pinv[fval[t]]];
	}
	{
		ll sum=0;
		rep(i,5001) sum+=accumulate(all(cnt[i]),0);
		out(sum,1);
	}
	vector<int> vs(5001);
	rrep(j,700){
		unordered_map<int,vector<pii>> mp;
		rep(i,5001)if(cnt[i][j]) mp[vs[i]].eb(cnt[i][j],i);
		for(auto &p:mp){
			sort(all(p.Y));
			int v=p.X;
			int cur=0;
			for(auto dv:p.Y){
				// if(dv.Y==3) out(dv,j,cur,v,1);
				if(dv.X!=cur){
					// if(dv.Y==3) out(g.size(),1);
					int w=g.size();
					g[v].eb(w,dv.X-cur);
					g.eb();
					cur=dv.X;
					v=w;
				}
				// if(dv.Y==3) out(dv,j,cur,v,1);
				vs[dv.Y]=v;
			}
		}
	}
	// out(g.size(),1);
	// out(g[0],1);
	// out(g[443229],1);
	// out(g[448229],1);

	int n;
	cin>>n;
	vector<int> ts(n);
	rep(i,n) cin>>ts[i];
	int N=g.size();
	sz.resize(N); dep.resize(N);
	for(int t:ts) ++sz[vs[t]];
	dfssz(0,0);
	out(sz[0],1);
	vector<ll> cs(N);
	for(int t:ts) cs[0]+=dep[vs[t]];
	// for(int t:ts) out(t,vs[t],dep[vs[t]],1);
	out(cs[0],1);
	{
		queue<int> que; que.emplace(0);
		while(que.size()){
			int v=que.front(); que.pop();
			for(pii e:g[v]){
				ll shita=sz[e.X];
				ll ue=n-shita;
				cs[e.X]=cs[v]+(ue-shita)*e.Y;
				// if(e.X==443229) out(e,v,cs[v],ue,shita,cs[e.X],1);
				// if(e.X==448229) out(e,v,cs[v],cs[e.X],1);
				que.emplace(e.X);
			}
		}
	}
	// rep(i,10) out(i,vs[i],cs[vs[i]],1);
	cout<<*min_element(all(cs)) NL;
  return 0;
}
//9308
	// rreps(t,2,5001){
	// 	int v=0;
	// 	rrep(i,700)rep(_,cnt[t][i]){
	// 		int ind=-1;
	// 		rep(j,g[v].size())if(g[v][j].Y==i) ind=j;
	// 		if(ind<0){
	// 			ind=g[v].size();
	// 			g[v].eb(g.size(),i);
	// 			g.eb();
	// 		}
	// 		v=g[v][ind].X;
	// 	}
	// }
	// out(g.size(),1);
	// int cnt=0;
	// rep(i,g.size())if(g[i].size()==1) ++cnt;
	// out(g.size()-cnt,cnt,1);
	// return 0;