#include <bits/stdc++.h>

using namespace std;

int a, b, n;
int L, t, m;

long long solve(int u) {
  long long res = 1ll * a * u;
  res += 1ll * b * u * (u - 1) / 2;
  return res;
}

bool check(int u) {
  long long sum, h;
  h = 1ll * b * (u - 1) + a;
  if (t < h) return 0;
  sum = solve(u) - solve(L - 1);
  return (sum <= 1ll * min(m, u - L + 1) * t);
}

int main() {
 // freopen("inp.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin >> a >> b >> n;
  for (int i = 1; i <= n; i++) {
    cin >> L >> t >> m;
    int l = L, r = 1000005;
    while (r - l > 1) {
      int mi = (l + r) >> 1;
      if (check(mi)) {
        l = mi;
      } else {
        r = mi;
      }
    }
    if (!check(l)) {
      cout << -1 << endl;
    } else {
      cout << l << endl;
    }
  }
  return 0;
}