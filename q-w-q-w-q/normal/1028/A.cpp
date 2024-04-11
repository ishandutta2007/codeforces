#include <cstdio>
#include <iostream>

using namespace std;

const int N = 205;
int n, m;
bool c[N], r[N];
char a[N][N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> (a[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 'B')
        r[i] = c[j] = 1;
  int rr, cc;
  for (int i = 1; i <= n; i++)
    if (r[i]) {
      int j;
      for (j = i; j <= n && r[j]; j++)
        ;
      j--;
      rr = (i + j) / 2;
      break;
    }
  for (int i = 1; i <= m; i++)
    if (c[i]) {
      int j;
      for (j = i; j <= m && c[j]; j++)
        ;
      j--;
      cc = (i + j) / 2;
      break;
    }
  cout << rr << ' ' << cc;
}