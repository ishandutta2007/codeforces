#include <bits/stdc++.h>

using namespace std;

long long n;
long long a[100000];

int main() {
  cin >> n;
  a[0] = 1;
  a[1] = 2;
  for (int i = 2; i <= 100; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  for (int i = 0; i <= 100; i++) {
    if (a[i] > n) {
      cout << i - 1 << endl;
      return 0;
    }
  }
  return 0;
}