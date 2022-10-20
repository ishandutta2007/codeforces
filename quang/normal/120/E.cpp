#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (n % 2 == 0) << endl;
  }
  return 0;
}