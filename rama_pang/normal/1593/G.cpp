#include <bits/stdc++.h>
using namespace std;

void Main() {
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  int N = S.size();
  vector<int> p0(N + 1), p1(N + 1);
  for (int i = 0; i < N; i++) {
    p0[i + 1] = p0[i] + (i % 2 == 0 && (S[i] == '[' || S[i] == ']'));
    p1[i + 1] = p1[i] + (i % 2 == 1 && (S[i] == '[' || S[i] == ']'));
  }
  while (Q--) {
    int l, r;
    cin >> l >> r;
    int o = p0[r] - p0[l - 1];
    int e = p1[r] - p1[l - 1];
    cout << max(o, e) - min(o, e) << '\n';
  }
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