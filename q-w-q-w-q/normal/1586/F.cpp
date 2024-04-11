#include <cstdio>
#include <iostream>

using namespace std;

int ans[1001][1001];
int n, k;

void work(int l, int r, int d) {
  if (r - l + 1 <= k) {
    for (int i = l; i <= r; i++)
      for (int j = i + 1; j <= r; j++)
        ans[i][j] = d;
    return;
  }

  int tp = (r - l + 1) / k, g = (r - l + 1) % k;
  int nl = l;
  for (int i = 1; i <= k; i++) {
    int nr = nl + tp - 1;
    if (i <= g) nr++;
    work(nl, nr, d + 1);
    for (int j = nl; j <= nr; j++)
      for (int k = nr + 1; k <= r; k++)
        ans[j][k] = d;
    nl = nr + 1;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> k;
  int tp = 1, c = 0;
  while (tp < n) tp *= k, c++;
  cout << c << endl;

  work(1, n, 1);

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      cout << ans[i][j] << ' ';
}