#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int o = 19, N = 1 << o;
int n, a[N], b[N];

void fmt(int *a, int n) {
  for (int l = 1; l != n; l <<= 1)
    for (int i = 0; i != n; i += 2 * l)
      for (int j = 0; j != l; j++)
        a[i + l + j] ^= a[i + j];
}

void solve(int n, int m, int *a, int *b) {
  static int c[N];
  if (!m) {
    memcpy(b, a, n << 2);
    fmt(b, n);
    return;
  }
  if (m == n) {
    memcpy(a, b, n << 2);
    fmt(a, n);
    return;
  }

  bool op = 0;
  if (m * 2 > n)
    swap(a, b), op = 1, m = n - m;
  memcpy(c + n / 2, a + n / 2, n << 1);
  fmt(c + n / 2, n / 2);
  for (int i = 1; i <= m; i++)
    b[n / 2 - i] = b[n - i] ^ c[n - i];
  solve(n / 2, m, a, b);
  for (int i = m + 1; i <= n / 2; i++)
    b[n - i] = b[n / 2 - i] ^ c[n - i];
  if (op)
    swap(a, b);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  if (n == 1) {
    int x;
    cin >> x;
    cout << x << '\n';
    return 0;
  }

  int t = __lg(n - 1) + 1, m = 1 << t;
  for (int i = 1; i <= n; i++)
    cin >> a[m - i];
  solve(m, m - n, a, b);

  for (int i = n - 1; i != -1; i--)
    cout << b[i] << " \n"[!i];
}

//mod mwr