#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 998244353, N = 2e2 + 3;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);

  int tt; cin >> tt;
  while (tt--){
    int n, x, y; cin >> n >> x >> y;
    int ok = 0;
    for (int i = 0, z; i < n; ++i){
      cin >> z;
      ok ^= z;
    }
    ok ^= x ^ y;

    cout << (ok & 1 ^ 1 ? "Alice" : "Bob") << '\n';
  }

  return 0;
}