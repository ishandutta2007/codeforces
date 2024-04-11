#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    sort(begin(a), end(a));
    a.resize(unique(begin(a), end(a)) - begin(a));
    cout << a.size() << "\n";
  }
}