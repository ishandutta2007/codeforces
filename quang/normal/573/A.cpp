#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int g;

bool check(int u) {
  while (u % 2 == 0) {
    u /= 2;
  }
  while (u % 3 == 0) {
    u /= 3;
  }
  return u == 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  g = a[1];
  for (int i = 2; i <= n; i++) {
    g = __gcd(g, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    a[i] /= g;
  }
  for (int i = 1; i <= n; i++) {
    if (!check(a[i])) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}