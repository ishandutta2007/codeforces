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

//using namespace harudake;


// a^-1 mod p
i64 inv(i64 a,i64 p){
  return ( a == 1 ? 1 : (1 - p*inv(p%a,a)) / a + p );
}

i64 gcd(i64 a,i64 b){if(a<b)swap(a,b);return b?gcd(b,a%b):a;}
i64 lcm(i64 a,i64 b){return a/gcd(a,b)*b;}

// A[i] * x = B (mod M[i])
pair<i64,i64> linear_congruence(const vector<i64>& A, const vector<i64>& B, const vector<i64>& M) {
  i64 x = 0, m = 1;
  for(i64 i = 0; i < (int)M.size(); i++){
    i64 a = A[i] * m, b = B[i] - A[i] * x, d = __gcd(M[i], a);
    if (b % d != 0) return make_pair(0, -1);
    i64 t = b / d * inv(a / d, M[i] / d) % (M[i] / d);
    x = x + m * t;
    m *= M[i] / d;
  }
  return make_pair(x % m, m);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n,m,k;
  cin>>n>>m>>k;
  --k;
  vi64 id1(1000001, -1);
  vi64 id2(1000001, -1);
  rep(i,n) {
    i64 a;
    cin>>a;
    id1[a] = i;
  }
  rep(i,m) {
    i64 a;
    cin>>a;
    id2[a] = i;
  }
  vi64 days;
  i64 lnm = lcm(n, m);
  rep(i,1000001) {
    if (id1[i] >= 0 && id2[i] >= 0) {
      auto [p,q] = linear_congruence({1, 1}, {id1[i], id2[i]}, {n, m});
      if (q >= 0) {
        if (p < 0) p += lnm;
        days.push_back(p);
      }
    }
  }
  sort(all(days));
  i64 ngdays = lnm - size(days);
  i64 rem = k % ngdays;
  i64 d = k / ngdays;
  i64 ans = d * lnm;
  i64 sz = size(days);
  days.push_back(lnm);
  rep(i,sz+1) {
    if (i + rem < days[i]) {
      ans += i + rem;
      cout<<(ans+1)<<endl;
      return 0;
    }
  }
  return 0;
}