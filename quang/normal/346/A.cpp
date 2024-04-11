#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int foo = a[1], m = a[1];
  for (int i = 2; i <= n; i++) {
    foo = __gcd(foo, a[i]);
    m = max(m, a[i]);
  }
  int cnt = m / foo - n;
  if (cnt & 1) {
    cout << "Alice";
  } else {
    cout << "Bob";
  }
  return 0;
}