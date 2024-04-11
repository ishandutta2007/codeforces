#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(3);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= 3;
      c[a[i]]++;
    }
    int ans = 0;
    int need = n / 3;
    while (c[0] > need) {
      c[1]++;
      c[0]--;
      ans++;
    }
    while (c[1] > need) {
      c[2]++;
      c[1]--;
      ans++;
    }
    while (c[2] > need) {
      c[0]++;
      c[2]--;
      ans++;
    }
    while (c[0] > need) {
      c[1]++;
      c[0]--;
      ans++;
    }
    while (c[1] > need) {
      c[2]++;
      c[1]--;
      ans++;
    }
    while (c[2] > need) {
      c[0]++;
      c[2]--;
      ans++;
    }
    while (c[0] > need) {
      c[1]++;
      c[0]--;
      ans++;
    }
    while (c[1] > need) {
      c[2]++;
      c[1]--;
      ans++;
    }
    while (c[2] > need) {
      c[0]++;
      c[2]--;
      ans++;
    }
    while (c[0] > need) {
      c[1]++;
      c[0]--;
      ans++;
    }
    while (c[1] > need) {
      c[2]++;
      c[1]--;
      ans++;
    }
    while (c[2] > need) {
      c[0]++;
      c[2]--;
      ans++;
    }
    while (c[0] > need) {
      c[1]++;
      c[0]--;
      ans++;
    }
    while (c[1] > need) {
      c[2]++;
      c[1]--;
      ans++;
    }
    while (c[2] > need) {
      c[0]++;
      c[2]--;
      ans++;
    }
    while (c[0] > need) {
      c[1]++;
      c[0]--;
      ans++;
    }
    while (c[1] > need) {
      c[2]++;
      c[1]--;
      ans++;
    }
    while (c[2] > need) {
      c[0]++;
      c[2]--;
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}