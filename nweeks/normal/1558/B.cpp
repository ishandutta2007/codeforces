#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int MAXN = 4e6 + 1;
int dp[MAXN];
int n, m;

template <class T> class Fenwick {
public:
  int lim;
  vector<T> bit;

  Fenwick(int n) : lim(n + 1), bit(lim) {}

  void upd(int pos, T val) {
    for (pos++; pos < lim; pos += pos & -pos) {
      bit[pos] += val;
      if (bit[pos] >= m)
        bit[pos] -= m;
    }
  }

  T sum(int r) { // < r
    T ret = 0;
    for (; r; r -= r & -r) {
      ret += bit[r];
      if (ret >= m)
        ret -= m;
    }
    return ret;
  }

  T sum(int l, int r) { // [l, r)
    int ret = sum(r) + m - sum(l);
    if (ret >= m)
      ret -= m;
  }
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  Fenwick<int> fen1(n + 1), fen2(n + 1);

  auto rangeAdd = [&](int l, int r, int x) {
    fen1.upd(l, x);
    fen1.upd(r + 1, x ? m - x : 0);
    // fen2.upd(l, x * (l - 1LL) % m);
    // fen2.upd(r + 1, (x ? m - x : 0) * (long long)r % m);
  };

  auto ptVal = [&](int x) { return fen1.sum(x + 1); };

  dp[1] = 1;
  rangeAdd(1, 1, 1);
  int cumSum = 1;
  for (int i = 2; i <= n; ++i) {
    int toAdd = cumSum;
    rangeAdd(i, i, toAdd);

    // divide by i ?
    for (int k = 1; i * k <= n and k <= i; ++k) {
      int a = ptVal(k);
      if (a < 0)
        a += m;
      rangeAdd(k * i, min(n, (k + 1) * i - 1), a);
    }
    // divide by j < i and get i ?
    int a = ptVal(i);
    for (int j = 2; j < i and i * j <= n; ++j) {
      if (a < 0)
        a += m;
      rangeAdd(i * j, min(n, j * (i + 1) - 1), a);
    }
    cumSum += a;
    if (cumSum >= m)
      cumSum -= m;
  }
  cout << ptVal(n) << endl;
  // cout << (prefSum(n) - prefSum(n - 1) + m) % m << endl;
}