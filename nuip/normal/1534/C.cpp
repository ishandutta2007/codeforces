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
	int operator()(const pii &xy){ return unite(xy.X,xy.Y);}
	int operator[](const int &x){ return root(x);}
	bool operator[](const pii &xy){ return findSet(xy.X,xy.Y);}
};

ll modpow_(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
template <int mod=MOD> struct ModInt{
  int v;
  ModInt(int v=0):v(v){}
  ModInt operator+(const ModInt &n)const{return v+n.v<mod ? v+n.v : v+n.v-mod;}
  ModInt operator-(const ModInt &n)const{return v-n.v<0 ? v-n.v+mod : v-n.v;}
  ModInt operator*(const ModInt &n)const{return ll(v)*n.v%mod;}
  ModInt operator/(const ModInt &n)const{return ll(v)*modpow_(n.v%mod,-1,mod)%mod;}
  ModInt operator+(const ll &n)const{return v+n<mod ? v+n : v+n-mod;}
  ModInt operator-(const ll &n)const{return v-n<0 ? v-n+mod : v-n;}
  ModInt operator*(const ll &n)const{return ll(v)*(n%mod)%mod;}
  ModInt operator/(const ll &n)const{return ll(v)*modpow_(n%mod,-1,mod)%mod;}
  ModInt& operator+=(const ModInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  ModInt& operator-=(const ModInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  ModInt& operator*=(const ModInt &n){v=ll(v)*n.v%mod; return *this;}
  ModInt& operator/=(const ModInt &n){v=ll(v)*modpow_(n.v,-1,mod)%mod; return *this;}
  ModInt& operator+=(const ll &n){v+=n; if(v>=mod) v-=mod; return *this;}
  ModInt& operator-=(const ll &n){v-=n; if(v<0) v+=mod; return *this;}
  ModInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  ModInt& operator/=(const ll &n){v=ll(v)*modpow_(n,-1,mod)%mod; return *this;}
	bool operator==(const ModInt &n)const{return v==n.v;};
	bool operator!=(const ModInt &n)const{return v!=n.v;};
	ModInt& operator++(){ return operator+=(1); }
	ModInt& operator--(){ return operator-=(1); }
	ModInt operator++(int i){ ModInt tmp(*this); operator++(); return tmp; }
	ModInt operator--(int i){ ModInt tmp(*this); operator--(); return tmp; }
};
#ifdef NUIP
class MINT_FRAC____{
public:
	unordered_map<int,pii> dict;
	MINT_FRAC____(int n){
		rep(p,n+1)reps(q,1,n+1)if(__gcd(p,q)==1){
			dict[1ll*p*modpow_(q,-1)%MOD]=pii(p,q);
			dict[MOD-1ll*p*modpow_(q,-1)%MOD]=pii(-p,q);
		}
	}
} Il1Il1Il1(1000);
template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){if(Il1Il1Il1.dict.count(n.v)) os<<n.v, cerr<<"("<<Il1Il1Il1.dict[n.v].X<<"/"<<Il1Il1Il1.dict[n.v].Y<<")";else os<<n.v;return os;};
#else
template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){return os<<n.v;};
#endif
template<int mod> ModInt<mod> operator+(const ll &n,const ModInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> ModInt<mod> operator-(const ll &n,const ModInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> ModInt<mod> operator*(const ll &n,const ModInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> ModInt<mod> operator/(const ll &n,const ModInt<mod> &m){return ModInt<mod>(n%mod)/m;}
typedef ModInt<MOD> mint;
template <int mod> ModInt<mod> modpow(ModInt<mod> r,ll n){ ModInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;
mint comb(ll n,ll r){ if(n<r||r<0)return 0; return fact[n]*finv[n-r]*finv[r];}
class Doralion{
  void Modinvs(vector<mint> &re,int n){ re.resize(n+1); re[1]=1; for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);}
  void Facts(vector<mint> &re,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*(i+1);}
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*inv[i+1];}
public:
  Doralion(int n){ Modinvs(inv,n); Facts(fact,n); Factinvs(finv,inv,n);}
} doralion(1123456);
using pmm=pair<mint,mint>;
mint modpow(ll r,ll n){ return modpow_(r,n);}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	TT{
		cauto n=read();
		cauto vs=readV(n,1);
		cauto ws=readV(n,1);
		vector<int> inv(n);
		rep(i,n) inv[ws[i]]=i;
		UF uf(n);
		rep(i,n) uf(i,inv[vs[i]]);
		mint re=1;
		rep(i,n)if(uf[i]==i) re+=re;
		cout<<re NL;
	}
	return 0;
}