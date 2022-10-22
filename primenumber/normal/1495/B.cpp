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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 n;
  cin>>n;
  vi32 p(n);
  rep(i,n) cin>>p[i];
  vi32 inc(n-1);
  rep(i,n-1) inc[i] = p[i] < p[i+1];
  vi32 pos;
  pos.push_back(0);
  rep(i,n-2) {
    if (inc[i] != inc[i+1]) pos.push_back(i+1);
  }
  pos.push_back(n-1);
  i32 m = size(pos);
  vi32 len;
  rep(i,m-1) len.push_back(pos[i+1] - pos[i]);
  sort(all(len));
  reverse(all(len));
  i32 mx = len.front();
  i32 third = size(len) >= 3 ? len[2] : 0;
  i32 cnt = 0;
  rep(i,n-2) {
    if (inc[i] > inc[i+1]) {
      auto idx = lower_bound(all(pos), i+1) - begin(pos);
      i32 ll = pos[idx] - pos[idx-1];
      i32 lr = pos[idx+1] - pos[idx];
      if (mx == ll && mx % 2 == 0 && ll == lr && third < mx) {
        ++cnt;
      }
    }
  }
  cout<<cnt<<endl;
  return 0;
}