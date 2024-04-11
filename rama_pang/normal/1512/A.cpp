#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  map<int, int> f;
  for (auto i : a) f[i]++;
  int x;
  for (auto i : f) if (i.second == 1) x = i.first;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      cout << i + 1 << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}