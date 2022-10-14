#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, l, r, s;
  cin >> n >> l >> r >> s;
  int m = r - l + 1;
  int lb = 0, rb = 0;
  for (int i = 0; i < m; i++) {
    lb += i + 1;
    rb += n - i;
  }
  if (s < lb || rb < s) {
    cout << -1 << '\n';
    return;
  }
  vector<int> cur;
  for (int i = 0; i < m; i++) {
    cur.emplace_back(i + 1);
  }
  while (lb < s) {
    lb += 1;
    int done = 0;
    for (int i = 0; i < m; i++) {
      if (cur[m - i - 1] + 1 <= n - i) {
        cur[m - i - 1] += 1;
        done = 1;
        break;
      }
    }
    assert(done);
  }
  assert(lb == s);
  vector<int> other;
  sort(begin(cur), end(cur));
  for (int i = 1; i <= n; i++) {
    if (!binary_search(begin(cur), end(cur), i)) {
      other.emplace_back(i);
    }
  }
  for (int i = 1; i < l; i++) {
    cout << other.back() << ' ';
    other.pop_back();
  }
  for (int i = l; i <= r; i++) {
    cout << cur.back() << ' ';
    cur.pop_back();
  }
  for (int i = r + 1; i <= n; i++) {
    cout << other.back() << ' ';
    other.pop_back();
  }
  assert(cur.empty() && other.empty());
  cout << '\n';
  return;
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