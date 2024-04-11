#include <bits/stdc++.h>

using namespace std;

const int N = 710010;

// 1-indexed
// Can't add when x = 0
template<typename T = int>
struct BIT {
  int n;
  vector<T> t;

  BIT(int n = 0) : n(n), t(n + 1, 0) {}

  void Add(int x, T v) {
    for (; x <= n; x += x & -x) t[x] += v;
  }

  T Get(int x) {
    T res = 0;
    for (; x; x -= x & -x) res += t[x];
    return res;
  }

  T Get(int l, int r) {
    return Get(r) - (l ? Get(l - 1) : 0);
  }
};

int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  BIT<long long> t(N);
  BIT<long long> num(N);
  BIT<long long> sum(N);
  long long cur = 0;
  for (int i = 1; i <= n; i++) {
    long long foo = 1ll * (i - 1) * a[i] - t.Get(a[i]);
    long long bar = 0;
    for (int j = 0; j + a[i] < N; j += a[i]) {
      bar += sum.Get(j, j + a[i] - 1) - num.Get(j, j + a[i] - 1) * j;
    }
    cur += foo + bar;

    for (int j = a[i]; j < N; j += a[i]) {
      t.Add(j, a[i]);
    }
    sum.Add(a[i], a[i]);
    num.Add(a[i], 1);
    cout << cur << ' ';
  }
  cout << '\n';
  return 0;
}