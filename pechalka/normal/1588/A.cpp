#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

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
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    sort(A.begin(), A.end());
    vector<int> B(n);
    for (int i = 0; i < n; ++i)
      cin >> B[i];
    sort(B.begin(), B.end());
    bool ok = true;
    for (int i = 0; i < n; ++i)
      ok = ok && (A[i] <= B[i] && A[i] + 1 >= B[i]);
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}