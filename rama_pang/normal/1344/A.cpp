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
    for (auto &i : a) cin >> i;

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[((i + a[i]) % n + n) % n]++;
    }
    int l = begin(cnt)->first;
    int r = rbegin(cnt)->first;
    int can = 1;
    for (auto i : cnt) {
      if (i.second > 1) {
        can = 0;
      }
    }
    if (r - l + 1 > n) can = 0;
    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }


}