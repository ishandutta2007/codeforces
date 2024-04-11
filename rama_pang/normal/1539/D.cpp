#include <bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  lint N;
  cin >> N;
  deque<pair<lint, lint>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].second >> A[i].first;
  }
  sort(begin(A), end(A));
  reverse(begin(A), end(A));
  lint cost = 0;
  for (auto i : A) cost += i.second;
  lint buy = 0;
  while (!A.empty()) {
    while (!A.empty() && A.back().first <= buy) {
      buy += A.back().second;
      A.pop_back();
    }
    if (A.empty()) break;
    lint ev = min(A[0].second, A.back().first - buy);
    buy += ev;
    cost += ev;
    A[0].second -= ev;
    if (A[0].second == 0) {
      A.pop_front();
    }
  }

  cout << cost << '\n';
  return 0;
}