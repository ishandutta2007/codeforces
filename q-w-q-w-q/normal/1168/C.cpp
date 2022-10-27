#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 300005;
int n, q, a[N];
int f[N][19];

void dp() {
  memset(f, 0x3f, sizeof f);

  int nw[19] = {1 << 30};
  for (int i = n; i; i--) {
    for (int j = 0; j < 19; j++)
      if (a[i] >> j & 1) {
        if (nw[j] <= n) {
          for (int k = 0; k < 19; k++)
            f[i][k] = min(f[i][k], f[nw[j]][k]);
        }
        nw[j] = i, f[i][j] = i;
      }
  }
}

bool reachable(int x, int y) {
  for (int i = 0; i < 19; i++)
    if ((a[y] >> i & 1) && f[x][i] <= y)
      return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  dp();

  while (q--) {
    int x, y;
    cin >> x >> y;
    if (reachable(x, y))
      cout << "Shi\n";
    else
      cout << "Fou\n";
  }
}