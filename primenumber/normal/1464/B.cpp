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

i64 calc(const string& s, i64 x, i64 y) {
  i64 z = 0;
  i64 o = 0;
  i64 ans = 0;
  for (auto&& ch : s) {
    if (ch == '0') {
      ans += o * y;
      ++z;
    } else if (ch == '1') {
      ans += z * x;
      ++o;
    }
  }
  return ans;
}

i64 solve(const string& s, i64 x, i64 y) {
  //dump<<s<<endl;
  i64 n = size(s);
  vector cnt(3, vi64(n+1));
  string v = "01?";
  rep(i,n) {
    rep(j,3) {
      cnt[j][i+1] = cnt[j][i] + (s[i] == v[j]);
    }
  }
  vi64 bwd(n+1);
  i64 o = 0, q = 0;
  rep(ri,n) {
    i64 i = n - 1 - ri;
    if (s[i] == '?') {
      bwd[i] = bwd[i+1] + o * x;
      ++q;
    } else if (s[i] == '1') {
      bwd[i] = bwd[i+1] + q * y;
      ++o;
    } else {
      bwd[i] = bwd[i+1];
    }
    //dump<<bwd[i]<<endl;
  }
  i64 mn = 1e17;
  i64 z = 0;
  q = 0;
  i64 fwd = 0;
  i64 base = calc(s, x, y);
  //cerr<<base<<endl;
  rep(i,n+1) {
    i64 p1 = cnt[1][i];
    i64 n0 = (cnt[0][n] - cnt[0][i]);
    i64 score = base;
    score += cnt[2][i] * (cnt[2][n] - cnt[2][i]) * y;
    score += cnt[2][i] * n0 * y;
    score += p1 * (cnt[2][n] - cnt[2][i]) * y;
    score += fwd;
    score += bwd[i];
    //dump<<p1<<" "<<n0<<" "<<score<<endl;
    mn = min(mn, score);
    //string t = s;
    //rep(j,n) {
    //  if (t[j] == '?') {
    //    if (j < i) t[j] = '1';
    //    else t[j] = '0';
    //  }
    //}
    //assert(score == calc(t, x, y));
    if (i < n) {
      if (s[i] == '?') {
        fwd += z * x;
        ++q;
      } else if (s[i] == '0') {
        fwd += q * y;
        ++z;
      }
    }
  }
  //dump<<endl;
  return mn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin>>s;
  i64 x,y;
  cin>>x>>y;
  auto t = s;
  reverse(all(t));
  cout<<min(solve(s,x,y), solve(t,y,x))<<endl;
  return 0;
}