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
void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}
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
#define TT cauto TTT=read();rep(_,TTT)
const ll MOD=1e9+7; //998244353;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto vs=readV(n);
	cauto s=read<string>();
	if(s.size()==1){
		rep(i,n) cout<<(i?s:"")<<vs[i]; cout NL;
		return 0;
	}
	cauto minu=count(all(s),'-');
	cauto plus=count(all(s),'+');
	cauto mult=count(all(s),'*');
	if(!mult){
		rep(i,n) cout<<(i?"+":"")<<vs[i]; cout NL;
		return 0;
	}
	if(!plus){
		rep(i,n) cout<<(i?vs[i]?"*":"-":"")<<vs[i]; cout NL;
		return 0;
	}
	cauto solve=
		[&](const vector<int> &vs){
			if(vs.empty()) return;
			if(count(all(vs),1)==vs.size()){
				rep(i,vs.size()) cout<<(i?"+":"")<<"1";
				return;
			}
			ll prod=1;
			for(cauto v:vs) MN(prod*=v,MOD);
			if(prod==MOD){
				int l=0;
				while(vs[l]==1) ++l;
				int r=vs.size();
				while(vs[r-1]==1) --r;
				rep(i,vs.size()){
					if(i) cout<<(i<=l || r<=i ? "+" : "*");
					cout<<vs[i];
				}
				return;
			}
			vector<pll> ps;
			vector<int> ind;
			rep(i,vs.size()){
				cauto v=vs[i];
				if(ps.empty() || ps.back().X!=(v==1)) ps.eb(v==1,v!=1), ind.eb(i);
				if(v==1) ++ps.back().Y;
				else MN(ps.back().Y*=v,MOD);
			}
			ind.eb(vs.size());
			out(ps,ind,1);
			cauto n=(int)ps.size();
			vector<pll> dp(n+1);
			rep(i,n){
				ll p=1;
				reps(j,i,n){
					if(ps[j].X==0) p*=ps[j].Y;
					MX(dp[j+1],pll(dp[i].X+p,i));
				}
				if(ps[i].X)	MX(dp[i+1],pll(dp[i].X+ps[i].Y,n));
			}
			out(dp,1);
			string re;
			for(int i=n;i;){
				cauto t=dp[i].Y;
				if(t==n){
					--i;
					rep(_,ps[i].Y) re+="+1";
				}else{
					rreps(j,ind[t],ind[i]) re+=(j+1==ind[i]?"+"s:"*"s)+string(1,'0'+vs[j]);
					i=t;
				}
				out(i,re,1);
			}
			reverse(all(re));
			re.pop_back();
			cout<<re;
		};
	vector<int> cur;
	int f=0;
	for(cauto v:vs){
		if(v){
			cur.eb(v);
		}else{
			if(cur.size()){
				if(f) cout<<"+";
				f=1;
				solve(cur);
				cur.clear();
			}
			if(f) cout<<"+";
			cout<<"0";
			f=1;
		}
	}
	if(cur.size()){
		if(f) cout<<"+";
		f=1;
		solve(cur);
		cur.clear();
	}
	cout NL;
  return 0;
}