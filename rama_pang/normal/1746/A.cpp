#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  if (accumulate(begin(a), end(a), 0) == 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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
}