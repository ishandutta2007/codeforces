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
  #define trca(v,...) do { cerr << #v << " = "; array_out(v , __VA_ARGS__ );} while(0)
#else
  #define trc(...)
  #define trca(...)
  int main(){solve();}
#endif
 
using P = pair<int,int>; using vp = vector<P>;
constexpr int MOD = /**/ 1000000007; //*/ 998244353;
/////////////////

// 
//  -> RollingHash s_rori(S);
// mod
// -> RollingHash t_rori(T , false , s_rori.basis);
template<typename string_t> struct RollingHash{
  using ull = unsigned long long;
  using Pu = pair<ull , ull>;
  static constexpr ull rmod = (1ull << 61) - 1;
  vector<Pu> hashed , power;
  const int size_;
  Pu basis;
  
  static constexpr ull mul(const ull a,const ull b){
    ull l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
    ull l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
    ull ret = (l & rmod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3);
    if(ret > rmod) ret = (ret & rmod) + (ret>>61);
    if(ret >= rmod) ret -= rmod;
    return ret;
  }
  static constexpr ull mul_plus(const ull a,const ull b,const ull c){
    ull l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
    ull l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
    ull ret = (l & rmod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + c;
    if(ret > rmod) ret = (ret & rmod) + (ret>>61);
    if(ret >= rmod) ret -= rmod;
    return ret;
  }
  ull modpow(ull a,ull b){
    a %= rmod;
    ull r = 1;
    while(b) {
      if(b & 1) r = mul(r , a);
      a = mul(a , a);
      b >>= 1;
    }
    return r;
  }
  bool isPrimitive(ull x, vector<ull> &ds) {
    for(ll d : ds)
      if(d != rmod - 1) {
        if(modpow( x, (rmod - 1) / d ) == 1) return false;
      }
    return true;
  }
  Pu get_basis(){
    vector<ull> ds = {2,3,5,7,11,13,31,41,61,151,331,1321};
    auto rand_time = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
    mt19937_64 rng(rand_time);
    ull a = -1 , b = -1;
    do{ a = rng() % rmod; }while(isPrimitive(a , ds) == false);
    do{ b = rng() % rmod; }while(a == b || isPrimitive(b , ds) == false);
    return Pu(a , b);
  }

  // Rolling HashO( |S| )
  // basis_flagtruebasisfalsebbasis
  RollingHash(string_t &S , const int basis_flag = true , const Pu b = Pu(0 , 0) ) : size_((int)S.size()){
    // hashed[i] [0 , i) hashed[0] = (0,0)
    // power[i] basisi
    hashed.resize(size_ + 1 , Pu(0 , 0));
    power.resize(size_ + 1 , Pu(0 , 0));
    if(basis_flag == true) basis = get_basis();
    else basis = b;
    power[0] = Pu(1 , 1);
    for(int i = 1 ; i <= size_ ; i++){
      power[i].fi = mul( power[i - 1].fi , basis.fi);
      power[i].se = mul( power[i - 1].se , basis.se);
      hashed[i].fi = mul_plus( hashed[i - 1].fi , basis.fi , S[i - 1]);
      hashed[i].se = mul_plus( hashed[i - 1].se , basis.se , S[i - 1]);
    }
  }

  // [ l , r ) O(1)
  Pu get(const int l , const int r){
    Pu ret;
    ret.fi = rmod - mul_plus( hashed[l].fi , power[r-l].fi , rmod - hashed[r].fi );
    ret.se = rmod - mul_plus( hashed[l].se , power[r-l].se , rmod - hashed[r].se );
    return ret;
  }

  // O( |T| )
  Pu get_hash(string_t &T){
    Pu ret = Pu(0 , 0);
    for(int i = 0 ; i < (int)T.size() ; i++){
      ret.fi = mul_plus(ret.fi , basis.fi , T[i]);
      ret.se = mul_plus(ret.se , basis.se , T[i]);
    }
    return ret;
  }

  //  O ( |S| + |T| )
  // -1
  int find(string_t &T){
    auto t_hash = get_hash(T);
    int t_size = (int)(T.size());
    // |S| < |T|for
    for(int i = 0 ; i <= size_ - t_size ; i++){
      if(t_hash == get( i , i + t_size ) ) return i;
    }
    return -1;
  }

  //  O ( |S| + |T| )
  // index
  vector<int> find_all(string_t &T){
    auto t_hash = get_hash(T);
    int t_size = (int)(T.size());
    vector<int> ret;
    // |S| < |T|for
    for(int i = 0 ; i <= size_ - t_size ; i++){
      if(t_hash == get( i , i + t_size ) ) ret.push_back(i);
    }
    return ret;
  }

  // Longest Common Prefix() O(log |S|)
  //  ()

  //  O ( |S| (log|S|)^2 )
  int LongestCommonSubString(){
    auto func = [&](int len) -> bool {
      map < Pu , int > m;
      for(int i = 0 ; i <= size_ - len ; i++){
        if( (m[get(i , i + len)] += 1) != 1) return true;
      }
      return false; 
    };
    
    int ok = 0 , ng = size_ ;
    while(ok + 1 < ng){
      int med = (ok + ng) / 2;
      if(func(med)) ok = med;
      else ng = med;
    }
    return ok;
  }

};

void solve(){
  ini(N , Q);
  ins(S);
  vector<vector<char>> v(26 , vector<char>(N , 0));
  rep(i , N){
    v[S[i] - 'a'][i] = 1;
  }
  string dummy = "nya";
  RollingHash<string> rori(dummy);

  vector<RollingHash<vector<char>>> loli;
  rep(i , 26){
    RollingHash<vector<char>> roriha(v[i],false,rori.basis);
    loli.push_back(roriha);
  }

  rep(i , Q){
    using pu=pair<unsigned long long,unsigned long long>;
    ini(a , b , len); a--; b--;
    vector<pu> x(26) , y(26);
    rep(i,26){
      x[i] = loli[i].get(a , a + len);
      y[i] = loli[i].get(b , b + len);
    }
    sort(all(x)); sort(all(y));
    out(x==y ? "YES" : "NO");
  }

}