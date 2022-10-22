#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

struct bitmat {
  bitmat(int n) : data(n) {}
  int size() const { return std::size(data); }
  vector<bitset<500>> data;
};

bitmat operator*(const bitmat& lhs, const bitmat& rhs) {
  int n = lhs.size();
  bitmat res(n);
  REP(i,n) {
    REP(k,n) {
      if (lhs.data[i][k]) {
        res.data[i] |= rhs.data[k];
      }
    }
  }
  return res;
}

bitset<500> operator*(const bitset<500>& lhs, const bitmat& rhs) {
  int n = lhs.size();
  bitset<500> res;
  REP(k,n) {
    if (lhs[k]) {
      res |= rhs.data[k];
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m;
  cin>>n>>m;
  bitmat p(n), b(n);
  REP(i,m) {
    ll v,u,t;
    cin>>v>>u>>t;
    --v;--u;
    if (t == 0) {
      p.data[v][u] = true;
    } else {
      b.data[v][u] = true;
    }
  }
  vector<bitmat> dp, db;
  dp.push_back(p);
  db.push_back(b);
  REP(i,60) {
    auto&& x = dp.back();
    auto&& y = db.back();
    auto f = x * y;
    auto g = y * x;
    dp.push_back(f);
    db.push_back(g);
  }
  bitset<500> cur;
  cur[0] = true;
  bool inv = false;
  ll ans = 0;
  REP(ri,60) {
    ll i = 60 - ri - 1;
    auto&& rhs = inv ? db[i] : dp[i];
    auto&& prod = cur * rhs;
    bool is_zero = true;
    REP(c,n) {
      if (prod[c]) is_zero = false;
    }
    if (!is_zero) {
      cur = prod;
      inv = !inv;
      ans |= 1ll << i;
    }
  }
  if (ans <= 1'000'000'000'000'000'000ll) {
    cout<<ans<<endl;
  } else {
    cout<<-1<<endl;
  }
  return 0;
}