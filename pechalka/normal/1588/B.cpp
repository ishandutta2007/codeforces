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

long long get(int l, int r) {
  cout << '?' << ' ' << l + 1 << ' ' << r + 1 << endl;
  long long x;
  cin >> x;
  return x;
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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long all = get(0, n - 1);
    int left = 0, right = n - 1;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (get(0, mid) == all)
        right = mid;
      else
        left = mid;
    }
    int k = right;
    int b = all - get(0, right - 1) + 1;
    int j = k - b + 1;
    int a = get(0, j - 1) - get(0, j - 2) + 1;
    int i = j - a;
    cout << '!' << ' ' << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
  }
  return 0;
}