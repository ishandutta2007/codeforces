#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  cout << n + m - min(n, m) - 1 << " " << min(n, m) << endl;
  return 0;
}