#include <bits/stdc++.h>
#define whlie while
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define rep(i,N) for(int i = 0; i < (N); i++)
#define repr(i,N) for(int i = (N) - 1; i >= 0; i--)
#define rep1(i,N) for(int i = 1; i <= (N) ; i++)
#define repr1(i,N) for(int i = (N) ; i > 0 ; i--)
#define each(x,v) for(auto& x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define vrep(v,it) for(auto it = v.begin(); it != v.end(); it++)
#define vrepr(v,it) for(auto it = v.rbegin(); it != v.rend(); it++)
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
using namespace std; void solve();
using ll = long long; using vl = vector<ll>;
using vi = vector<int>; using vvi = vector< vector<int> >;
constexpr int inf = 1001001001;
constexpr ll infLL = (1LL << 61) - 1;
struct IoSetupNya {IoSetupNya() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); cerr << fixed << setprecision(7);} } iosetupnya;
template<typename T, typename U> inline bool amin(T &x, U y) { return (y < x) ? (x = y, true) : false; }
template<typename T, typename U> inline bool amax(T &x, U y) { return (x < y) ? (x = y, true) : false; }
template<typename T, typename U> ostream& operator <<(ostream& os, const pair<T, U> &p) { os << p.first << " " << p.second; return os; }
template<typename T, typename U> istream& operator >>(istream& is, pair<T, U> &p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator <<(ostream& os, const vector<T> &v) { int s = (int)v.size(); rep(i,s) os << (i ? " " : "") << v[i]; return os; }
template<typename T> istream& operator >>(istream& is, vector<T> &v) { for(auto &x : v) is >> x; return is; }
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
template<typename T>void die(T x){out(x); exit(0);}
#ifdef NyaanDebug
  #include "NyaanDebug.h"
  #define trc(...) do { cerr << #__VA_ARGS__ << " = "; dbg_out(__VA_ARGS__);} while(0)
  #define trca(v,N) do { cerr << #v << " = "; array_out(v , N);cout << endl;} while(0)
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif
using P = pair<int,int>; using vp = vector<P>;
constexpr int MOD = /** 1000000007; //*/ 998244353;
////////////////


//  O( sqrt(N) log log N )
// 0N->1->0
vector<int> Primes(int N){
  vector<int> A(N + 1 , 1);
  A[0] = A[1] = 0;
  for(int i = 2; i * i <= N ; i++) 
    if(A[i]==1) for(int j = i << 1 ; j <= N; j += i) A[j] = 0;
  return A;
}

//  O( sqrt(N) log log N )
// 0N->1->
vector<int> Factors(int N){
  vector<int> A(N + 1 , 1);
  A[0] = A[1] = 0;
  for(int i = 2; i * i <= N ; i++) 
    if(A[i]==1) for(int j = i << 1 ; j <= N; j += i) A[j] = i;
  return A;
}

//  (N)=(NN)
vector<int> EulersTotientFunction(int N){
  vector<int> ret(N + 1 , 0);
  for(int i = 0; i <= N ; i++) ret[i] = i; 
  for(int i = 2 ; i <= N ; i++){
    if(ret[i] == i)
      for(int j = i; j <= N; j += i) ret[j] = ret[j] / i * (i - 1);
  }
  return ret;
}

//  O(sqrt(N))
// N
vector<long long> Divisor(long long N){
  vector<long long> v;
  for(long long i = 1; i * i <= N ; i++){
    if(N % i == 0){
      v.push_back(i);
      if(i * i != N) v.push_back(N / i);
    }
  }
  return v;
}

// 
// keyvaluemap
// ex) N=12 -> m={ (2,2) , (3,1) }
map<long long,int> PrimeFactors(long long N){
  map<long long,int> m;
  for(long long i=2; i * i <= N; i++)
    while(N % i == 0) m[i]++ , N /= i;
  if(N != 1) m[N]++;
  return m;
}

//  modr
bool PrimitiveRoot(long long r , long long mod){
  r %= mod; if(r == 0) return false;
  auto modpow = [](long long a,long long b,long long m)->long long{
    a %= m; long long ret = 1;
    while(b){
      if(b & 1) ret = a * ret % m;
      a = a * a % m;
      b >>= 1;
    }
    return ret;
  };
  map<long long,int> m = PrimeFactors(mod - 1);
  each(x , m){
    if(modpow(r , (mod - 1) / x.fi , mod ) == 1) return false;
  }
  return true;
}

//  ax+by=gcd(a,b)
// 
long long extgcd(long long a,long long b, long long &x, long long &y){
  if(b == 0){
    x = 1; y = 0; return a;
  }
  long long d = extgcd(b , a%b , y , x);
  y -= a / b * x;
  return d;
}

// 
// Point. -1 (UNIT & a = aUNIT)
struct BA{
  unsigned long long x;
  BA(): x(0){}
  BA(unsigned long long y):x(y){}
  
  BA operator += (const BA &p){
    x = x ^ p.x;
    return (*this);
  }
  BA operator *= (const BA &p){
    x = x & p.x;
    return (*this);
  }

  BA operator+(const BA &p)const {return BA(*this) += p;}
  BA operator*(const BA &p)const {return BA(*this) *= p;}
  bool operator==(const BA &p) const { return x == p.x; }
  bool operator!=(const BA &p) const { return x != p.x; }

  friend ostream &operator<<(ostream &os,const BA &p){
    return os << p.x;
  }
  friend istream &operator>>(istream &is, BA &a){
    unsigned int t;
    is >> t;
    a = BA(t);
    return (is);
  }
};

void solve(){
  inl(N);
  if(N == 1) die(1);
  auto factors = PrimeFactors(N);
  if(factors.size() >= 2) out(1);
  else out(factors.begin()->first);
}