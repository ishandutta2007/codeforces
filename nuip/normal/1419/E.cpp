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
	auto T=read();
	while(T--){
		cauto n=read();
		vector<pii> ps;
		auto rem=n;
		for(ll i=2;i*i<=rem;++i){
			if(rem%i) continue;
			ps.eb(i,0);
			for(;rem%i==0;rem/=i) ++ps.back().Y;
		}
		if(rem>1) ps.eb(rem,1);
		out(ps,1);
		vector<ll> re;
		if(ps.size()==1){
			re.eb(ps[0].X);
		}else{
			re.eb(ps[0].X);
			reps(i,1,ps.size()){
				re.eb(ps[i-1].X*ps[i].X);
				re.eb(ps[i].X);
			}
			if(ps.size()>2) re.eb(ps.back().X*ps[0].X);
		}
		out(re,1);
		const int m=ps.size();
		vv<ll> nums(m);
		auto dfs=
			[&](auto &&dfs,int i,int cur,int last){
				if(i==m){
					if(last>=0) nums[last].eb(cur);
					return;
				}
				rep(j,ps[i].Y+1){
					dfs(dfs,i+1,cur,j?i:last);
					cur*=ps[i].X;
				}
			};
		dfs(dfs,0,1,-1);
		out(nums,1);
		set<int> usd(all(re));
		vector<ll> res;
		rep(i,re.size()){
			if(i%2){
				res.eb(re[i]);
			}else{
				res.eb(re[i]);
				for(auto x:nums[i/2])if(usd.count(x)==0) res.eb(x);
			}
		}
		out(res,1);
		int cnt=(__gcd(res[0],res.back())==1);
		reps(i,1,res.size()) cnt+=(gcd(res[i-1],res[i])==1);
		for(auto x:res) cout<<x<<" "; cout NL;
		cout<<cnt NL;
	}
  return 0;
}