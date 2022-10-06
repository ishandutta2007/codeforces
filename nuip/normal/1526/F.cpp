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
template<class T=ll> T read(){ T re; cin>>re; return re;}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return re;}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return re;}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return g;}
vv<int> readG(const int &n){ return readG(n,n-1);}
vv<int> readD(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); } return g;}
vv<int> readD(const int &n){ return readD(n,n-1);}
template<class T> vv<pair<int,T>> readG(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); g[b].eb(a,c);} return g;}
template<class T> vv<pair<int,T>> readG(const int &n){ return readG<T>(n,n-1);}
template<class T> vv<pair<int,T>> readD(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); } return g;}
template<class T> vv<pair<int,T>> readD(const int &n){ return readD<T>(n,n-1);}
#ifdef __cpp_init_captures
template<typename T> vector<T> readT(int n, T v){ return readV(n,v);}
template <class... Args> auto readT(int n, Args... args){ vector re(1,readT(args...));rep(_,n-1) re.eb(readT(args...));	return re;}
template<typename T, size_t... Is> void addadd(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) += get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator += (tuple<T...>& lhs, const tuple<T...>& rhs){	addadd(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator +(tuple<T...> lhs, const tuple<T...>& rhs){ return lhs += rhs;}
template<typename T, size_t... Is> void subsub(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) -= get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator -= (tuple<T...>& lhs, const tuple<T...>& rhs){	subsub(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator - (tuple<T...> lhs, const tuple<T...>& rhs){ return lhs -= rhs;}
template<class Tuple, size_t... Is> void read_tuple_impl(istream &is, Tuple& t, index_sequence<Is...>){((is >> get<Is>(t)), ...);}
template<class... Args> auto& operator>>(istream &is, tuple<Args...>& t){ read_tuple_impl(is, t, index_sequence_for<Args...>{}); return is;}
#endif
#define TT cauto TTT=read();rep(_,TTT)
const ll MOD=1e9+7; //998244353;

struct Solve{
	vector<int> ans;
	Solve(vector<int> p):ans(p){};
	Solve(int n):ans(n){}
	map<vector<int>,int> memo;
	int ask(vector<int> vs){
		sort(all(vs));
		if(memo.count(vs)) return memo[vs];
#ifdef NUIP
		vector<int> ds;
		rep(i,3)rep(j,i) ds.eb(abs(ans[vs[i]]-ans[vs[j]]));
		sort(all(ds));
		return memo[vs]=ds[1];
#endif
		cout<<"? "<<vs[0]+1<<" "<<vs[1]+1<<" "<<vs[2]+1<<endl; cout.flush();
		cauto re=read();
		if(re<0) exit(0);
		return memo[vs]=re;
	}
	void solve(){
		const int n=ans.size();
		int a,b,c;
		while(1){
			a=rand()%n;
			b=rand()%n;
			c=rand()%n;
			if(a==b || b==c || a==c) continue;
			cauto d=ask({a,b,c});
			out(a,b,c,d,1);
			if(d*6+4<n) break;
		}
		// out(a,b,c,ask({a,b,c}),1);
		pii mx;
		// rep(i,n)if(a!=i && b!=i) out(i,ask({a,b,i}),1);
		rep(i,n)if(a!=i && b!=i) MX(mx,{ask({a,b,i}),i});
		cauto i0=mx.Y;
		vector<int> vs1,vs2;
		rep(i,n)if(a!=i && b!=i){
			cauto d=mx.X-ask({a,b,i});
			if(d==1) vs1.eb(i);
			if(d==2) vs2.eb(i);
		}
		int i1;
		for(cauto &v1:vs1)for(cauto &v2:vs2)if(ask({i0,v1,v2})==1) i1=v1;
		out(a,ans[a],b,ans[b],mx,i0,ans[i0],i1,vs1,vs2,1);
		vector<int> re(n);
		re[i0]=0;
		re[i1]=1;
		rep(i,n)if(i!=i0 && i!=i1) re[i]=ask({i0,i1,i})+1;
		if(re[0]>re[1]) for(auto &v:re) v=n-1-v;
		cout<<"!";
		for(cauto &v:re) cout<<" "<<v+1;
		cout<<endl; cout.flush();
#ifdef NUIP
		assert(re==ans);
#else
		if(read()<0) exit(0);
#endif
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	// Solve({3,19,13,22,15,27,28,14,20,8,18,5,23,4,2,11,6,1,0,26,12,7,24,16,10,25,9,17,21}).solve(); return 0;
	if(0)rep(_,100){
		cauto n=rand()%10+20;
		vector<int> perm(n); iota(all(perm),0);
		while(1){
			random_shuffle(all(perm));
			if(perm[0]<perm[1]) break;
		}
		out(perm,1);
		Solve(perm).solve();
	}
	TT{
		cauto n=read();
		Solve(n).solve();
	}
	return 0;
}