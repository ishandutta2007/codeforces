#include <bits/stdc++.h>

using namespace std;

bool go(long long u, long long v) {
  if (u == 0) {
    return 0;
  }
  if (!go(v % u, u)) {
    return 1;
  }
  v /= u;
  if (u & 1) {
    return v % 2 == 0;
  }
  return (v % (u + 1)) % 2 == 0;
}

int main() {
  int tc;
  ios_base::sync_with_stdio(0);
  cin >> tc;
  while (tc--) {
    long long u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    if (go(u, v)) {
      puts("First");
    } else {
      puts("Second");
    }
  }
  return 0;
}