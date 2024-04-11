#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Fenwick {
 public:
  int sz;
  vector<T> tree;
  Fenwick(int sz) : sz(sz), tree(sz, 0) {}
  void Add(int p, T x) {
    for (int i = p; i < sz; i |= i + 1) {
      tree[i] += x;
    }
  }
  T Sum(int p) {
    T res = 0;
    for (int i = p + 1; i > 0; i &= i - 1) {
      res += tree[i - 1];
    }
    return res;
  }
};

vector<long long> Solve(int N, vector<int> A) {
  vector<long long> ans(N);
  const auto Calc = [&]() {
    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
      pos[A[i]] = i;
    }

    Fenwick<int> active(N);
    long long current_ans = 0;
    Fenwick<int> cntToR(N + 1);
    for (int i = 0; i < N; i++) {
      cntToR.Add(i, 1);
    }

    // Segment Tree Beats = array toR[]
    const int INF = 1e9;
    vector<array<int, 4>> seg(2 * N); // (max, second_max, count_max, lazy)
    const auto Apply = [&](int n, int v) {
      if (v != INF && v < seg[n][0]) {
        assert(seg[n][1] < v);
        seg[n][0] = v;
        seg[n][3] = v;
      }
    };
    const auto Merge = [&](array<int, 4> a, array<int, 4> b) {
      if (a[0] < b[0]) {
        a[1] = a[0];
        a[0] = b[0];
        a[2] = 0;
      }
      if (a[0] == b[0]) {
        a[2] += b[2];
        a[1] = max(a[1], b[1]);
      } else {
        a[1] = max(a[1], b[0]);
      }
      a[3] = INF;
      return a;
    };
    const auto Push = [&](int n, int lc, int rc) {
      Apply(lc, seg[n][3]);
      Apply(rc, seg[n][3]);
      seg[n][3] = INF;
    };
    const auto Build = [&](const auto &self, int n, int tl, int tr) -> void {
      if (tl == tr) {
        seg[n][0] = tl - 1;
        seg[n][1] = -INF;
        seg[n][2] = 1;
        seg[n][3] = INF;
        return;
      }
      int md = (tl + tr) / 2;
      int z = n + 2 * (md - tl + 1);
      self(self, n + 1, tl, md);
      self(self, z, md + 1, tr);
      seg[n] = Merge(seg[n + 1], seg[z]);
    };
    const auto RangeMinimum = [&](const auto &self, int n, int tl, int tr, int l, int r, int v) -> void {
      if (l > tr || tl > r || tl > tr || l > r || seg[n][0] <= v) return;
      if (l <= tl && tr <= r && seg[n][1] < v) {
        cntToR.Add(seg[n][0] + 1, -seg[n][2]);
        current_ans -= 1ll * seg[n][2] * active.Sum(seg[n][0]);
        Apply(n, v);
        cntToR.Add(seg[n][0] + 1, +seg[n][2]);
        current_ans += 1ll * seg[n][2] * active.Sum(seg[n][0]);
        return;
      }
      int md = (tl + tr) / 2;
      int z = n + 2 * (md - tl + 1);
      Push(n, n + 1, z);
      self(self, n + 1, tl, md, l, r, v);
      self(self, z, md + 1, tr, l, r, v);
      seg[n] = Merge(seg[n + 1], seg[z]);
    };
    const auto Modify = [&](const auto &self, int n, int tl, int tr, int p, int v) -> void {
      if (tl == tr) {
        cntToR.Add(seg[n][0] + 1, -seg[n][2]);
        current_ans -= 1ll * seg[n][2] * active.Sum(seg[n][0]);
        seg[n][0] = v;
        cntToR.Add(seg[n][0] + 1, +seg[n][2]);
        current_ans += 1ll * seg[n][2] * active.Sum(seg[n][0]);
        return;
      }
      int md = (tl + tr) / 2;
      int z = n + 2 * (md - tl + 1);
      Push(n, n + 1, z);
      if (p <= md) {
        self(self, n + 1, tl, md, p, v);
      } else {
        self(self, z, md + 1, tr, p, v);
      }
      seg[n] = Merge(seg[n + 1], seg[z]);
    };
    const auto Query = [&](const auto &self, int n, int tl, int tr, int p) -> int {
      if (tl == tr) return seg[n][0];
      int md = (tl + tr) / 2;
      int z = n + 2 * (md - tl + 1);
      Push(n, n + 1, z);
      if (p <= md) {
        return self(self, n + 1, tl, md, p);
      } else {
        return self(self, z, md + 1, tr, p);
      }
    };

    Build(Build, 1, 0, N - 1);

    set<int> set_active;
    set_active.emplace(pos[0]);

    int fr = pos[0];
    int bk = pos[0];
    active.Add(pos[0], 1);
    Modify(Modify, 1, 0, N - 1, fr, bk);

    current_ans = 0;
    for (int i = 0; i < N; i++) {
      current_ans += active.Sum(Query(Query, 1, 0, N - 1, i));
    }

    for (int level = 1; level < N; level++) {
      active.Add(pos[level], 1);
      set_active.emplace(pos[level]);
      current_ans += cntToR.Sum(N) - cntToR.Sum(pos[level]);
      if (pos[level] < fr) {
        fr = pos[level];
        Modify(Modify, 1, 0, N - 1, fr, bk);
      } else if (bk < pos[level]) {
        bk = pos[level];
        Modify(Modify, 1, 0, N - 1, fr, bk);
      } else {
        int nl = *prev(set_active.find(pos[level]));
        int nr = *next(set_active.find(pos[level]));
        Modify(Modify, 1, 0, N - 1, nr, bk);
        RangeMinimum(RangeMinimum, 1, 0, N - 1, fr + 1, nl, nl);
      }
      ans[level] += current_ans;
    }
  };
  
  for (int i = 0; i < 2; i++) {
    Calc();
    reverse(begin(A), end(A));
  }

  ans[0] = 1;
  for (int i = 1; i < N; i++) {
    ans[i] -= 1ll * N * (i + 1);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }

  auto ans = Solve(N, A);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}