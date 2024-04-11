#include <bits/stdc++.h>
using namespace std;
using lint = long long;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a) {
      cin >> i;
    }
    for (auto &i : b) {
      cin >> i;
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));

    for (auto &i : a) {
      cout << i << " ";
    }
    cout << "\n";
    for (auto &i : b) {
      cout << i << " ";
    }
    cout << "\n";
    

  }


}