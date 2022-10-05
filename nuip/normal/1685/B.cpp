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
#define TT cauto TTT=read();rep(_,TTT)
struct sorted_impl{template<class T>friend vector<T>operator-(vector<T>a,sorted_impl){sort(all(a));return a;}friend string operator-(string a,sorted_impl){sort(all(a));return a;}}sorted;struct reversed_impl{template<class T>friend vector<T>operator-(vector<T> a,reversed_impl){reverse(all(a));return a;}friend string operator-(string a,reversed_impl){reverse(all(a));return a;}}reversed;struct distinct_impl{template<class T>friend vector<T>operator-(vector<T> a,distinct_impl){sort(all(a));UNIQUE(a);return a;}}distinct;template<class S>struct sortedWith{const S f;sortedWith(const S &f):f(f){}template<class T>friend vector<T>operator-(vector<T> a,const sortedWith&b){sort(all(a),[&](cauto&i,cauto&j){return b.f(i)<b.f(j);});return a;}};
template<class T>int operator/(const T&v,const vector<T>&vs){return lower_bound(all(vs),v)-vs.begin();}
vector<int> Inds(const int n){vector<int> inds(n);iota(all(inds),0);return inds;}
const ll MOD=1e9+7; //998244353;

bool solve(int a, int b, int ab, int ba, const string s){
	if(a+ab+ba>count(all(s),'A') || b+ab+ba>count(all(s),'B')) return false;
	vector<pii> ps(1);
	vector<int> lb{(int)(s[0]=='B')};
	{
		char prv='.';
		for(cauto &c:s){
			if(prv==c){
				ps.eb();
				lb.eb(c=='B');
			}
			++(c=='A'?ps.back().X:ps.back().Y);
			prv=c;
		}
	}
	int any=0;
	vector<int> abab,baba;
	rep(i,ps.size()){
		cauto &[ca,cb]=ps[i];
		if(ca==cb){
			if(ca==1){
				--(lb[i]?ba:ab);
			}else{
				(lb[i]?baba:abab).eb(ca);
			}
		}else{
			any+=min(ca,cb);
			--(ca>cb?a:b);
		}
	}
	out(ps,a,b,ab,ba,abab,baba,any,1);
	MX(a,0); MX(b,0); MX(ab,0); MX(ba,0);
	cauto check=
		[&](int ab, int ba, int any, vector<int> abab, vector<int> baba){
			out(ab,ba,any,abab,baba,1);
			ab-=accumulate(all(abab),0);
			MX(ab,0);
			auto tmp=min(ab,any);
			ab-=tmp;
			any-=tmp;
			sort(all(baba));
			while(ab && baba.size()){
				if(ab<baba.back()-1){
					baba.back()-=ab+1;
					ab=0;
					break;
				}else{
					ab-=baba.back()-1;
					baba.pop_back();
				}
			}
			out(ab,ba,any,abab,baba,1);
			return ab==0 && ba<=any+accumulate(all(baba),0);
		};
	return check(ab,ba,any,abab,baba)||check(ba,ab,any,baba,abab);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	// out(solve(2,3,5,4,"AABAABBABAAABABBABBBABB"),1); return 0;
	// vector<string> ss{"A","B","AB","BA"};
	// map<string,set<tuple<int,int,int,int>>> mp;
	// rep(a,3)rep(b,3)rep(ab,3)rep(ba,3)if(cauto s=a+b+2*ab+2*ba; s&&s<=6){
	// 	vector<int> vs;
	// 	rep(i,a) vs.eb(0);
	// 	rep(i,b) vs.eb(1);
	// 	rep(i,ab) vs.eb(2);
	// 	rep(i,ba) vs.eb(3);
	// 	do{
	// 		string s;
	// 		for(cauto &v:vs) s+=ss[v];
	// 		mp[s].emplace(a,b,ab,ba);
	// 		cauto re=solve(a,b,ab,ba,s);
	// 		if(!re){
	// 			out(a,b,ab,ba,s,1);
	// 			exit(0);
	// 		}
	// 	}while(next_permutation(all(vs)));
	// }
	// for(cauto &[s,tps]:mp){
	// 	rep(a,3)rep(b,3)rep(ab,3)rep(ba,3)if(cauto sum=a+b+2*ab+2*ba; sum==s.size()){
	// 		cauto exp=tps.count(tuple(a,b,ab,ba));
	// 		cauto act=solve(a,b,ab,ba,s);
	// 		if(exp!=act){
	// 			out(a,b,ab,ba,s,exp,act,1);
	// 			exit(0);
	// 		}
	// 	}
	// }
	// return 0;
	TT{
		auto a=read(0);
		auto b=read(0);
		auto ab=read(0);
		auto ba=read(0);
		cauto s=read<string>();
		cout<<(solve(a,b,ab,ba,s)?"YES":"NO") NL;
	}
	return 0;
}