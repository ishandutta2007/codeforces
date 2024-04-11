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
    vector<int> a(2 * n);
    for (int i = 0; i < n; i++) {
      cin >> a[i * 2];
    }
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
      freq[a[i * 2]]++;
    }
    bool can = true;
    for (auto &i : freq) {
      if (i.second > 1) {
        can = false;
      }
      if (i.first > 2 * n || i.first < 1) {
        can = false;
      }
    }
    if (!can) {
      cout << -1 << "\n";
      continue;
    }
    set<int> unused;
    for (int i = 1; i <= 2 * n; i++) if (freq[i] == 0) {
      for (int j = 1; j < 2 * n; j += 2) {
        if (a[j] == 0 && a[j - 1] < i) {
          a[j] = i;
          break;
        }
      } 
    }
    for (int i = 0; i < 2 * n; i++) {
      if (a[i] == 0) {
        can = false;
        break;
      }
    }
    if (!can) {
      cout << -1 << "\n";
      continue;
    }

    for (int i = 0; i < 2 * n; i++) {
      cout << a[i] << " \n"[i == 2 * n - 1];
    }
  }
}