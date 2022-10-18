#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
namespace modular {
	template <typename>
	struct is_modular : std::false_type { };

	template<int M>
	struct static_mint {
		static_assert(0 < M, "Module must be positive");

		using mint = static_mint;
		constexpr static int get_mod() { return M; }

		int val;
		static_mint(): val() {}
		static_mint(long long x) : val(x % M) { if (val < 0) val += M; }
		mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		mint inv() const { return pow(M - 2); }

		friend mint pow(const mint &m, long long n) { return m.pow(n); }
		friend mint inv(const mint &m) { return m.inv(); }

		mint operator+() const { mint m; m.val = val; return m; }
		mint operator-() const { mint m; m.val = M - val; return m; }
		mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		mint &operator++() { return *this += 1; }
		mint &operator--() { return *this -= 1; }
		mint operator++(int) { mint result(*this); *this += 1; return result; }
		mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const mint &m) {
			return os << m.val;
		}

		friend std::istream &operator>>(std::istream &is, mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	template <int M>
	struct is_modular<static_mint<M>> : std::true_type { };

	struct dynamic_mint {
		static int M;
		static void set_mod(int m) { assert(0 < m); M = m; }
		static int get_mod() { return M; }

		using mint = dynamic_mint;

		int val;
		dynamic_mint(): val() {}
		dynamic_mint(long long x) : val(x % M) { if (val < 0) { val += M; } }
		mint pow(long long n) const { mint ans = 1, x(*this); while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
		mint inv() const { return pow(M - 2); }

		friend mint pow(const mint &m, long long n) { return m.pow(n); }
		friend mint inv(const mint &m) { return m.inv(); }

		mint operator+() const { mint m; m.val = val; return m; }
		mint operator-() const { mint m; m.val = M - val; return m; }
		mint &operator+=(const mint &m) { if ((val += m.val) >= M) val -= M; return *this; }
		mint &operator-=(const mint &m) { if ((val -= m.val) < 0) val += M; return *this; }
		mint &operator*=(const mint &m) { val = (long long) val * m.val % M; return *this; }
		mint &operator/=(const mint &m) { val = (long long) val * m.inv().val % M; return *this; }

		friend mint operator+ (const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
		friend mint operator- (const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
		friend mint operator* (const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
		friend mint operator/ (const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }
		friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
		friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }

		mint &operator++() { return *this += 1; }
		mint &operator--() { return *this -= 1; }
		mint operator++(int) { mint result(*this); *this += 1; return result; }
		mint operator--(int) { mint result(*this); *this -= 1; return result; }

		template <typename T> explicit operator T() const { return T(val); }

		friend std::ostream &operator<<(std::ostream &os, const mint &m) {
			return os << m.val;
		}

		friend std::istream &operator>>(std::istream &is, mint &m) {
			long long x; is >> x; m = x;
			return is;
		}
	};

	int dynamic_mint::M;

	template <>
	struct is_modular<dynamic_mint> : std::true_type { };
}

namespace ntt {
	template <int M> using mint = modular::static_mint<M>; //default mint

	template <int P>
	struct prime_info {
		constexpr static int root = 0, root_pw = 0;
	};

	template <> struct prime_info<7340033>   { constexpr static int root = 5, root_pw = 1 << 20; };
	template <> struct prime_info<998244353> { constexpr static int root = 15311432, root_pw = 1 << 23; };
	template <> struct prime_info<754974721> { constexpr static int root = 739831874, root_pw = 1 << 24; };
	template <> struct prime_info<167772161> { constexpr static int root = 243, root_pw = 1 << 25; };
	template <> struct prime_info<469762049> { constexpr static int root = 2187, root_pw = 1 << 26; };

	std::vector<int> rev = {0};

	void compute_bit_reverse(int lg) {
		static int computed = 0;
		if (lg <= computed) return;
		rev.resize(1 << lg);
		for (int i = (1 << computed); i < (1 << lg); i++) {
			rev[i] = (rev[i >> 1] >> 1) ^ ((i & 1) << 30);
		}
		computed = lg;
	}

	template <int M>
	std::vector<mint<M>> root = {0, 1};

	template <int M>
	void compute_roots(int lg) {
		static int computed = 1;
		if (lg <= computed) return;
		root<M>.resize(1 << lg);
		for (int k = computed; k < lg; k++) {
			mint<M> z(prime_info<M>::root);
			for (int i = (1 << (k + 1)); i < prime_info<M>::root_pw; i <<= 1) {
				z *= z;
			}
			for (int i = (1 << (k - 1)); i < (1 << k); i++) {
				root<M>[i << 1] = root<M>[i];
				root<M>[i << 1 | 1] = root<M>[i] * z;
			}
		}
	}

	template<int M>
	void ntt(std::vector<mint<M>> &a) {
		int n = int(a.size()), lg = 32 - __builtin_clz(n) - 1;
		compute_bit_reverse(lg);
		compute_roots<M>(lg);
		int shift = 31 - lg;
		for (int i = 0; i < n; i++) {
			if (i < (rev[i] >> shift)) {
				std::swap(a[i], a[rev[i] >> shift]);
			}
		}
		for (int k = 1; k < n; k <<= 1) {
			mint<M> wl = prime_info<M>::root;
			for (int i = 2 * k; i < prime_info<M>::root_pw; i <<= 1) {
				wl *= wl;
			}
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					mint<M> z = root<M>[j + k] * a[i + j + k];
					a[i + j + k] = a[i + j] - z;
					a[i + j] = a[i + j] + z;
				}
			}
		}
	}

	template <int M>
	std::enable_if_t<prime_info<M>::root != 0, std::vector<mint<M>>>
	convolution(std::vector<mint<M>> a, std::vector<mint<M>> b) {
		int n = 1;
		while (n < a.size() + b.size()) {
			n <<= 1;
		}
		a.resize(n);
		b.resize(n);
		ntt(a), ntt(b);
		mint<M> n_inv = mint<M>(n).inv();
		for (int i = 0; i < n; i++) {
			a[i] *= b[i] * n_inv;
		}
		reverse(a.begin() + 1, a.end());
		ntt(a);
		return a;
	}

	template <int M>
	mint<M> garner(int a1, int a2, int a3) {
		constexpr static int M1 = 754974721, M2 = 167772161, M3 = 469762049;
		const static int R12 = mint<M2>(M1).inv().val;
		const static int R13 = mint<M3>(M1).inv().val;
		const static int R23 = mint<M3>(M2).inv().val;
		int x1 = a1;
		int x2 = (long long)(a2 - x1) * R12 % M2; if (x2 < 0) x2 += M2;
		int x3 = ((long long)(a3 - x1) * R13 % M3 - x2) * R23 % M3; if (x3 < 0) x3 += M3;
		return mint<M>(x1) + mint<M>(x2) * M1 + mint<M>(x3) * M1 * M2;
	}

	template <int M>
	std::enable_if_t<prime_info<M>::root == 0, std::vector<mint<M>>>
	convolution(std::vector<mint<M>> a, const std::vector<mint<M>> &b) {
		constexpr static int M1 = 754974721, M2 = 167772161, M3 = 469762049;
		auto c1 = convolution(vector<mint<M1>>(a.begin(), a.end()), vector<mint<M1>>(b.begin(), b.end()));
		auto c2 = convolution(vector<mint<M2>>(a.begin(), a.end()), vector<mint<M2>>(b.begin(), b.end()));
		auto c3 = convolution(vector<mint<M3>>(a.begin(), a.end()), vector<mint<M3>>(b.begin(), b.end()));
		int n = int(c1.size());
		a.resize(n);
		for (int i = 0; i < n; i++) {
			a[i] = garner<M>(c1[i].val, c2[i].val, c3[i].val);
		}
		return a;
	}

	template <int M, typename T>
	std::enable_if_t<!modular::is_modular<T>::value, std::vector<T>>
	convolution(const std::vector<T> &a, const std::vector<T> &b) {
		auto f = convolution(std::vector<mint<M>>(a.begin(), a.end()), std::vector<mint<M>>(b.begin(), b.end()));
		return vector<T>(f.begin(), f.end());
	}

	template <typename T>
	void normalize(const std::vector<T> &a) {
		for (int i = int(a.size()) - 1; i >= 0; i--) {
			if (a[i]) {
				a.resize(i + 1);
				return;
			}
		}
		a.clear();
	}
}
template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;
template<class T>
vector<T> NTT(vector<T> a,vector<T> b){
  ll nmod=T::mod();
  int n=a.size();
  int m=b.size();
  vector<int> x1(n);
  vector<int> y1(m);
  for(int i=0;i<n;i++){
    ll tmp1,tmp2,tmp3;
    tmp1=a[i].val();
    x1[i]=tmp1;
  }
  for(int i=0;i<m;i++){
    ll tmp1,tmp2,tmp3;
    tmp1=b[i].val();
    y1[i]=tmp1;
  }
  auto z1=ntt::convolution<167772161>(x1,y1);
  auto z2=ntt::convolution<469762049>(x1,y1);
  auto z3=ntt::convolution<1224736769>(x1,y1);
  vector<T> res(n+m-1);
  ll m1=167772161;
  ll m2=469762049;
  ll m3=1224736769;
  ll m1m2=104391568;
  ll m1m2m3=721017874;
  ll mm12=m1*m2%nmod;
  for(int i=0;i<n+m-1;i++){
    int v1=(z2[i]-z1[i])*m1m2%m2;
    if(v1<0) v1+=m2;
    int v2=(z3[i]-(z1[i]+v1*m1)%m3)*m1m2m3%m3;
    if(v2<0) v2+=m3;
    res[i]=(z1[i]+v1*m1+v2*mm12);
  }
  return res;
}
template<class T>
struct FormalPowerSeries:vector<T>{
  using vector<T>::vector;
  using vector<T>::operator=;
  using F=FormalPowerSeries;
  F operator-() const{
    F res(*this);
    for(auto &e:res) e=-e;
    return res;
  }
  F &operator*=(const T &g){
    for(auto &e:*this) e*=g;
    return *this;
  }
  F &operator/=(const T &g){
    assert(g!=T(0));
    *this*=g.inv();
    return *this;
  }
  F &operator+=(const F &g){
    int n=(*this).size(),m=g.size();
    for(int i=0;i<min(n,m);i++){
      (*this)[i]+=g[i];
    }
    return *this;
  }
  F &operator-=(const F &g){
    int n=(*this).size(),m=g.size();
    for(int i=0;i<min(n,m);i++){
      (*this)[i]-=g[i];
    }
    return *this;
  }
  F &operator<<=(const int d) {
    int n=(*this).size();
    (*this).insert((*this).begin(),d,0);
    (*this).resize(n);
    return *this;
  }
  F &operator>>=(const int d) {
    int n=(*this).size();
    (*this).erase((*this).begin(),(*this).begin()+min(n, d));
    (*this).resize(n);
    return *this;
  }
  F inv(int d=-1) const{
    int n=(*this).size();
    assert(n!=0&&(*this)[0]!=0);
    if(d==-1) d=n;
    assert(d>0);
    F res{(*this)[0].inv()};
    while(res.size()<d){
      int m=size(res);
      F f(begin(*this),begin(*this)+min(n,2*m));
      F r(res);
      f.resize(2*m);
      r.resize(2*m);
      vector<T> s=NTT(f,r);
      s.resize(2*m);
      for(int i=0;i<2*m;i++){
        s[i]=-s[i];
      }
      s[0]+=2;
      vector<T> g=NTT(s,r);
      g.resize(2*m);
      res=g;
    }
    res.resize(n);
    return res;
  }
  F &operator/=(const F &g){
    int n=(*this).size();
    *this=NTT(*this,g.inv());
    (*this).resize(n);
    return (*this);
  }
  F &operator*=(const F &g){
    int n=(*this).size();
    *this=NTT(*this,g);
    (*this).resize(n);
    return (*this);
  }
  void onemultiply(const int d,const T c){
    int n=(*this).size();
    for(int i=n-d-1;i>=0;i--){
      (*this)[i+d]+=(*this)[i]*c;
    }
  }
  void onediv(const int d,const T c){
    int n=(*this).size();
    for(int i=n-d-1;i>=0;i--){
      (*this)[i+d]-=(*this)[i]*c;
    }
  }
  T eval(const T &a) const {
    T x(1),res(0);
    for(auto e:*this) res+=e*x,x*=a;
    return res;
  }
  F differential() const {
    int n=(*this).size();
    F res(n);
    for(int i=0;i<n-1;i++){
      res[i]=T(i+1)*(*this)[i+1];
    }
    res[n-1]=0;
    return res;
  }
  F Integral() const {
    int n=(*this).size();
    F res(n);
    for(int i=1;i<n;i++){
      res[i]=(*this)[i-1]/T(i);
    }
    res[0]=0;
    return res;
  }
  F log() const{
    int n=(*this).size();
    F u=(*this).differential();
    F d=(*this);
    u/=d;
    u=u.Integral();
    u.resize(n);
    return u;
  }
  F exp(int d=-1) const{
    int n=(*this).size();
    assert(n!=0&&(*this)[0]==0);
    if(d==-1) d=n;
    assert(d>0);
    F res{1};
    while(res.size()<d){
      int m=size(res);
      F f(begin(*this),begin(*this)+min(n,2*m));
      F r(res);
      f.resize(2*m);
      r.resize(2*m);
      r=r.log();
      f-=r;
      f[0]++;
      F g=f*res;
      g.resize(2*m);
      res=g;
    }
    res.resize(n);
    return res;
  }
  F pow(int a){
    int n=(*this).size();
    F res(n);
    for(int i=0;i<n;i++){
      res[i]=(*this)[i];
    }
    if(a==0){
      F s(n);
      if(n>0){
        s[0]=T(1);
      }
      for(int i=0;i<n;i++){
      res[i]=s[i];
      }
      return res;
    }
    int l=0;
    while(l<n&&res[l]==0) l++;
    if(l>(n-1)/a||l==n){
      F s(n);
      for(int i=0;i<n;i++){
        res[i]=s[i];
      }
      return res;
    }
    T t=res[l];
    res.erase(res.begin(),res.begin()+l);
    res/=t;
    F g=res.log();
    for(int i=0;i<n;i++){
      res[i]=g[i];
    }
    res*=a;
    g=res.exp();
    for(int i=0;i<n;i++){
      res[i]=g[i];
    }
    res*=t.pow(a);
    res.insert(res.begin(),l*a,0);
    return res;
  }
  F operator*(const T &g) const { return F(*this)*=g;}
  F operator-(const T &g) const { return F(*this)-=g;}
  F operator*(const F &g) const { return F(*this)*=g;}
  F operator-(const F &g) const { return F(*this)-=g;}
  F operator+(const F &g) const { return F(*this)+=g;}
  F operator/(const F &g) const { return F(*this)/=g;}
  F operator<<(const int d) const { return F(*this)<<=d;}
  F operator>>(const int d) const { return F(*this)>>=d;}  
};
using fps = FormalPowerSeries<modint>;
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll a,b,q;
  cin>>a>>b>>q;
  fps f(a);
  fps tmp(a);
  vector<fps> t;
  for(int i=0;i<a;i++){
    f[i]=1;
  }
  t.push_back(f);
  for(int i=0;i<b;i++){
    fps g=f;
    g>>=1;
    fps h=f;
    h<<=1;
    f=g+h;
    t.push_back(f);
  }
  for(int i=0;i<=b;i++){
    fps x=t[i];
    fps y=t[b-i];
    for(int j=0;j<a;j++){
      tmp[j]+=x[j]*y[j];
    }
  }
  vector<modint> k(a);
  vcin(k);
  modint ans=0;
  for(int i=0;i<a;i++){
    ans+=k[i]*tmp[i];
  } 
  for(int i=0;i<q;i++){
    ll x;
    modint y;
    cin>>x>>y;
    x=x-1;
    ans+=tmp[x]*(y-k[x]);
    cout<<ans<<endl;
    k[x]=y;
  } 
}