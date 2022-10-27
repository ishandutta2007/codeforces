#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
int a[1001][1001], ans[1001][1001];
char s[100001];
struct p {
  int x, v;
} x, y, z;
inline int ad(int x) { return (x + 1) % n; }
inline int sb(int x) { return (x + n - 1) % n; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", a[i] + j);
    scanf("%s", s + 1);
    x.x = 0, y.x = 1, z.x = 2, x.v = y.v = z.v = 0;
    for (int i = 1; i <= m; i++) {
      if (s[i] == 'R') y.v = ad(y.v);
      if (s[i] == 'L') y.v = sb(y.v);
      if (s[i] == 'D') x.v = ad(x.v);
      if (s[i] == 'U') x.v = sb(x.v);
      if (s[i] == 'I') swap(y, z);
      if (s[i] == 'C') swap(x, z);
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        int b[3] = {i, j, a[i][j] - 1};
        ans[(b[x.x] + x.v) % n][(b[y.x] + y.v) % n] = (b[z.x] + z.v) % n;
      }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        printf("%d%c", ans[i][j] + 1, " \n"[j == n - 1]);
    cout << endl;
  }
}