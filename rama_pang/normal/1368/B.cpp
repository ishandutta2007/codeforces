#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string cf = "codeforces";
  lint n;
  cin >> n;
  vector<lint> cnt(cf.size(), 1);
  while (true) {
    lint cur = 1;
    for (auto i : cnt) cur *= i;
    if (cur >= n) {
      break;
    }
    int mn = min_element(begin(cnt), end(cnt)) - begin(cnt);
    cnt[mn]++;
  }
  for (int i = 0; i < cnt.size(); i++) {
    for (int j = 0; j < cnt[i]; j++) {
      cout << cf[i];
    }
  }
  cout << "\n";

}