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
#include <chrono>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int X = 0;X < (int)(Y);++X)
#define reps(X,S,Y) for (int X = (int)(S);X < (int)(Y);++X)
#define rrep(X,Y) for (int X = (int)(Y)-1;X >=0;--X)
#define rreps(X,S,Y) for (int X = (int)(Y)-1;X >= (int)(S);--X)
#define repe(X,Y) for (X = 0;X < (Y);++X)
#define peat(X,Y) for (;X < (Y);++X)
#define all(X) X.begin(),X.end()
#define rall(X) X.rbegin(),X.rend()
#define eb emplace_back
#define UNIQUE(X) X.erase(unique(all(X)),X.end())
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
#ifdef __cpp_deduction_guides
template<typename T> vector<T> readT(int n, T v){ return readV(n,v);}
template <class... Args> auto readT(int n, Args... args){ vector re(1,readT(args...));rep(_,n-1) re.eb(readT(args...));	return re;}
template<class Tuple, size_t... Is> void read_tuple_impl(istream &is, Tuple& t, index_sequence<Is...>){((is >> get<Is>(t)), ...);}
template<class... Args> auto& operator>>(istream &is, tuple<Args...>& t){ read_tuple_impl(is, t, index_sequence_for<Args...>{}); return is;}
template<class T> bool erase(multiset<T> &st, const T &v){if(cauto it=st.find(v); it==st.end()) return false; else{ st.erase(it); return true;}}
#endif
#ifdef __cpp_init_captures
template<typename T, size_t... Is> void addadd(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) += get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator += (tuple<T...>& lhs, const tuple<T...>& rhs){	addadd(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator +(tuple<T...> lhs, const tuple<T...>& rhs){ return lhs += rhs;}
template<typename T, size_t... Is> void subsub(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) -= get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator -= (tuple<T...>& lhs, const tuple<T...>& rhs){	subsub(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator - (tuple<T...> lhs, const tuple<T...>& rhs){ return lhs -= rhs;}
#endif
#ifdef NUIP
#define TT cauto TTT=read();rep(kase,TTT)if(cerr<<"Case #"<<kase<<endl)
#else
#define TT cauto TTT=read();rep(kase,TTT)
#endif
struct sorted_impl{template<class T>friend vector<T>operator-(vector<T>a,sorted_impl){sort(all(a));return a;}friend string operator-(string a,sorted_impl){sort(all(a));return a;}}sorted;struct reversed_impl{template<class T>friend vector<T>operator-(vector<T> a,reversed_impl){reverse(all(a));return a;}friend string operator-(string a,reversed_impl){reverse(all(a));return a;}}reversed;struct distinct_impl{template<class T>friend vector<T>operator-(vector<T> a,distinct_impl){sort(all(a));UNIQUE(a);return a;}}distinct;template<class S>struct sortedWith{const S f;sortedWith(const S &f):f(f){}template<class T>friend vector<T>operator-(vector<T> a,const sortedWith&b){sort(all(a),[&](cauto&i,cauto&j){return b.f(i)<b.f(j);});return a;}};
template<class T>int operator/(const T&v,const vector<T>&vs){return lower_bound(all(vs),v)-vs.begin();}
vector<int> Inds(const int n){vector<int> inds(n);iota(all(inds),0);return inds;}
const ll MOD=1e9+7; //998244353;

using TP=tuple<ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll,ll>;
const int nn=312345;
TP bit[nn+1];

TP sum(int i){ ++i;
  TP s{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i, TP x){ ++i; ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	cauto n=read(0);
	cauto q=read(0);
	auto vs=readV(n,0);
	map<int,set<int>> inv;
	mt19937 rand(chrono::steady_clock::now().time_since_epoch().count());
	cauto getH=
		[&](const int x){
			cauto it=inv.find(x);
			if(it==inv.end()) return TP(rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand(),rand());
			cauto i=*(it->Y.begin());
			return sum(i+1)-sum(i);
		};
	// out(get<0>(getH(3)),1);
	// out(get<0>(getH(4)),1);
	// out(get<0>(getH(3)),1);
	rep(i,n){
		add(i,getH(vs[i]));
		inv[vs[i]].emplace(i);
	}
	rep(_,q){
		if(read(0)==1){
			cauto i=read(1);
			cauto x=read(0);
			cauto tmp=getH(x)-getH(vs[i]);
			inv[vs[i]].erase(i);
			if(inv[vs[i]].empty()) inv.erase(vs[i]);
			add(i,tmp);
			vs[i]=x;
			inv[vs[i]].emplace(i);
		}else{
			cauto l=read(1);
			cauto r=read(0);
			cauto t=read(0);
			cauto tp=sum(r)-sum(l);
			cauto re=(get<0>(tp)%t==0 && get<1>(tp)%t==0 && get<2>(tp)%t==0 && get<3>(tp)%t==0 && get<4>(tp)%t==0 &&
								get<5>(tp)%t==0 && get<6>(tp)%t==0 && get<7>(tp)%t==0 && get<8>(tp)%t==0 && get<9>(tp)%t==0 &&
								get<10>(tp)%t==0 && get<11>(tp)%t==0 && get<12>(tp)%t==0 && get<13>(tp)%t==0 && get<14>(tp)%t==0 &&
								get<15>(tp)%t==0 && get<16>(tp)%t==0 && get<17>(tp)%t==0 && get<18>(tp)%t==0 && get<19>(tp)%t==0&&
								get<20>(tp)%t==0 && get<21>(tp)%t==0 && get<22>(tp)%t==0 && get<23>(tp)%t==0 && get<24>(tp)%t==0 &&
								get<25>(tp)%t==0 && get<26>(tp)%t==0 && get<27>(tp)%t==0 && get<28>(tp)%t==0 && get<29>(tp)%t==0 &&
								get<30>(tp)%t==0 && get<31>(tp)%t==0 && get<32>(tp)%t==0 && get<33>(tp)%t==0 && get<34>(tp)%t==0 &&
								get<35>(tp)%t==0 && get<36>(tp)%t==0 && get<37>(tp)%t==0 && get<38>(tp)%t==0 && get<39>(tp)%t==0);
			cout<<(re?"YES":"NO") NL;
		}
	}
	return 0;
}