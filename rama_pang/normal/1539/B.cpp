#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;
  vector<int> A;
  string s;
  cin >> s;
  for (auto i : s) {
    A.emplace_back(i - 'a' + 1);
  }
  for (int i = 1; i < N; i++) {
    A[i] += A[i - 1];
  }
  while (Q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << (A[r] - (l > 0 ? A[l - 1] : 0)) << '\n';
  }
  return 0;
}