#include <bits/stdc++.h>

using namespace std;

long long q;
map<long long, long long> a;

long long get(long long u) {
  if (a.count(u)) {
    return a[u];
  }
  long long x = -1;
  int f = 0;
  for (int i = 2; 1ll * i * i <= u; i++) {
    if (u % i == 0) {
      f = 1;
      if (get(i) < 0) {
        x = i;
        break;
      }
      if (get(u / i) < 0) {
        x = u / i;
        break;
      }
    }
  }
  if (!f) {
    return (a[u] = 0);
  }
  return (a[u] = x);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> q;
  long long x = get(q);
  if (x < 0) {
    cout << 2 << endl;
  } else {
    cout << 1 << "\n" << x << endl;
  }
  return 0;
}