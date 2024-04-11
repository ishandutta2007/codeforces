#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 16005;
char a[805], b[805];
int n, l1, l2;
int cnt, ch[N][10], v[N][2005], f[2005][N];
int fail[N];
inline int newnode(int x, int c) { return ch[x][c] ? ch[x][c] : ch[x][c] = ++cnt; }
void buildtrie() {
  if (l1 != l2) {
    for (int k = l1 + 1; k < l2; k++)
      for (int i = 1; i < 10; i++) {
        int x = newnode(0, i);
        v[x][k - 1]++;
      }
    for (int i = 1, x = 0; i <= l1; x = newnode(x, a[i++] - '0'))
      for (int j = a[i] - '0' + (i < l1); j < 10; j++) v[newnode(x, j)][l1 - i]++;
    for (int i = 1, x = 0; i <= l2; x = newnode(x, b[i++] - '0'))
      for (int j = b[i] - '0' - (i < l2); j > (i > 1 ? -1 : 0); j--) v[newnode(x, j)][l2 - i]++;
  } else {
    int p, x;
    for (p = 1, x = 0; p <= l1 && a[p] == b[p]; p++) x = newnode(x, a[p] - '0');
    if (p > l1)
      v[x][0]++;
    else {
      int o1 = a[p] - '0', o2 = b[p] - '0';
      for (int i = o1 + 1; i < o2; i++) v[newnode(x, i)][l1 - p]++;
      if (p == l1)
        v[newnode(x, o1)][0]++, v[newnode(x, o2)][0]++;
      else {
        for (int i = p + 1, y = newnode(x, o1); i <= l1; y = newnode(y, a[i++] - '0'))
          for (int j = a[i] - '0' + (i < l1); j < 10; j++) v[newnode(y, j)][l1 - i]++;
        for (int i = p + 1, y = newnode(x, o2); i <= l2; y = newnode(y, b[i++] - '0'))
          for (int j = b[i] - '0' - (i < l2); ~j; j--) v[newnode(y, j)][l2 - i]++;
      }
    }
  }
}
void buildacam() {
  static int q[N], h, t;
  for (int i = 0; i < 10; i++)
    if (ch[0][i]) q[++t] = ch[0][i];
  while (h < t) {
    int x = q[++h];
    for (int i = 1; i <= n; i++) v[x][i] += v[x][i - 1];
    for (int i = 0; i <= n; i++) v[x][i] += v[fail[x]][i];
    for (int i = 0; i < 10; i++)
      if (ch[x][i]) {
        q[++t] = ch[x][i];
        fail[ch[x][i]] = ch[fail[x]][i];
      } else
        ch[x][i] = ch[fail[x]][i];
  }
}
void dp() {
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= cnt; j++)
      for (int k = 0; k < 10; k++) f[i][j] = max(f[i][j], f[i - 1][ch[j][k]] + v[ch[j][k]][i - 1]);
}
void output() {
  cout << f[n][0] << endl;
  for (int i = n, x = 0; i; i--)
    for (int j = 0; j < 10; j++)
      if (f[i][x] == f[i - 1][ch[x][j]] + v[ch[x][j]][i - 1]) {
        putchar(j + '0'), x = ch[x][j];
        break;
      }
}
int main() {
  scanf("%s%s%d", a + 1, b + 1, &n);
  l1 = strlen(a + 1), l2 = strlen(b + 1);
  buildtrie(), buildacam();
  dp(), output();
}