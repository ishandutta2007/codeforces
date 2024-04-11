#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

// Light version
using Data = int;
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
  int n;
  cin>>n;
  vecint a(n);
  REP(i,n) cin>>a[i];
  int x = 0;
  ll oldinv = 0;
  vecint val0;
  REP(j,n) val0.push_back(a[j]);
  sort(ALL(val0));
  val0.erase(unique(ALL(val0)), end(val0));
  BIT bit0;
  REP(j,n) {
    int v0 = a[j];
    int idx0 = lower_bound(ALL(val0), v0) - begin(val0);
    int cnt0 = j - bit0.query(idx0);
    oldinv += cnt0;
    bit0.update(idx0, 1);
  }
  REP(ri,30) {
    int i = 29 - ri;
    ll sum0 = 0;
    ll sum1 = 0;
    unordered_map<int,int> cnt0;
    unordered_map<int,int> cnt1;
    cnt0.reserve(min(n, 1<<ri));
    cnt1.reserve(min(n, 1<<ri));
    REP(j,n) {
      int v0 = (a[j] ^ x) >> i;
      int v1 = v0 ^ 1;
      if (v1 & 1) {
        sum0 += cnt0[v1>>1];
        ++cnt1[v1>>1];
      } else {
        ++cnt0[v1>>1];
        sum1 += cnt1[v1>>1];
      }
    }
    if (sum1 < sum0) {
      x |= 1 << i;
      oldinv += sum1 - sum0;
    }
  }
  cout << oldinv << " " << x << "\n";
  return 0;
}