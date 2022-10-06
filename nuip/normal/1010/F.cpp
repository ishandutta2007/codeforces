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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"

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
const ll MOD=998244353;

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
template <int mod=MOD> struct modInt{
  int v;
  modInt(int v=0):v(v){}
  modInt(ll v):v(v%MOD){}
  modInt operator+(const modInt &n)const{return v+n.v<mod ? v+n.v : v+n.v-mod;}
  modInt operator-(const modInt &n)const{return v-n.v<0 ? v-n.v+mod : v-n.v;}
  modInt operator*(const modInt &n)const{return ll(v)*n.v%mod;}
  modInt operator/(const modInt &n)const{return ll(v)*modpow(n.v%mod,-1,mod)%mod;}
  modInt operator+(const ll &n)const{return v+n<mod ? v+n : v+n-mod;}
  modInt operator-(const ll &n)const{return v-n<0 ? v-n+mod : v-n;}
  modInt operator*(const ll &n)const{return ll(v)*(n%mod)%mod;}
  modInt operator/(const ll &n)const{return ll(v)*modpow(n%mod,-1,mod)%mod;}
  modInt& operator+=(const modInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const modInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const modInt &n){v=ll(v)*n.v%mod; return *this;}
  modInt& operator/=(const modInt &n){v=ll(v)*modpow(n.v,-1,mod)%mod; return *this;}
  modInt& operator+=(const ll &n){v+=n; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const ll &n){v-=n; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  modInt& operator/=(const ll &n){v=ll(v)*modpow(n,-1,mod)%mod; return *this;}
};
#ifdef NUIP
class MINT_FRAC____{
public:
	unordered_map<int,pii> dict;
	MINT_FRAC____(int n){
		rep(p,n+1)reps(q,1,n+1)if(__gcd(p,q)==1){
			dict[1ll*p*modpow(q,-1)%MOD]=pii(p,q);
			dict[MOD-1ll*p*modpow(q,-1)%MOD]=pii(-p,q);
		}
	}
} Il1Il1Il1(1000);
template<int mod> ostream& operator<<(ostream &os,const modInt<mod> &n){if(Il1Il1Il1.dict.count(n.v)) os<<n.v<<"("<<Il1Il1Il1.dict[n.v].X<<"/"<<Il1Il1Il1.dict[n.v].Y<<")";else os<<n.v;return os;};
#else
template<int mod> ostream& operator<<(ostream &os,const modInt<mod> &n){return os<<n.v;};
#endif
template<int mod> modInt<mod> operator+(const ll &n,const modInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> modInt<mod> operator-(const ll &n,const modInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> modInt<mod> operator*(const ll &n,const modInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> modInt<mod> operator/(const ll &n,const modInt<mod> &m){return modInt<mod>(n%mod)/m;}
typedef modInt<MOD> mint;
template <int mod> modInt<mod> modpow(modInt<mod> r,ll n){ modInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;
mint comb(ll n,ll r){ if(n<r||r<0)return 0; return fact[n]*finv[n-r]*finv[r];}
class Doralion{
  void Modinvs(vector<mint> &re,int n){ re.resize(n+1); re[1]=1; for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);}
  void Facts(vector<mint> &re,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*(i+1);}
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*inv[i+1];}
public:
  Doralion(int n){ Modinvs(inv,n); Facts(fact,n); Factinvs(finv,inv,n);}
} doralion(1123456);

template<int B, int ROOT=5> // n <= 1<<B
struct FMT{
  mint R[2*(B+1)];
  vector<int> m2[(B+1)];
  vector<mint> power[2*(B+1)];
  FMT(){
    rep(e, (B+1)){
      m2[e].resize(1<<e);
      rep(m, 1<<e)rep(i,e) if(m&(1<<i)) m2[e][m] |= (1<<(e-1-i));
      
      mint w1 = modpow(ROOT,(MOD-1)/(2<<e));
      mint w2 = modpow(w1,-1);
      power[  e].resize(1<<e);
      power[(B+1)+e].resize(1<<e);
      power[e][0] = power[(B+1)+e][0] = 1;
      reps(j,1,(1<<e)){
				power[  e][j] = power[  e][j-1]*w1;
				power[(B+1)+e][j] = power[(B+1)+e][j-1]*w2;
      }
    }
  }
  
  void transform(mint *f, int N, bool inv){
    int e;
    for(e=0;;e++) if(N == (1<<e)) break;
    rep(m,N)if(m < m2[e][m]) swap(f[m], f[m2[e][m]]);
    for(int t=0,t2=1;t2<N;t++,t2+=t2){
      mint *po = power[inv*(B+1) + t].data();
      for(int i=0;i<N;i+=t2+t2){
				for (int j = 0; j < (1<<t); j++) {
					mint x = f[i+j];
					mint y = f[i+t2+j]*po[j];
					f[i+j] = x + y;
					f[i+t2+j] = x - y;
				}
      }
    }
    if(inv){
      mint ni=modpow(N,-1);
      for(int i = 0; i < N; i++) f[i] = f[i] * ni;
    }
  }
  template <typename T>
  vector<mint> convolution(const vector<T> &f, const vector<T> &g){
    const int n = f.size(), m = g.size();
    int n2 = 1;
    while(n2 < f.size()+g.size()) n2 *= 2;
    vector<mint> cf(n2), cg(n2);
    rep(i, n) cf[i] = f[i];
    rep(i, m) cg[i] = g[i];
    transform(cf.data(), n2, false);
    transform(cg.data(), n2, false);
    rep(i, n2) cf[i] *= cg[i];
    transform(cf.data(), n2, true);
		while(cf.size() && cf.back().v==0) cf.pop_back();
    return cf;
  }
};
FMT<17> fmt;

int n;
vv<int> g;
vector<vv<mint>> dp;
vector<int> sz;

using pff=pair<vector<mint>,vector<mint>>;
pff eval(vv<mint> &fs){ // (f-1, prod)
	int n=fs.size();
	out(fs,1);
	if(n==0) return pff({},{});
	if(n==1){
		return pff(fs[0],fs[0]);
	}
	int deg=0;
	for(auto &f:fs) deg+=max(0,(int)f.size()-1);
	vv<mint> ls,rs;
	{
		int sum=0;
		for(auto &f:fs){
			sum+=max(0,(int)f.size()-1);
			(sum*2>deg&&ls.size()?rs:ls).pb(f);
		}
	}
	//fs.clear(); fs.shrink_to_fit();
	pff l=eval(ls);
	pff r=eval(rs);
	pff re(fmt.convolution(l.X,r.Y),
				 fmt.convolution(l.Y,r.Y));
	if(r.X.size()>re.X.size()) re.X.resize(r.X.size());
	rep(i,r.X.size()) re.X[i]+=r.X[i];
	return re;
}

void dfs(int v,int p){
	{
		auto it=find(all(g[v]),p);
		if(it!=g[v].end()) g[v].erase(it);
	}
	sz[v]=1;
	for(auto w:g[v]){
		dfs(w,v);
		sz[v]+=sz[w];
	}
	if(g[v].size()==0){
		dp[v].pb({0,1});
	}else if(g[v].size()==1){
		swap(dp[v],dp[g[v][0]]);
		dp[v].pb({0,1});
	}else{
		int w=g[v][0];
		int w_=g[v][1];
		if(sz[w]>sz[w_]) swap(w,w_);
		swap(dp[v],dp[w_]);
		auto f=eval(dp[w]).X;
		if(f.empty()) f.eb();
		f[0]+=1;
		out(v,f,1);
		f.insert(f.begin(),0);
		out(v,f,1);
		dp[v].eb(f);
	}
	// out(v,p,dp[v],eval(dp[v]),1);
}

mint solve(vv<int> g,ll x){
	n=g.size();
	::g=g;
	dp.resize(n); sz.resize(n);
	dfs(0,-1);
	auto re=eval(dp[0]).X;
	if(re.empty()) re.eb();
	re[0]+=1;
	out(re,1);
	vector<mint> binom(n+1);
	x%=MOD;
	binom[1]=1;
	reps(i,2,n+1){
		++x;
		if(x==MOD) x=0;
		binom[i]=binom[i-1]*x;
	}
	reps(i,2,n+1) binom[i]*=finv[i-1];
	mint ans=0;
	reps(i,1,n+1) ans+=binom[i]*re[i];
	out(binom,1);
	return ans;
	// rep(v,n)for(int w:g[v]) cout<<v<<" "<<w NL;
}

//#define USO
int main(){
	// debug(); return 0;
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	ll x;
#ifdef USO
	n=1000-00;
	x=10;
#else
	cin>>n>>x;
#endif
	g.resize(n); dp.resize(n); sz.resize(n);
	rep(i,n-1){
		int a,b;
#ifdef USO
		b=i+1;
		a=(i%2?i-1:i);
#else
		cin>>a>>b; --a; --b;
#endif
		g[a].pb(b);
		g[b].pb(a);
	}
	cout<<solve(g,x)<<endl;
  return 0;
}
// https://codeforces.com/blog/entry/60851