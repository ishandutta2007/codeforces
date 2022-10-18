#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int s;
  cin >> s;
  int last = -1;
  int n = 0;
  while (s) {
    last += 2;
    s -= min(s, last);
    n++;
  }
  cout << n << '\n';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}