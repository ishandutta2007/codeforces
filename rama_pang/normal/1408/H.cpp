#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    int zero = 0;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      zero += A[i] == 0;
    }

    int ans = 0;
    vector<int> L(N), R(N);
    for (int i = 0, z = 0; i < N; i++) {
      z += A[i] == 0;
      if (A[i] > 0) {
        if (z < zero - z) {
          L[A[i] - 1] = max(L[A[i] - 1], z);
        } else {
          R[A[i] - 1] = max(R[A[i] - 1], zero - z);
        }
      }
    }

    vector<vector<int>> todo(zero + 1);
    for (int i = 0; i < N; i++) {
      todo[L[i]].emplace_back(R[i]);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = zero; i >= 0; i--) { // iterate forward
      for (auto j : todo[i]) {
        pq.emplace(j);
      }
      if (i > 0 && !pq.empty()) {
        pq.pop();
        ans += 1;
      }
    }
    for (int i = 1; i <= zero; i++) {
      while (!pq.empty() && pq.top() < i) { // iterate backward
        pq.pop();
      }
      if (!pq.empty()) {
        pq.pop();
        ans += 1;
      }
    }

    cout << min(ans, zero / 2) << "\n";
  }
  return 0;
}