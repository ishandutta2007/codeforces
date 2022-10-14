#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  lint sum = 0;
  lint p = 0, ne = 0;
  vector<int> pos, neg, zer;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] > 0) {
      pos.emplace_back(a[i]);
      p += a[i];
    } else if (a[i] < 0) {
      neg.emplace_back(a[i]);
      ne += -a[i];
    } else {
      zer.emplace_back(a[i]);
    }
  }
  if (sum == 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  sort(begin(neg), end(neg));
  sort(begin(pos), end(pos));
  reverse(begin(pos), end(pos));
  if (p > ne) {
    for (auto i : pos) cout << i << " ";
    for (auto i : neg) cout << i << " ";
  } else {
    for (auto i : neg) cout << i << " ";
    for (auto i : pos) cout << i << " ";
  }
  for (auto i : zer) cout << i << " ";
  cout << "\n";
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