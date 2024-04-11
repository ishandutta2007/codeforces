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
#define rep(X,Y) for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"
#define cauto const auto

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
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return move(re);}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
const ll MOD=1e9+7; //998244353

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	auto vs=readV(n,0);
	// vector<int> vs(n,1); vs[0]=2;
	const int M=101;
	{
		vector<int> cnt(M);
		for(cauto v:vs) ++cnt[v];
		cauto mxi=max_element(all(cnt))-cnt.begin();
		cauto mx=cnt[mxi];
		if(mx==n){
			cout<<0 NL;
			return 0;
		}
		rep(i,M)if(i!=mxi && cnt[i]==mx){
			cout<<n NL;
			return 0;
		}
		for(auto &v:vs)if(v==mxi) v=0;
	}
	out(vs,1);
	vector<int> val(M);
	vector<deque<int>> lb(M,{0});
	int mx=0;
	rep(i,n){
		cauto v=vs[i];
		if(v){
			// if(i-lb[v][val[v]]==6) out(i,v,lb[v][val[v]],1);
		  MX(mx,i-lb[v][val[v]]);
			++val[v];
			if((int)lb[v].size()>val[v]){
				MN(lb[v][val[v]],i+1);
			}else{
				lb[v].push_back(i+1);
			}
				
		}else{
			reps(v,1,M){
				// if(i-lb[v][val[v]]==6) out(i,v,lb[v][val[v]],1);
				MX(mx,i-lb[v][val[v]]);
				lb[v].push_front(MOD);
				MN(lb[v][val[v]],i+1);
			}
		}
		// out(i,v,val,lb,1);
	}
	// reps(v,1,M) if(n-lb[v][val[v]]==6) out(v,lb[v][val[v]],val[v],1);
	reps(v,1,M) MX<int>(mx,n-lb[v][val[v]]);
	cout<<mx NL;
  return 0;
}