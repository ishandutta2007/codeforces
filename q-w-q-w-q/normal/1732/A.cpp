// LUOGU_RID: 91280282
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 20;
int n, f[N][N];

int gcd(int n, int m) { return !m ? n : gcd(m, n % m); }

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int d = 0;
    for (int i = 0, x; i != n; i++)
      cin >> x, d = gcd(d, x);
    if (d == 1) {
      cout << "0\n";
      continue;
    }
    if (gcd(d, n) == 1) {
      cout << "1\n";
      continue;
    }
    if (gcd(d, n - 1) == 1) {
      cout << "2\n";
      continue;
    }
    cout << "3\n";
  }
}