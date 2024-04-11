#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

struct SegTree {
  int sum0[N << 2];
  long long sum1[N << 2];
  long long sum2[N << 2];
  int lazy[N << 2];

  void add(int idx, int val) {
    sum2[idx] += 1LL * val * sum1[idx] + (1LL * val * val - val) * sum0[idx] / 2;
    sum1[idx] += 1LL * val * sum0[idx];
    lazy[idx] += val;
  }

  void propagate(int idx) {
    if (lazy[idx] == 0) return;
    add(idx * 2 + 1, lazy[idx]);
    add(idx * 2 + 2, lazy[idx]);
    lazy[idx] = 0;
  }

  void update(int idx, int l, int r, int ll, int rr, int val) {
    if (l >= rr || r <= ll) return;
    if (l >= ll && r <= rr) {
      add(idx, val);
      return;
    }

    int mid = (l + r) >> 1;
    propagate(idx);
    update(idx * 2 + 1, l, mid, ll, rr, val);
    update(idx * 2 + 2, mid, r, ll, rr, val);
    sum1[idx] = (sum1[idx * 2 + 1] + sum1[idx * 2 + 2]);
    sum2[idx] = (sum2[idx * 2 + 1] + sum2[idx * 2 + 2]);
  }

  void toggle(int idx, int l, int r, int x, int val) {
    if (l > x || r <= x) return;
    if (l == x && x + 1 == r) {
      sum0[idx] = 1 - sum0[idx];
      sum1[idx] = sum0[idx] * val;
      sum2[idx] = 1LL * val * (val - 1) / 2 * sum0[idx];
      return;
    }

    int mid = (l + r) >> 1;
    propagate(idx);
    toggle(idx * 2 + 1, l, mid, x, val);
    toggle(idx * 2 + 2, mid, r, x, val);
    sum0[idx] = (sum0[idx * 2 + 1] + sum0[idx * 2 + 2]);
    sum1[idx] = (sum1[idx * 2 + 1] + sum1[idx * 2 + 2]);
    sum2[idx] = (sum2[idx * 2 + 1] + sum2[idx * 2 + 2]);
  }

  void update(int l, int r, int val) {
    update(0, 0, N, max(0, l), min(r, N), val);
  }

  void toggle(int x, int val) {
    toggle(0, 0, N, x, val);
  }
} tree;

struct BIT {
  int sum[N];
  void update(int x, int val) {
    for (int i = x; i < N; i += i & -i) sum[i] += val;
  }
  int query(int x) {
    int ret = 0;
    for (int i = min(x, N - 1); i > 0; i -= i & -i) ret += sum[i];
    return ret;
  }
} bit;

int solve() {
  int q, d;
  scanf("%d %d", &q, &d);
  set<int> exists;
  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);
    int add = 1;
    if (exists.find(x) == exists.end()) {
      exists.insert(x);
    } else {
      exists.erase(x);
      add = -1;
    }
    int cnt = bit.query(x + d) - bit.query(x);
    bit.update(x, add);

    tree.toggle(x, cnt);
    tree.update(x - d, x, add);
    printf("%lld\n", tree.sum2[0]);
  }

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}