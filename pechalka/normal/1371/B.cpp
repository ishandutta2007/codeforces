#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

int main(){
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
    long long n, r;
    cin >> n >> r;
    long long ans = min(n - 1, r) * (min(n - 1, r) + 1) / 2;
    if (n <= r)
      ans += 1;
    cout << ans << '\n';
  }
  return 0;
}