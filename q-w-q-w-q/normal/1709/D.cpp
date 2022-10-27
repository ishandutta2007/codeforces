#include <cstdio>
#include <iostream>

using namespace std;

const int N = 200005;
int n, m;
int d[18][N];

int query(int l, int r) {
  int k = __lg(r - l + 1);
  return max(d[k][l], d[k][r - (1 << k) + 1]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++)
    cin >> d[0][i];
  for (int j = 1; (1 << j) <= m; j++)
    for (int i = 1; i + (1 << j) - 1 <= m; i++)
      d[j][i] = max(d[j - 1][i], d[j - 1][i + (1 << (j - 1))]);

  int q;
  cin >> q;
  while (q--) {
    int xs, ys, xf, yf, k;
    cin >> xs >> ys >> xf >> yf >> k;
    if (ys > yf)
      swap(xs, xf), swap(ys, yf);
    if (xs % k != xf % k || ys % k != yf % k) {
      cout << "NO\n";
      continue;
    }
    xs += (n - xs) / k * k;
    if (query(ys, yf) >= xs)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}