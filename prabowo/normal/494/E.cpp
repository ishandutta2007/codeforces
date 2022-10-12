#include <bits/stdc++.h>
using namespace std;

const int M = 50005 * 2;

int n, m, k;

tuple<int, int, int, int> segs[M];

// 2^ctz(min(row, col, k))
void nim() {
  int n = 50, m = 50, k = 17;
  int dp[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vector<bool> vis(n*m + 5, false);
      for (int len = 0; len <= min(k-1, min(i, j)); ++len) {
        int cur = dp[i][j] = 0;
        for (int x = i - len; x <= i; ++x) for (int y = j - len; y <= j; ++y) {
          cur ^= dp[x][y];
        }
        vis[cur] = true;
      }
      int mex;
      for (mex = 0; vis[mex]; ++mex);
      dp[i][j] = mex;

      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}



struct SegTree {
  int cnt[M << 2];
  int sum[M << 2];

  vector<int> pre;

  void init(const vector<int> &_pre) {
    pre = _pre;
  }

  void update(int idx, int l, int r, int ll, int rr, int val) {
    if (l >= rr || r <= ll) return;
    if (l >= ll && r <= rr) {
      cnt[idx] += val;
      sum[idx] = (cnt[idx] == 0 ? l == r - 1 ? 0 : sum[idx*2 + 1] + sum[idx*2 + 2] : pre[r] - pre[l]);
      return;
    }

    int mid = (l + r) >> 1;

    update(idx*2 + 1, l, mid, ll, rr, val);
    update(idx*2 + 2, mid, r, ll, rr, val);
    sum[idx] = (cnt[idx] == 0 ? sum[idx*2 + 1] + sum[idx*2 + 2] : pre[r] - pre[l]);
  }

  void update(int l, int r, int val) {
    update(0, 0, pre.size(), l, r, val);
  }

  int query() {
    return sum[0];
  }
} tree;

int main() {
  // nim();
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    --a, --b;
    segs[i*2 + 0] = make_tuple(a, b, d, 1);
    segs[i*2 + 1] = make_tuple(c, b, d, -1);
  }

  sort(segs, segs + m*2);

  int LG = 32 - __builtin_clz(k);
  vector<long long> area(LG + 1);
  for (int lg = 0; lg < LG; ++lg) {
    vector<int> ys;
    for (int i = 0; i < m*2; ++i) {
      int y, yy, _;
      tie(_, y, yy, _) = segs[i];
      ys.push_back(y / (1 << lg));
      ys.push_back(yy / (1 << lg));
    }
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    tree.init(ys);

    area[lg] = 0;

    int lst = 0;
    for (int i = 0; i < m*2; ++i) {
      int x, y, yy, val;
      tie(x, y, yy, val) = segs[i];
      area[lg] += 1LL * (x/(1 << lg) - lst/(1 << lg)) * tree.query();

      tree.update(lower_bound(ys.begin(), ys.end(), y/(1 << lg)) - ys.begin(), lower_bound(ys.begin(), ys.end(), yy/(1 << lg)) - ys.begin(), val);
      lst = x;
    }
    // cerr << area[lg] << endl;
  }

  for (int i = 0; i < LG; ++i) {
    if (area[i] - area[i+1] & 1) return 0 * printf("Hamed\n");
  }
  printf("Malek\n");
  return 0;
}