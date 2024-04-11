#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    deque<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    while (a.front() == 0) {
      a.pop_front();
    }
    while (a.back() == 0) {
      a.pop_back();
    }
    cout << int(a.size()) - accumulate(begin(a), end(a), 0) << "\n";
  }
  return 0; 
}