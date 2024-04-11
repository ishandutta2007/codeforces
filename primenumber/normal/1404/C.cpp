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

int bise(BIT& bit, int m, int n) {
  int le = -1;
  int gt = n;
  while (gt - le > 1) {
    int mid = (gt + le) / 2;
    if (bit.query(mid) >= m) {
      le = mid;
    } else {
      gt = mid;
    }
  }
  return le;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin>>n>>q;
  vecint a(n);
  REP(i,n)cin>>a[i];
  vector<tuple<int,int,int>> vq;
  REP(i,q) {
    int x,y;
    cin>>x>>y;
    y = n - y;
    vq.emplace_back(y,x,i);
  }
  sort(ALL(vq));
  BIT bit;
  vecint ans(q);
  auto itr = begin(vq);
  REP(i,n) {
    int diff = i+1 - a[i];
    if (diff >= 0) {
      int index = bise(bit, diff, i+1);
      bit.update(0, 1);
      bit.update(index+1, -1);
    }
    while (itr != end(vq)) {
      auto [y,x,j] = *itr;
      if (y != i+1) break;
      int idx = bit.query(x);
      ans[j] = idx;
      ++itr;
    }
  }
  REP(i,q) {
    cout<<ans[i]<<"\n";
  }
  return 0;
}