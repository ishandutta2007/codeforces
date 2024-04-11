////////////////////////////////////////////////////////////////////////////////
//                          Give me AC!!!                                     //
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <random>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>; 
#define coutY cout<<"YES"<<endl
#define couty cout<<"Yes"<<endl
#define coutN cout<<"NO"<<endl
#define coutn cout<<"No"<<endl
#define coutdouble(a,b) cout << fixed << setprecision(a) << double(b) << endl;
#define vi(a,b) vector<int> a(b)
#define vl(a,b) vector<ll> a(b)
#define vs(a,b) vector<string> a(b)
#define vll(a,b,c)  vector<vector<ll>> a(b, vector<ll>(c));
#define intque(a) queue<int> a;
#define llque(a) queue<ll> a;
#define intque2(a) priority_queue<int, vector<int>, greater<int>> a;
#define llque2(a) priority_queue<ll, vector<ll>, greater<ll>> a;
#define pushback(a,b) a.push_back(b)
#define mapii(M1) map<int, int> M1;
#define cou(v,x) count(v.begin(), v.end(), x)
#define mapll(M1) map<ll,ll> M1;
#define mapls(M1) map<ll, string> M1;
#define mapsl(M1) map<string, ll> M1;
#define twolook(a,l,r,x) lower_bound(a+l, a+r, x) - a
#define sor(a) sort(a.begin(), a.end())
#define rever(a) reverse(a.begin(),a.end())
#define rep(i,a) for(ll i=0;i<a;i++)
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define vcout(n) for(ll i=0;i<ll(n.size());i++) cout<<n[i]
#define vcin2(n) rep(i,ll(n.size())) rep(j,ll(n.at(0).size())) cin>>n[i][j]
const ll mod = 1000000007;
const ll MOD = 1000000007;
const ll MAX = 200000;
//const ll _max = 9223372036854775807;
const ll _max = 1223372036854775807;
  
ll fac[MAX],finv[MAX],inv[MAX];
 
// 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
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
 
int modPow(long long a, long long n, long long p) {
  if (n == 0) return 1; // 0
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}
 
ll clocks(ll a,ll b,ll c){
  return a*3600+b*60+c;
}
ll divup(ll b,ll d){
   if(b%d==0){
    return b/d;
  }
  else{
    return b/d+1;
  }
}
struct UnionFind {
    vector<int> par; // par[i]:i() par[3] = 2 : 32
 
    UnionFind(int N) : par(N) { //
        for(int i = 0; i < N; i++) par[i] = i;
    }
 
    int root(int x) { // xroot(x) = {x}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
 
    void unite(int x, int y) { // xy
        int rx = root(x); //xrx
        int ry = root(y); //yry
        if (rx == ry) return; //xy(=)
        par[rx] = ry; //xy(=)xrxyry
    }
 
    bool same(int x, int y) { // 2x, ytrue
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
 
struct Edge {
    int to;     // 
    int weight; // 
    Edge(int t, int w) : to(t), weight(w) { }
};
 
using Graphw = vector<vector<Edge>>;
ll zero(ll a){
  return max(ll(0),a);
}
 
template< typename T >
struct FormalPowerSeries : vector< T > {
  using vector< T >::vector;
  using P = FormalPowerSeries;
 
  using MULT = function< P(P, P) >;
 
  static MULT &get_mult() {
    static MULT mult = nullptr;
    return mult;
  }
 
  static void set_fft(MULT f) {
    get_mult() = f;
  }
 
  void shrink() {
    while(this->size() && this->back() == T(0)) this->pop_back();
  }
 
  P operator+(const P &r) const { return P(*this) += r; }
 
  P operator+(const T &v) const { return P(*this) += v; }
 
  P operator-(const P &r) const { return P(*this) -= r; }
 
  P operator-(const T &v) const { return P(*this) -= v; }
 
  P operator*(const P &r) const { return P(*this) *= r; }
 
  P operator*(const T &v) const { return P(*this) *= v; }
 
  P operator/(const P &r) const { return P(*this) /= r; }
 
  P operator%(const P &r) const { return P(*this) %= r; }
 
  P &operator+=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
    return *this;
  }
 
  P &operator+=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }
 
  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
    shrink();
    return *this;
  }
 
  P &operator-=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] -= r;
    shrink();
    return *this;
  }
 
  P &operator*=(const T &v) {
    const int n = (int) this->size();
    for(int k = 0; k < n; k++) (*this)[k] *= v;
    return *this;
  }
 
  P &operator*=(const P &r) {
    if(this->empty() || r.empty()) {
      this->clear();
      return *this;
    }
    assert(get_mult() != nullptr);
    return *this = get_mult()(*this, r);
  }
 
  P &operator%=(const P &r) {
    return *this -= *this / r * r;
  }
 
  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }
 
  P &operator/=(const P &r) {
    if(this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
  }
 
  P pre(int sz) const {
    return P(begin(*this), begin(*this) + min((int) this->size(), sz));
  }
 
  P operator>>(int sz) const {
    if(this->size() <= sz) return {};
    P ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }
 
  P operator<<(int sz) const {
    P ret(*this);
    ret.insert(ret.begin(), sz, T(0));
    return ret;
  }
 
  P rev(int deg = -1) const {
    P ret(*this);
    if(deg != -1) ret.resize(deg, T(0));
    reverse(begin(ret), end(ret));
    return ret;
  }
 
  P diff() const {
    const int n = (int) this->size();
    P ret(max(0, n - 1));
    for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
    return ret;
  }
 
  P integral() const {
    const int n = (int) this->size();
    P ret(n + 1);
    ret[0] = T(0);
    for(int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
    return ret;
  }
 
  // F(0) must not be 0
  P inv(int deg = -1) const {
    assert(((*this)[0]) != T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1) / (*this)[0]});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
    }
    return ret.pre(deg);
  }
 
  // F(0) must be 1
  P log(int deg = -1) const {
    assert((*this)[0] == 1);
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }
 
  P sqrt(int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
 
    if((*this)[0] == T(0)) {
      for(int i = 1; i < n; i++) {
        if((*this)[i] != T(0)) {
          if(i & 1) return {};
          if(deg - i / 2 <= 0) break;
          auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);
          if(ret.size() < deg) ret.resize(deg, T(0));
          return ret;
        }
      }
      return P(deg, 0);
    }
 
    P ret({T(1)});
    T inv2 = T(1) / T(2);
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
    }
    return ret.pre(deg);
  }
 
  // F(0) must be 0
  P exp(int deg = -1) const {
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1)});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
    }
    return ret.pre(deg);
  }
 
  P pow(int64_t k, int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    for(int i = 0; i < n; i++) {
      if((*this)[i] != T(0)) {
        T rev = T(1) / (*this)[i];
        P C(*this * rev);
        P D(n - i);
        for(int j = i; j < n; j++) D[j - i] = C[j];
        D = (D.log() * k).exp() * (*this)[i].pow(k);
        P E(deg);
        if(i * k > deg) return E;
        auto S = i * k;
        for(int j = 0; j + S < deg && j < D.size(); j++) E[j + S] = D[j];
        return E;
      }
    }
    return *this;
  }
 
 
  T eval(T x) const {
    T r = 0, w = 1;
    for(auto &v : *this) {
      r += w * v;
      w *= x;
    }
    return r;
  }
};
 
//ab,(a,10)a
ll expless(ll a,ll b){
  ll k=0;
  ll o=1;
  while(a>=o){
    k++;
    o=o*b;
  }
  return k;
}
//ab
ll base(ll a,ll b){
  ll c=expless(a,b);
  ll ans=0;
  ll k;
  for(int i=0;i<c;i++){
    k=a%b;
    ans+=k*modPow(10,i,_max);
    a=a/b;
  }
  return ans;
}
//ba10
ll tenbase(ll a,ll b){
  ll c=expless(a,10);
  ll ans=0;
  ll k=1;
  for(int i=0;i<c;i++){
    ans+=(a%10)*k;
    k=k*b;
    a=a/10;
  }
  return ans;
}
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 
 
        // 
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
 
        //  push
        res.push_back({a, ex});
    }
 
    // 
    if (N != 1) res.push_back({N, 1});
    return res;
}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll atll(ll a,ll b){
  b++;
  ll c=expless(a,10);
  ll d=c-b;
  ll f=1;
  for(int i=0;i<d;i++){
    f=f*10;
  }
  a=(a/f);
  return a%10;
}
//ab
ll exp(ll a,ll b){
  ll ans=0;
  while(a%b==0){
    a=a/b;
    ans++;
  }
  return ans;
}
int main() {
 COMinit();
ll a;
  cin>>a;
  ll m;
  ll r,g,b,w;
  for(int i=0;i<a;i++){
    cin>>r>>g>>b>>w;
    m=min(r,min(g,b));
    if(m==0){
      if(r%2+b%2+g%2+w%2<=1){
        couty;
      }
      else{
        coutn;
      }
    }
    else{
      if(r%2+b%2+g%2+w%2!=2){
        couty;
      }
      else{
        coutn;
      }
    }
  }
}