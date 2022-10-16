#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

const int N = 2e7 + 5;
const Long MOD = 1LL << 32;

ULong b[N];
Long arr[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  int t;
  cin >> t;

  while (t--) {
    ULong n, x, y, z, b1, b2;
    Long l, r;

    cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
    b[1] = b1, b[2] = b2;
    for (int i = 3; i <= n; ++i) {
      b[i] = ((b[i - 2] * x) % MOD + (b[i - 1] * y) % MOD + z) % MOD;
    }
    for (int i = 1; i <= n; ++i) {
      arr[i] = (b[i] % (r - l + 1)) + l;
    }

    Long res = LLONG_MAX;
    Long mx_pos = LLONG_MIN, mx_neg = LLONG_MIN;
    for (int i = n; i >= 1; --i) {
      if (arr[i] < mx_pos) {
        res = min(res, arr[i] * mx_pos);
      }
      if (arr[i] < mx_neg) {
        res = min(res, arr[i] * mx_neg);
      }
      if (arr[i] >= 0) {
        mx_pos = max(mx_pos, arr[i]);
      }
      if (arr[i] <= 0) {
        mx_neg = max(mx_neg, arr[i]);
      }
    }
    Long mn_pos = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
      if (mn_pos < arr[i]) {
        res = min(res, arr[i] * mn_pos);
      }
      if (arr[i] >= 0) {
        mn_pos = min(mn_pos, arr[i]);
      }
    }

    if (res == LLONG_MAX) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << res << endl;
    }
  }

}