#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
long long a[N];
pair<int, int> b[N];

int get(long long u) {
  int it = lower_bound(a + 1, a + m + 1, u) - a;
  if (!b[it].second) {
    return b[it].first;
  }
  long long x = u - a[it - 1];
  return get((x - 1) % b[it].first + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int e;
    cin >> e;
    if (e == 1) {
      int x;
      cin >> x;
      b[i] = make_pair(x, 0);
      a[i] = a[i - 1] + 1;
    } else {
      int l, c;
      cin >> l >> c;
      b[i] = make_pair(l, c);
      a[i] = a[i - 1] + 1ll * l * c;
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long u;
    cin >> u;
    cout << get(u) << " ";
  }
  return 0;
}