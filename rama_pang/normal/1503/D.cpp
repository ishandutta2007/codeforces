#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i]; 
    A[i]--; B[i]--;
  }
  vector<int> ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) { return min(A[i], B[i]) < min(A[j], B[j]); });
  for (int i = 0; i < N; i++) {
    if (min(A[ord[i]], B[ord[i]]) != i) {
      cout << -1 << '\n';
      return;
    }
  }

  // Numbers < N must occupy prefix of increasing sequence + suffix of decreasing sequence.
  // So they must be in different cards.

  // Sort the cards by their number < N.
  // We need to split the cards into 2 decreasing subsequences: 1 for increasing, 1 for decreasing

  // If we split the subsequence into segments, s.t.
  // min(segment[i]) > max(segment[i + 1])
  // Then each segment is independent of the other.
  // Also, each segment has exactly 1 way of splitting.
  // Choose the way which minimizes flips.

  vector<int> suff(N);
  for (int i = N - 1; i >= 0; i--) {
    suff[ord[i]] = max(A[ord[i]], B[ord[i]]);
    if (i + 1 < N) suff[ord[i]] = max(suff[ord[i]], suff[ord[i + 1]]);
  }

  int ans = 0;

  const auto Solve = [&](vector<int> C) -> int {
    if (C.empty()) return 0;
    int cnt = 0;
    int last1 = 1e9;
    int last2 = 1e9;
    for (auto i : C) {
      if (last1 > max(A[i], B[i])) {
        last1 = max(A[i], B[i]);
        cnt += A[i] < B[i];
      } else if (last2 > max(A[i], B[i])) {
        last2 = max(A[i], B[i]);
        cnt += A[i] > B[i];
      } else {
        cout << -1 << '\n';
        exit(0);
      }
    }
    return min(cnt, int(C.size()) - cnt);
  };

  int current_min = 1e9;
  vector<int> current;
  for (auto i : ord) {
    if (current_min > suff[i]) {
      ans += Solve(current);
      current = {i};
      current_min = max(A[i], B[i]);
    } else {
      current.emplace_back(i);
      current_min = min(current_min, max(A[i], B[i]));
    }
  }
  ans += Solve(current);

  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}