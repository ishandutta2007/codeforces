#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<string> A(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    R[i] = A[i];
    reverse(begin(R[i]), end(R[i]));
  }
  vector<int> done(N, 0);
  string ans;
  string palin;
  while (true) {
    bool changed = false;
    for (int i = 0; i < N; i++) {
      if (done[i]) {
        continue;
      }
      for (int j = i + 1; j < N; j++) {
        if (done[j]) {
          continue;
        }
        if (A[i] == R[j]) {
          done[i] = 1;
          done[j] = 1;
          ans.append(A[i]);
          changed = true;
          goto RELOOP;
        }
      }
    }
    RELOOP:
    if (!changed) {
      break;
    }
  }
  for (int i = 0; i < N; i++) {
    if (done[i]) {
      continue;
    }
    if (A[i] == R[i]) {
      palin = A[i];
      break;
    }
  }

  cout << ans.size() * 2 + palin.size() << "\n";
  cout << ans << palin << string(ans.rbegin(), ans.rend()) << "\n";

}