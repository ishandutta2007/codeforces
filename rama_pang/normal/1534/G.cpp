#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N;
  cin >> N;
  vector<pair<lint, lint>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
    A[i] = pair(A[i].first + A[i].second, A[i].first - A[i].second);
  }
  sort(begin(A), end(A));

  // dp[x][y] = answer, if we are at coord x, currently at y
  // dp[x][y] += abs(Y - y) for Y in coord x
  // dp[x][y] += y - Y if Y < y
  // dp[x][y] += Y - y if Y > y
  //
  // Minimum cost to change some array such that adjacent elements have difference 1.
  // For a fixed x, we have some sum of abs functions.
  // DP Slope Trick.
  //
  // Let's say we have answer for some x, want to move to x+1.
  // Instead of +1 and -1 every time we move to x+1, we make it
  // to +2 or 0.

  lint ans = 0;
  for (auto &a : A) {
    a.second += a.first;
    if (a.first * 2 < a.second) {
      ans += a.second - 2 * a.first;
      a.second = 2 * a.first;
    }
  }

  lint lowerLazy = 0;
  lint upperLazy = 0;
  priority_queue<lint> lower;
  priority_queue<lint, vector<lint>, greater<lint>> upper;
  lower.emplace(0);
  upper.emplace(0);
  lint lastX = 0;
  for (int i = 0; i < int(A.size()); i++) {
    int j = i;
    while (j + 1 < int(A.size()) && A[i].first == A[j + 1].first) {
      j += 1;
    }
    upperLazy += 2 * (A[i].first - lastX);
    lastX = A[i].first;
    for (int k = i; k <= j; k++) {
      if (A[k].second < lower.top() + lowerLazy) {
        ans += lower.top() + lowerLazy - A[k].second;
      }
      if (upper.top() + upperLazy < A[k].second) {
        ans += A[k].second - upper.top() - upperLazy;
      }
      if (A[k].second & 1) {
        lower.emplace(A[k].second - 1 - lowerLazy);
        lower.emplace(A[k].second + 1 - lowerLazy);
      } else {
        lower.emplace(A[k].second - lowerLazy);
        lower.emplace(A[k].second - lowerLazy);
      }
      while (!lower.empty() && lower.top() + lowerLazy > upper.top() + upperLazy) {
        auto top = lower.top() + lowerLazy;
        lower.pop();
        upper.emplace(top - upperLazy);
      }
      while (lower.size() > upper.size()) {
        auto top = lower.top() + lowerLazy;
        lower.pop();
        upper.emplace(top - upperLazy);
      }
      while (lower.size() < upper.size()) {
        auto top = upper.top() + upperLazy;
        upper.pop();
        lower.emplace(top - lowerLazy);
      }
    }
    i = j;
  }

  assert(ans % 2 == 0);
  ans /= 2;
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