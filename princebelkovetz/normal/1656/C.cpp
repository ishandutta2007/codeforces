#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 998244353;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);

  int tt; cin >> tt;
  while (tt--){
    int n, cnt = 0; cin >> n;
    vector <int> a(n);
    for (auto &x: a) cin >> x, cnt += (x == 1);
    if (cnt == 0 or cnt == n){
      cout << "YES\n";
    } else {
     bool ok = true;
     sort(a.begin(), a.end());
     for (int i = 0; i + 1 < n; ++i)
       if (a[i] + 1 == a[i + 1]) ok = false;
     cout << (ok ? "YES" : "NO") << '\n';
    }
  }


  return 0;
}