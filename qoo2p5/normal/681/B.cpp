#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  const int A = 1234567;
  const int B = 123456;
  const int C = 1234;
  
  int n;
  cin >> n;
  bool ans = false;
  
  for (int a = 0; a * A <= n; a++) {
    for (int b = 0; a * A + b * B <= n; b++) {
      int c = (n - a * A - b * B) / C;
      if (a * A + b * B + c * C == n) ans = true;
    }
  }
  
  cout << (ans ? "YES" : "NO") << "\n";
  
  return 0;
}