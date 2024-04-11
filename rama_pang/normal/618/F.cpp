#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }

  bool swapped = false;
  if (accumulate(begin(A), end(A), 0ll) < accumulate(begin(B), end(B), 0ll)) {
    swap(A, B);
    swapped = true;
  }

  vector<int> ansA, ansB;
  long long sumA = accumulate(begin(A), end(A), 0ll);
  long long sumB = accumulate(begin(B), end(B), 0ll);

  // vector<pair<int, int>>;
  vector<pair<int, int>> last(N, {-1, -1});
  for (int i = N - 1; i >= 0; i--) {
    while (sumA - A.back() >= sumB) {
      sumA -= A.back();
      A.pop_back();
    }
    if (sumA == sumB) {
      for (int j = 0; j < (int) A.size(); j++) {
        ansA.emplace_back(j);
      }
      for (int j = 0; j <= i; j++) {
        ansB.emplace_back(j);
      }
      break;
    }
    assert(1 <= sumA - sumB && sumA - sumB < N);
    if (last[sumA - sumB] == pair(-1, -1)) {
      last[sumA - sumB] = {int(A.size()) - 1, i};
    } else {
      for (int j = A.size(); j <= last[sumA - sumB].first; j++) {
        ansA.emplace_back(j);
      }
      for (int j = i + 1; j <= last[sumA - sumB].second; j++) {
        ansB.emplace_back(j);
      }
      break;
    }
    sumB -= B[i];
  }
  if (swapped) {
    swap(ansA, ansB);
  }
  for (const auto &ans : {ansA, ansB}) {
    cout << ans.size() << '\n';
    for (auto i : ans) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}