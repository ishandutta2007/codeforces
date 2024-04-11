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
  const int K = 20'200;
  vector<bool> is_not_prime(K);
  for (int i = 2; i < K; ++i) {
    int j = 2;
    while (j * j <= i) {
      if (i % j == 0) {
        is_not_prime[i] = true;
        break;
      }
      ++j;
    }
  }
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
      cin >> A[i];
    int sum = 0;
    for (int x : A)
      sum += x;
    if (is_not_prime[sum]) {
      cout << n << '\n';
      for (int i = 0; i < n; ++i)
        cout << i + 1 << ' ';
      cout << '\n';
    } else {
      for (int i = 0; i < n; ++i) {
        if (is_not_prime[sum - A[i]]) {
          cout << n - 1 << '\n';
          for (int j = 0; j < i; ++j)
            cout << j + 1 << ' ';
          for (int j = i + 1; j < n; ++j)
            cout << j + 1 << ' ';
          cout << '\n';
          break;
        }
      }
    }
  }
  return 0;
}