#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

struct RollingHash {
  static const uint64_t mod = (1ull << 61ull) - 1;
  using uint128_t = __uint128_t;
  vector< uint64_t > power;
  const uint64_t base;

  static inline uint64_t add(uint64_t a, uint64_t b) {
    if((a += b) >= mod) a -= mod;
    return a;
  }

  static inline uint64_t mul(uint64_t a, uint64_t b) {
    uint128_t c = (uint128_t) a * b;
    return add(c >> 61, c & mod);
  }

  static inline uint64_t generate_base() {
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution< uint64_t > rand(1, RollingHash::mod - 1);
    return rand(mt);
  }

  inline void expand(size_t sz) {
    if(power.size() < sz + 1) {
      int pre_sz = (int) power.size();
      power.resize(sz + 1);
      for(int i = pre_sz - 1; i < sz; i++) {
        power[i + 1] = mul(power[i], base);
      }
    }
  }

  explicit RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}

  vector< uint64_t > build(const string &s) const {
    int sz = s.size();
    vector< uint64_t > hashed(sz + 1);
    for(int i = 0; i < sz; i++) {
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
    return hashed;
  }

  template< typename T >
  vector< uint64_t > build(const vector< T > &s) const {
    int sz = s.size();
    vector< uint64_t > hashed(sz + 1);
    for(int i = 0; i < sz; i++) {
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
    return hashed;
  }

  uint64_t query(const vector< uint64_t > &s, int l, int r) {
    expand(r - l);
    return add(s[r], mod - mul(s[l], power[r - l]));
  }

  uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len) {
    expand(h2len);
    return add(mul(h1, power[h2len]), h2);
  }

  int lcp(const vector< uint64_t > &a, int l1, int r1, const vector< uint64_t > &b, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = 0, high = len + 1;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(query(a, l1, l1 + mid) == query(b, l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return low;
  }
};

// a^-1 mod p
i64 inv(i64 a,i64 p){
  return ( a == 1 ? 1 : (1 - p*inv(p%a,a)) / a + p );
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n,q;
  cin>>n>>q;
  string s0, t;
  cin>>s0>>t;
  vector<string> vs;
  vs.push_back(s0);
  while (size(vs) <= n && size(vs.back()) < 1'000'000) {
    auto s = vs.back();
    auto nxt = s + t[size(vs)-1] + s;
    vs.push_back(nxt);
  }
  //for (auto&& l : vs) dump<<l<<endl;
  i64 m = size(vs);
	RollingHash rollh;
  vector<vector<uint64_t>> vhs(m);
  rep(i,m) {
		vhs[i] = rollh.build(vs[i]);
  }
  constexpr i64 mod = 1'000'000'007;
  vi64 p2(n+1);
  p2[0] = 1;
  rep(i,n) {
    p2[i+1] = p2[i] * 2 % mod;
  }
	vector hist(26, vi64(n+1));
  rep(i,n) {
    rep(j,26) {
      hist[j][i+1] = hist[j][i];
    }
    hist[t[i]-'a'][i+1] += p2[n-i-1];
    hist[t[i]-'a'][i+1] %= mod;
  }
  rep(qid,q) {
    i64 k;
    cin>>k;
    string w;
    cin>>w;
    auto v = rollh.build(w);
    i64 len = size(w);
    i64 mxm = min(k+1, m);
    if (len > size(vs[mxm-1])) {
      cout<<0<<"\n";
      continue;
    }
    rep(i,mxm) {
      if (len <= size(vs[i])) {
        i64 cnt = 0;
        i64 l2 = size(vs[i]);
        rep(j,l2 - len + 1) {
          if (rollh.query(v, 0, len) == rollh.query(vhs[i], j, j+len)) {
            ++cnt;
          }
        }
        cnt *= p2[k - i];
        cnt %= mod;
        //dump<<qid<<" "<<i<<" "<<cnt<<endl;
        rep(j,len) {
          if (rollh.query(v, len - j, len) != rollh.query(vhs[i], 0, j)) continue;
          if (rollh.query(v, 0, len - j - 1) != rollh.query(vhs[i], l2 - (len - j - 1), l2)) continue;
          i32 ch = w[len-j-1] - 'a';
          //dump<<qid<<" "<<i<<" "<<j<<" "<<ch<<endl;
          cnt += (hist[ch][k] + mod - hist[ch][i]) % mod * inv(p2[n-k], mod) % mod;
          cnt %= mod;
        }
        cout<<cnt<<"\n";
        break;
      }
    }
  }
  return 0;
}