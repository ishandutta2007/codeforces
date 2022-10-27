#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

const int N = 150005;
int n, b[N];
i64 a[N];
bool ok[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> b[i];

  bool o = 0;
  for (int i = 1; i < n; i++)
    if (b[i] != b[i - 1])
      o = 1;
  if (!o) {
    if (b[0] != 0) {
      cout << "NO";
      return 0;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++)
      cout << 1 << " \n"[i == n];
    return 0;
  }

  for (int i = 0; i < n; i++)
    if (b[i] >= b[(i + 1) % n])
      ok[(i + 1) % n] = 1;

  for (int i = 0; i < n; i++)
    if (!ok[i]) {
      a[i] = max(b[(i + n - 1) % n] + 1, b[i]);
      for (int j = (i + n - 1) % n; ok[j]; j = (j + n - 1) % n) {
        a[j] = a[(j + 1) % n] + b[j];
        if (a[j] <= b[(j + n - 1) % n]) {
          a[j] = b[(j + n - 1) % n] + 1;
          i64 mod = a[(j + 1) % n];
          a[j] += (b[j] + mod - a[j] % mod) % mod;
        }
      }
    }

  cout << "YES\n";
  for (int i = 0; i < n; i++)
    cout << a[i] << " \n"[i == n - 1];
}