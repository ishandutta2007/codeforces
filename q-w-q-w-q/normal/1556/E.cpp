#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int n, q, a[N];
ll s[N];
ll d[20][N], dm[20][N];
inline ll query(int l, int r) {
  int k = __lg(r - l + 1);
  return min(d[k][l], d[k][r - (1 << k) + 1]);
}
inline ll querym(int l, int r) {
  int k = __lg(r - l + 1);
  return max(dm[k][l], dm[k][r - (1 << k) + 1]);
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[i] -= x;
    s[i] = s[i - 1] + a[i];
    d[0][i] = s[i];
    dm[0][i] = s[i];
  }
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) d[j][i] = min(d[j - 1][i], d[j - 1][i + (1 << (j - 1))]);
  for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) dm[j][i] = max(dm[j - 1][i], dm[j - 1][i + (1 << (j - 1))]);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (s[r] != s[l - 1] || querym(l, r) > s[l - 1]) {
      cout << -1 << endl;
      continue;
    }
    cout << s[l - 1] - query(l, r) << endl;
  }
}