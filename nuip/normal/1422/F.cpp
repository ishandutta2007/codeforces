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
template<int mod> ostream& operator<<(ostream &os,const ModInt<mod> &n){if(Il1Il1Il1.dict.count(n.v)) os<<n.v<<"("<<Il1Il1Il1.dict[n.v].X<<"/"<<Il1Il1Il1.dict[n.v].Y<<")";else os<<n.v;return os;};
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


vector<int> primes,prime;
class PRPRPR{
public:
  PRPRPR(int PRIME_MAX){
    prime.resize(PRIME_MAX);
    for(int i=2;i<PRIME_MAX;i++)if(!prime[i]){
	primes.pb(i);
	for(int j=i*2;j<PRIME_MAX;j+=i)
	  prime[j]=1;
      }
  }
} prprprpr(212345);

const int P=86;
using AR=array<int,P>;
AR zero;
struct Seg{
	AR mx;
  Seg(AR &ar=zero):mx(ar){}
  static Seg e;
};
Seg Seg::e=Seg();

Seg operator+(const Seg &l,const Seg &r){
	Seg re;
	rep(i,P) re.mx[i]=max(l.mx[i],r.mx[i]);
  return re;
}


template<class SegTree>
struct SegTreeUpdater{
	SegTree *st;
	int i;
	SegTreeUpdater(SegTree *st,int i):st(st),i(i){}
	template<class Seg> void operator+=(const Seg &seg){ st->add(i,seg);}
	template<class Seg> void operator=(const Seg &seg){	st->assign(i,seg);}
};

template<class Seg>
struct SegTree{
	vector<Seg> segs;
	void add(int k,Seg a){
		k+=segs.size()/2-1;
		segs[k]=segs[k]+a;
		upd(k);
	}
	void assign(int k,Seg a){
		k+=segs.size()/2-1;
		segs[k]=a;
		upd(k);
	}
	void upd(int k){
		while(k>0){
			k=(k-1)/2;
			segs[k]=segs[k*2+1]+segs[k*2+2];
		}
	}
	void upd(){	rrep(k,segs.size()/2-1) segs[k]=segs[k*2+1]+segs[k*2+2];}
	
	//(l,r,0,0,nn)
	template<class T=Seg> T query(int a,int b,int k,int l,int r){
		if(r<=a || b<=l)return T::e;
		if(a<=l && r<=b) return segs[k];
		T lv=query(a,b,k*2+1,l,(l+r)/2) ,rv= query(a,b,k*2+2,(l+r)/2,r);
		return lv+rv;
	}

	SegTree(int n){
		int pw=1;
		while(pw<n) pw*=2;
		segs.resize(2*pw);
	}
	SegTreeUpdater<SegTree<Seg>> operator[](int i){ return {this,i};}
	Seg operator()(int l,int r){ return query(max(0,l),min((int)segs.size()/2,r),0,0,segs.size()/2);};
	Seg& operator()(int i){ return segs[segs.size()/2-1+i];}
	Seg operator()(){ return segs[0];}
};


int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	out(primes[85],primes[86],primes[86]*primes[86],1);
	cauto n=read();
	cauto vs=readV(n);
	// auto vs=primes; vs.resize(n,100);
	cauto q=read();
	cauto qs=readV<pii>(q);
	// vector<pii> qs(q);
	out(vs,1);
	SegTree<Seg> st(n);
	vector<int> large(n);
	rep(i,n){
		auto x=vs[i];
		auto &ar=st(i).mx;
		rep(i,P)for(;x%primes[i]==0;x/=primes[i]) ++ar[i];
		large[i]=x;
	}
	st.upd();

	
	vector<int> ls(n,-1),rs(n,n);
	{
		vector<int> prv(212345,-1);
		rep(i,n){
			cauto x=large[i];
			if(prv[x]>=0){
				ls[i]=prv[x];
				rs[prv[x]]=i;
			}
			prv[x]=i;
		}
	}
	out(ls,rs,1);

	vector<mint> prod(n+1,1),iprod(n+1,1);
	rep(i,n){
		cauto p=large[i];
		prod[i+1]=prod[i]*p;
		iprod[i+1]=iprod[i]*inv[p];
	}
	const int SQ=456;
	const int BK=n/SQ+1;
	vv<pii> rvs(BK);
	vv<mint> prods(BK);
	vv<mint> iprods(BK);
	rep(i,n) rvs[i/SQ].eb(rs[i],large[i]);
	rep(i,BK){
		auto &rv=rvs[i];
		sort(all(rv));
		auto &prod=prods[i];
		auto &iprod=iprods[i];
		prod.resize(rv.size()+1,1);
		iprod.resize(rv.size()+1,1);
		rep(i,rv.size()){
			cauto p=rv[i].Y;
			prod[i+1]=prod[i]*p;
			iprod[i+1]=iprod[i]*inv[p];
		}
	}
	
	int last=0;
	for(cauto &[x,y]:qs){
		int l=(last+x)%n;
		int r=(last+y)%n;
		if(l>r) swap(l,r);
		++r;
		out(l,r,1);
		cauto ar=st(l,r).mx;
		// out(ar,1);
		mint re=prod[r]*iprod[l];
		out(re,1);
		for(int i=l;i<r;){
			if(i%SQ==0 && i+SQ<r){
				cauto bk=i/SQ;
				cauto li=lower_bound(all(rvs[bk]),pii(l,0))-rvs[bk].begin();
				cauto ri=lower_bound(all(rvs[bk]),pii(r,0))-rvs[bk].begin();
				out(bk,rvs[bk],li,ri,prods[bk][ri]*iprods[bk][li],1);
				re*=iprods[bk][ri]*prods[bk][li];
				i+=SQ;
			}else{
				if(rs[i]<r) re*=inv[large[i]];
				++i;
			}
		}
		rep(i,P) re*=modpow(primes[i],ar[i]);
		cout<<re NL;
		last=re.v;
	}		
  return 0;
}