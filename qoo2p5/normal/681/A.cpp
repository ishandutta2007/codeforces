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
  
  bool ans = false;
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int b, a;
    cin >> b >> a;
    if (a - b > 0 && b >= 2400) ans = true;
  }
  
  cout << (ans ? "YES" : "NO") << "\n";
  
  return 0;
}