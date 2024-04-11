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

struct UF{
  vector<int> data;
  UF(const int &size):data(size,-1){}
  int unite(int x, int y){
    x=root(x); y=root(y);
    if(x==y) return 0;
		if(-data[y]>-data[x]) swap(x,y);
		data[x]+=data[y]; data[y]=x;
    return y+1;
  }
  bool findSet(const int &x, const int &y){ return root(x)==root(y);}
  int root(const int &x){ return data[x]<0?x:data[x]=root(data[x]);}
  int size(const int &x){ return -data[root(x)];}
	int size(){ return count_if(all(data),[](const int &x){ return x<0;});}; //unverified
	int operator()(const int &x, const int &y){ return unite(x,y);}
	// int operator()(const pii &xy){ return unite(xy.X,xy.Y);}
	int operator[](const int &x){ return root(x);}
	bool operator[](const pii &xy){ return findSet(xy.X,xy.Y);}
};
#ifdef NUIP
ostream& operator<<(ostream &os, UF &uf){
	cauto n=uf.data.size();
	vector<int> single;
	rep(v,n)if(uf.size(v)==1) single.eb(v);
	os<<"[]"<<single;
	vv<int> vss(n);
	rep(v,n) vss[uf[v]].eb(v);
	rep(v,n)if(vss[v].size()>1) os<<"["<<v<<"]"<<vss[v];
	return os;
}
#endif

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	cauto m=read(0);
	cauto es=readV(m,pii(1,1));
	vector<int> ex(m);
	rep(i,m) ex[i]=es[i].X^es[i].Y;
	cauto n=m+m;
	UF uf(n);
	for(cauto &[a,b]:es) uf(a,b);
	{
		vector<int> cnt(n);
		for(cauto &e:es) ++cnt[uf[e.X]];
		if(any_of(all(cnt),[](cauto &v){return v==1;})){
			cout<<-1 NL;
			return 0;
		}
	}
	vv<int> g(n);
	rep(i,m){
		cauto &[a,b]=es[i];
		g[a].eb(i);
		if(a!=b) g[b].eb(i);
		assert(0<=a && a<n);
		assert(0<=b && b<n);
	}
	out(g,1);
	vector<int> vst(n);
	vector<tuple<int,int,int>> tps;
	vector<tuple<int,int,int,int,int,int>> tps6;
	vector<int> usde(m);
	cauto dfs=
		[&](auto &&dfs,int v,int pe)->bool{
			if(!MX(vst[v],1)) return false;
			int reme=-1;
			for(cauto &e:g[v]){
				if(!MX(usde[e],1)) continue;
				if(!dfs(dfs,ex[e]^v,e)){
					out(v,e,reme,e,1);
					if(reme<0){
						reme=e;
					}else{
						tps.eb(ex[reme]^v,v,ex[e]^v);
						reme=-1;
					}
				}
			}
			out(v,pe,reme,1);
			if(reme<0) return false;
			if(pe>=0){
				tps.eb(ex[reme]^v,v,ex[pe]^v);
				return true;
			}
			auto x=v;
			auto y=ex[reme]^v;
			cauto [a,b,c]=tps.back(); tps.pop_back();
			if(x!=a && x!=b && x!=c) swap(x,y);
			if(x==b){
				tps6.eb(b,a,c,b,b,y);
			}else if(x==a){
				tps6.eb(y,a,a,b,b,c);
			}else if(x==c){
				tps6.eb(a,b,b,c,c,y);
			}else rep(_,MOD) cout<<string(MOD,'.') NL;
			return false;
		};
	rep(v,n) dfs(dfs,v,-1);
	assert(all_of(all(usde),[](cauto &v){return v==1;}));
	assert(all_of(all(vst),[](cauto &v){return v==1;}));
	out(tps,tps.size(),1);
	cout<<m<<" 2" NL;
	cout NL;
	for(cauto &[a,b,c]:tps){
		cout<<a+1<<" "<<b+1 NL;
		cout<<b+1<<" "<<c+1 NL;
	}
	for(cauto &[a,b,c,d,e,f]:tps6){
		cout<<a+1<<" "<<b+1 NL;
		cout<<c+1<<" "<<d+1 NL;
		cout<<e+1<<" "<<f+1 NL;
	}
	cout NL;
	rep(_,tps.size()) cout<<"LR\nLR" NL;
	rep(_,tps6.size()) cout<<"LR\nUU\nDD\n";
	cout NL;
	rep(_,tps.size()){
		cout<<"UU" NL;
		cout<<"DD" NL;
	}
	rep(_,tps6.size()) cout<<"UU\nDD\nLR\n";
	return 0;
}