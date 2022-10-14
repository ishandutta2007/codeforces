#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> arr;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      if (a[i] != i) {
        if (arr.empty() || arr.back() + 1 != i) {
          arr.emplace_back(i);
        } else {
          arr.back() = i;
        }
      }
    }
    cout << min((int) arr.size(), 2) << "\n";
  } 
}