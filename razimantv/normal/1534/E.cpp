// Bad practice, just doing this for competitive programming!
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  if ((N & 1) and !(K & 1)) {
    cout << -1 << "\n";
    return 0;
  }

  int M = (N + K - 1) / K, X = 1, tot = M * K;
  while(1) {
    if (tot - X * N >= 2 * N) X += 2;
    if ((tot - X * N) & 1) {
      tot = K * ++M;
      continue;
    }
    if (X + 2 <= M or (tot == X * N and X <= M)) break;
    tot = K * ++M;
  }
  int A = (tot - X * N) / 2;

  vector<vector<int>> ask(M);
  for (int i = 1; i <= N; ++i) {
    int c = X + ((i <= A) ? 2 : 0);
    for (int j = 0; j < c; ++j) ask[--tot % M].push_back(i);
  }

  int ret = 0;
  for(auto& v: ask) {
    cout << "?";
    for(int x:v) cout << " " << x;
    cout << endl;

    int q;
    cin >> q;
    ret ^= q;
  }
  cout << "! " << ret << "\n";
  return 0;
}