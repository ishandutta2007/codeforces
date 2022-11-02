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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> first_id(26, n);
    for (int i = 0; i < n; ++i)
      first_id[s[i] - 'a'] = i;
    int j = n;
    for (int x : first_id)
      j = min(j, x);
    for (; j < n; ++j)
      cout << s[j];
    cout << '\n';
  }
  return 0;
}