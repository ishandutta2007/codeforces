#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n,k;
  cin>>n>>k;
  vi64 c(n);
  rep(i,n) cin>>c[i];
  sort(all(c));
  vi64 ps(n+1);
  rep(ri,n) {
    i64 i = n-1-ri;
    ps[i] = ps[i+1] + c[i];
  }
  vi64 tris(n+1);
  rep(ri,n) {
    i64 i = n-1-ri;
    tris[i] = tris[i+1] + ps[i];
  }
  i64 ans = tris[1];
  i64 sum = 0;
  rep(i,n) {
    i64 depth = i / (k+1);
    sum += c[i] * depth;
    ans = max(ans, sum + tris[i+1] + ps[i+1] * depth);
  }
  cout<<ans<<endl;
  return 0;
}