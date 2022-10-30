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

bool good(long long n){
  long long t = n;
  while (t){
    int k = t % 10;
    t /= 10;
    if (k != 0 && n % k != 0)
      return false;
  }
  return true;
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
  while (t--){
    long long n;
    cin >> n;
    while (!good(n))
      ++n;
    cout << n << '\n';
  }
  return 0;
}