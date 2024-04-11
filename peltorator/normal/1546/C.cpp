#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  valarray<int> a(n);
  for (int& i : a) {
    cin >> i;
  }
  auto even = slice(0, (n + 1) / 2, 2);
  auto odd = slice(1, n / 2, 2);
  valarray<int> b = a[even];
  valarray<int> c = a[odd];
  sort(begin(b), end(b));
  sort(begin(c), end(c));
  a[even] = b;
  a[odd] = c;
  cout << (is_sorted(begin(a), end(a)) ? "YES\n" : "NO\n");
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}