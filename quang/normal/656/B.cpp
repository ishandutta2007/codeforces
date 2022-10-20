#include <bits/stdc++.h>

using namespace std;

const int N = 16;

int n;
int a[N], b[N];

int lcm(int u, int v) {
  int w = __gcd(u, v);
  u /= w;
  return u * v;
}

int main() {
  cin >> n;
  int sum = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum = lcm(sum, a[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int res = 0;
  for (int i = 0; i < sum; i++) {
    int f = 0;
    for (int j = 0; j < n; j++) {
      if (i % a[j] == b[j]) {
        f = 1;
        break;
      }
    }
    res += f;
  }
  printf("%0.17f", (double)res / (double) sum);
  return 0;
}