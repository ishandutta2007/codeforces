#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) {
    cin >> a;
  }
  vector<int> B(N);
  for (auto &a : B) {
    cin >> a;
  }
  vector<int> s, t;
  for (int i = 0; i < N; i++) {
    (A[i] ? s : t).emplace_back(B[i]);
  }
  sort(begin(s), end(s));
  sort(begin(t), end(t));
  lint ans = 0;
  int sz = min(s.size(), t.size());
  reverse(begin(s), end(s));
  reverse(begin(t), end(t));
  for (int i = 0; i < int(s.size()); i++) {
    ans += s[i];
    if (i < sz) ans += s[i];
  }
  for (int i = 0; i < int(t.size()); i++) {
    ans += t[i];
    if (i < sz) ans += t[i];
  }
  if (s.size() == t.size()) {
    ans -= *min_element(begin(B), end(B));
  }
  cout << ans << '\n';
  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}