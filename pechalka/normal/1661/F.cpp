#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <string>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long long f(int n, int k) {
  long long x = n / k;
  return x * x * k + (2 * x + 1) * (n - x * k);
}

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  for (int i = n - 1; i > 0; --i)
    A[i] -= A[i - 1];
  sort(A.begin(), A.end());
  vector<int> B;
  vector<int> kek;
  {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      ++cur;
      if (i + 1 == n || A[i + 1] != A[i]) {
        B.emplace_back(A[i]);
        kek.emplace_back(cur);
        cur = 0;
      }
    }
  }
  long long need;
  cin >> need;
  long long cur = 0;
  for (int x : A)
    cur += x * 1ll * x;
  set<pair<long long, int>> deltas;
  n = B.size();
  vector<long long> cnt(n);
  for (int i = 0; i < n; ++i) {
    if (B[i] == 1)
      continue;
    deltas.emplace(f(B[i], 2) - B[i] * 1ll * B[i], i);
  }
  int ans = 0;
  while (cur > need) {
    int i = deltas.begin()->second;
    long long delta = deltas.begin()->first;
    deltas.erase(deltas.begin());
    long long have = 1;
    if (B[i] / (cnt[i] + 1) == B[i] / (cnt[i] + 2))
      have = B[i] / (B[i] / (cnt[i] + 1)) - cnt[i] - 1;
    if (cur + have * delta * kek[i] > need) {
      cur += have * delta * kek[i];
      cnt[i] += have;
      ans += have * kek[i];
      if (cnt[i] != B[i] - 1)
        deltas.emplace(f(B[i], cnt[i] + 2) - f(B[i], cnt[i] + 1), i);
    } else {
      long long rest = (cur - need - delta - 1) / (-delta);
      ans += rest;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}