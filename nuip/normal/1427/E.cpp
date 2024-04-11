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

void solve(ll x){
		vector<tuple<ll,char,ll>> re;
	cauto xr=
		[&](ll x,ll y){
			re.eb(x,'^',y);
			return x^y;
		};
	xr(x,x);
	cauto ad=
		[&](ll x,ll y){
			re.eb(x,'+',y);
			return x+y;
		};
	cauto mul=
		[&](ll x,ll y){
			ll re=0;
			ll pw=x;
			for(auto i=y;i;i/=2){
				if(i%2) re=ad(re,pw);
				pw=ad(pw,pw);
			}
			return re;
		};
	while(x>1){
		int d;
		{
			auto i=x;
			while(__builtin_popcountll(i)>1) i/=2;
			d=__builtin_ctzll(i);
		}
		out(x,d,1);
		ll cur=mul(x,2ll<<d);
		ll a=cur;
		cur=xr(cur,x);
		cur=ad(cur,x);
		if(cauto tmp=cur^a;(int)__builtin_clzll(tmp)-(int)__builtin_clzll(x)>=0){
			cur=xr(cur,a);
		}else{
			a=ad(a,x);
			out(a,1);
			cur=xr(cur,a);
		}
		out(cur,1);
		while(x>1){
			auto dif=(int)__builtin_clzll(cur)-(int)__builtin_clzll(x);
			if(dif<0) break;
			if(dif==0 && cur%2){
				if(cur==x) break;
				out(dif,cur,x,1);
				cur=xr(x,cur);
				dif=(int)__builtin_clzll(cur)-(int)__builtin_clzll(x);
				out(dif,cur,x,1);
			}
			cauto pw=mul(cur,1<<dif);
			x=xr(x,pw);
			out(x,1);
		}
	}
	assert(re.size()<=100000);
	cout<<re.size() NL;
	for(cauto &[a,b,c]:re) cout<<a<<" "<<b<<" "<<c NL;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	// for(int hoge=3;hoge<100000;hoge+=2){
	// 	cout<<"hoge"<<hoge<<endl;
	// 	out(hoge,1);
	// 	solve(hoge);
	// }
	// return 0;
	auto x=read();
	solve(x);
  return 0;
}