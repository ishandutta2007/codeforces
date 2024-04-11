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

int main() {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> A(n);
    vector<long long> B(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    for (int i = 0; i < n; ++i)
      cin >> B[i];
    long long dp = 0;
    for (int i = 1; i < n; ++i)
      dp += min(abs(A[i] - A[i - 1]) + abs(B[i] - B[i - 1]), abs(B[i] - A[i - 1]) + abs(A[i] - B[i - 1]));
    cout << dp << '\n';
  }
  return 0;
}