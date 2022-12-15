#include <bits/stdc++.h>
#define int long long
using namespace std;

template <class T> class Fenwick {
public:
  int lim;
  vector<T> bit;

  Fenwick(int n) : lim(n + 1), bit(lim) {}

  void upd(int pos, T val) {
    for (pos++; pos < lim; pos += pos & -pos)
      bit[pos] += val;
  }

  T sum(int r) { // < r
    T ret = 0;
    for (; r; r -= r & -r)
      ret += bit[r];
    return ret;
  }

  T sum(int l, int r) { // [l, r)
    return sum(r) - sum(l);
  }
};

const int MAXN = 3e5 + 1;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  Fenwick<int> fenSum(MAXN), fenCount(MAXN);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  bitset<MAXN> seen;
  seen.reset();

  int ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j * a[i] < MAXN; ++j) {
      int l = j * a[i];
      int r = min(MAXN, l + a[i]);
      int cnt = fenCount.sum(l, r);
      int totSum = fenSum.sum(l, r);
      ret += totSum - cnt * j * a[i];
    }

    for (int d = 1; d * d <= a[i]; ++d)
      if (seen[d]) {
        int quotient = a[i] / d;
        int modu = a[i] - d * quotient;
        if (quotient * quotient > a[i])
          ret += modu;
      }

    for (int d = 1; d * d <= a[i]; ++d) {
      int up = a[i] / d + 1; // < up
      int lo = a[i] / (d + 1) + 1;
      if (lo < up) {
        int cnt = fenCount.sum(lo, up);
        int sum = fenSum.sum(lo, up);
        ret += cnt * a[i] - d * sum;
      }
    }
    ret += fenCount.sum(a[i], MAXN) * a[i];

    cout << ret << ' ';
    fenCount.upd(a[i], 1);
    fenSum.upd(a[i], a[i]);
    seen[a[i]] = 1;
  }
  cout << endl;
}