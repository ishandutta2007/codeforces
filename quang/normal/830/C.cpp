#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = 32000;

int n;
long long k;
int a[N];
int b[N * M * 2], cnt;

long long getSum(long long u) {
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    long long foo = a[i] % u;
    if (!foo) {
      continue;
    }
    res += u - foo;
  }
  return res;
}

long long get(long long u, long long v) {
  long long low = u - 1;
  long long high = v;
  while (high - low > 1) {
    long long mid = (low + high) >> 1ll;
    long long sum = getSum(mid);
    if (sum <= k) {
      low = mid;
    } else {
      high = mid;
    }
  }
  if (low == u - 1) {
    return -1;
  }
  return low;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j <= sqrt(a[i] - 1) + 1; j++) {
      int foo = (a[i] - 1) / j + 1;
      b[++cnt] = foo;
      b[++cnt] = j;
    }
  }
  sort(b + 1, b + cnt + 1);
  int sz = unique(b + 1, b + cnt + 1) - b - 1;
  long long res = 1;
  for (int i = 1; i < sz; i++) {
    res = max(res, get(b[i], b[i + 1]));
  }
  res = max(res, get(b[sz], (1ll << 40)));
  cout << res << endl;
  return 0;
}