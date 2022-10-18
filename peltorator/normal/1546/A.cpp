#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &i : a) {
    cin >> i;
  }
  for (int &i : b) {
    cin >> i;
  }
  if (accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0)) {
    cout << "-1\n";
    return;
  }
  queue<int> neg, pos;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      neg.push(i);
    } else if (a[i] > b[i]) {
      pos.push(i);
    }
  }
  vector<pair<int, int>> ans;
  while (!pos.empty()) {
    int i = pos.front();
    int j = neg.front();
    a[i]--;
    a[j]++;
    if (a[i] == b[i]) {
      pos.pop();
    }
    if (a[j] == b[j]) {
      neg.pop();
    }
    ans.push_back({i, j});
  }
  cout << (int)ans.size() << '\n';
  for (auto [i, j] : ans) {
    cout << i + 1 << ' ' << j + 1 << '\n';
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}