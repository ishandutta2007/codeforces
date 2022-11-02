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
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    sort(A.rbegin(), A.rend());
    long long sum = 0;
    for (long long x : A)
      sum += x;
    int id = 0;
    multiset<long long> Q;
    Q.emplace(sum);
    for (int i = 0; i < n - 1; ++i) {
      long long x = *(--Q.end());
      Q.erase(--Q.end());
      if (x == A[id]) {
        ++id;
        --i;
      } else {
        Q.emplace((x + 1) / 2);
        Q.emplace(x / 2);
      }
    }
    bool ok = (n - id) == Q.size();
    if (ok) {
      while (id < n) {
        ok = ok && (*(--Q.end())) == A[id];
        ++id;
        Q.erase(--Q.end());
      }
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}