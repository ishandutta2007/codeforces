#include <bits/stdc++.h>

using namespace std;

int get(long long x) {
    if (x < 4) return 0;
    if (x < 16) return 1;
    if (x < 82) return 2;
    if (x < 6724) return 0;
    if (x < 50626) return 3;
    if (x < 2562991876LL) return 1;
    return 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    long long u;
    cin >> u;
    tot ^= get(u);
  }
  cout << (tot ? "Furlo" : "Rublo");
  return 0;
}