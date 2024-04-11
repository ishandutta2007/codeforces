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

i32 naive(i32 n, i32 l, i32 r, const vi32& clr) {
  vi32 dp(1<<n, n);
  dp[0] = 0;
  rep(i,1<<n) {
    rep(x,n) {
      if ((i>>x)&1) continue;
      rep(y,x) {
        if ((i>>y)&1) continue;
        i32 cost = 0;
        if (y >= l || x < l) ++cost;
        if (clr[x] != clr[y]) ++cost;
        dp[i|1<<x|1<<y] = min(dp[i|1<<x|1<<y], dp[i] + cost);
      }
    }
  }
  return dp.back();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n,l,r;
    cin>>n>>l>>r;
    vi32 hist(n);
    vi32 clr;
    i32 ll = l, rr = r;
    rep(i,l) {
      i32 c;
      cin>>c;
      clr.push_back(c);
      --c;
      ++hist[c];
    }
    rep(i,r) {
      i32 c;
      cin>>c;
      clr.push_back(c);
      --c;
      --hist[c];
    }
    if (r > l) {
      rep(i,n) hist[i] *= -1;
      swap(l, r);
    }
    i32 rem = 0;
    rep(i,n) {
      if (hist[i] < 0) {
        rem += -hist[i];
        hist[i] = 0;
      }
    }
    i32 cost = 0;
    // remove odd
    rep(i,n) {
      if (rem > 0 && hist[i] % 2 == 1) {
        --hist[i];
        ++cost;
        --rem;
      }
    }
    // remove rem
    rep(i,n) {
      i32 red = min(hist[i], rem);
      hist[i] -= red;
      cost += red;
      rem -= red;
    }
    // remove many
    rep(i,n) {
      cost += hist[i] / 2;
      hist[i] %= 2;
      cost += hist[i];
      hist[i] = 0;
    }
    cout<<cost<<"\n";
  }
  return 0;
}