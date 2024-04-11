#include <bits/stdc++.h>
using namespace std;

int st[1 << 21];
int lazy[1 << 21];

class LazySeg {
 public:
  int N;
  LazySeg(int n) : N(n) {
    for (int i = 0; i < 2 * n; i++) {
      st[i] = lazy[i] = 0;
    }
  }

  void Apply(int n, int x) {
    st[n] += x;
    lazy[n] += x;
  }

  void Push(int n, int lc, int rc) {
    Apply(lc, lazy[n]);
    Apply(rc, lazy[n]);
    lazy[n] = 0;
  }

  void update_range(int s, int e, int x, int lo=0, int hi=-1, int node=1) {
    if (hi == -1) hi = N - 1;
    if (hi < s || lo > e) return;
    if (lo >= s && hi <= e) return Apply(node, x);
    int mid = (lo + hi) / 2;
    int lc = node + 1;
    int rc = node + 2 * (mid - lo + 1);
    Push(node, lc, rc);
    update_range(s, e, x, lo, mid, lc);
    update_range(s, e, x, mid + 1, hi, rc);
    st[node] = min(st[lc], st[rc]);
  }

  int query(int s, int e, int lo=0, int hi=-1, int node=1) {
    if (hi == -1) hi = N - 1;
    if (hi < s || lo > e) return 1e9;
    if (lo >= s && hi <= e) return st[node];
    int mid = (lo + hi) / 2;
    int lc = node + 1;
    int rc = node + 2 * (mid - lo + 1);
    Push(node, lc, rc);
    return min(query(s, e, lo, mid, lc), query(s, e, mid + 1, hi, rc));
  }
};

class SegTree {
 public:
  int sz;
  vector<int> tree;
  SegTree(int n) : sz(n), tree(2 * n) {}
  void Update(int p, int x) {
    for (p += sz; p > 0; p /= 2) tree[p] += x;
  }
  int Query(int l, int r) {
    if (l > r) return 0;
    int z = 0;
    for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) z += tree[l++];
      if (r & 1) z += tree[--r];
    }
    return z;
  }
};

void Main() {
  int N, M;
  cin >> N >> M;
  vector<int> coords;
  vector<int> A(N), B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    coords.emplace_back(A[i]);
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
    coords.emplace_back(B[i]);
  }
  sort(begin(B), end(B));
  sort(begin(coords), end(coords));
  coords.resize(unique(begin(coords), end(coords)) - begin(coords));
  for (auto &a : A) a = lower_bound(begin(coords), end(coords), a) - begin(coords);
  for (auto &a : B) a = lower_bound(begin(coords), end(coords), a) - begin(coords);
  vector<vector<int>> events(coords.size());
  for (int i = 0; i < N; i++) events[A[i]].emplace_back(i);
  for (int i = 0; i < M; i++) events[B[i]].emplace_back(-1);
  long long ans = 0;
  SegTree seg(coords.size());
  for (int i = 0; i < N; i++) {
    seg.Update(A[i], 1);
    ans += seg.Query(A[i] + 1, int(coords.size()) - 1);
  }
  LazySeg lz(N + 5);
  for (int i = 0; i < N; i++) {
    lz.update_range(i + 1, N, 1);
  }
  for (int cc = 0; cc < int(coords.size()); cc++) {
    for (auto x : events[cc]) {
      if (x != -1) {
        lz.update_range(x + 1, N, -1);
      }
    }
    for (auto x : events[cc]) {
      if (x == -1) {
        ans += lz.query(0, N);
      }
    }
    for (auto x : events[cc]) {
      if (x != -1) {
        lz.update_range(0, x, 1);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}