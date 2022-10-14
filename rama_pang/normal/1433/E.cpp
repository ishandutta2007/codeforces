#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int cnt = 0;
  long long ways = 1;
  for (int i = 1; i < n / 2; i++) {
    ways *= i;
  }
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) == (n / 2)) {
      cnt++;
    }
  }
  cout << 1ll * cnt * ways * ways / 2 << "\n";
  return 0; 
}