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

// Light version
using Data = i64;
const int len = 1 << 19;

struct BIT {
  vector<Data> data;
  BIT() : data(len, 0) {}
  void update(int i, Data value) {
    for (; i < len; i |= i+1) data[i] += value;
  }
  Data query(int i) {
    Data s = 0;
    for (; i >= 0; i = (i&i+1)-1) s += data[i];
    return s;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n;
  cin>>n;
  BIT b0, b1, s, c;
  i64 ans = 0;
  i64 sum = 0;
  rep(i,n) {
    i32 a;
    cin>>a;
    i64 v0 = b0.query(a);
    i64 v1 = b1.query(a) * a;
    i64 ls = s.query(a);
    //dump<<v0<<" "<<v1<<" "<<ls;
    b1.update(0, 1);
    i64 h = 0;
    h += sum;
    for(i32 j = a; j < len; j += a) {
      b0.update(j, -a);
      h -= (i - c.query(j-1)) * a;
    }
    //dump<<" "<<h<<"\n";
    s.update(a, a);
    c.update(a, 1);
    ans += v0 + v1 + h;
    sum += a;
    if (i) cout<<" ";
    cout<<ans;
  }
  cout<<"\n";
  return 0;
}