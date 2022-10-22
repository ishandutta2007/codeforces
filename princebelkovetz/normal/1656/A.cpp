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
    int n; cin >> n;
    vector <int> a(n);
    for (auto &x: a) cin >> x;
    int id1 = 0, id2 = 0;
    for (int i = 0; i < n; ++i){
      if (a[i] < a[id1]) id1 = i;
      if (a[i] > a[id2]) id2 = i;
    }
    cout << id1 + 1 << ' ' << id2 + 1 << '\n';
  }


  return 0;
}