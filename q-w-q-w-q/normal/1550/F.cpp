#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const int N = 200005;
int n, q, s, d, x, y, a[N], f[N], mp[1000005];
bool u[N];
set<int> q1, q2;
struct p {
  int pre, v, x;
  bool operator<(const p &j) const { return v > j.v; }
};
priority_queue<p> lxmtxdy;
inline int get(int x) {
  auto it = q2.lower_bound(x);
  int ans = 1 << 30;
  if (it != q2.end()) ans = *it - x;
  if (it != q2.begin()) {
    it--;
    ans = min(ans, x - *it);
  }
  return ans;
}
int main() {
  cin >> n >> q >> s >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i], mp[a[i]] = i;
    q1.insert(a[i]);
  }
  f[s] = 0;
  lxmtxdy.push(p{0, 0, s});
  while (!lxmtxdy.empty()) {
    p tp = lxmtxdy.top();
    lxmtxdy.pop();
    int v = tp.v, x = tp.x;
    if (u[x]) continue;
    u[x] = 1;
    f[x] = max(f[tp.pre], v), q1.erase(q1.find(a[x]));
    for (int v : {a[x] - d, a[x] + d}) {
      q2.insert(v);
      auto it = q1.lower_bound(v);
      if (it != q1.end()) lxmtxdy.push(p{x, *it - v, mp[*it]});
      if (it != q1.begin()) {
        it--;
        lxmtxdy.push(p{x, v - *it, mp[*it]});
      }
    }
    auto it = q1.lower_bound(a[x]);
    if (it != q1.end()) lxmtxdy.push(p{x, get(*it), mp[*it]});
    if (it != q1.begin()) {
      it--;
      lxmtxdy.push(p{x, get(*it), mp[*it]});
    }
  }
  while (q--) {
    cin >> x >> y;
    puts(f[x] <= y ? "Yes" : "No");
  }
}