#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main () {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> bal(n + 1);
  bal[0] = 0;
  for (int i = 0; i < n; ++i) {
    bal[i + 1] = bal[i];
    if (s[i] == '(')
      ++bal[i + 1];
    else
      --bal[i + 1];
    if (bal[i + 1] < -1) {
      cout << "No\n";
      return 0;
    }
  }
  if (bal[n] != 0) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  return 0;
}