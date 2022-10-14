#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  if (count(begin(s), end(s), 'W') == 0) {
    cout << max(0, 2 * k - 1) << "\n";
    return;
  }

  vector<int> a;
  int last = 0;
  vector<int> two;
  two.emplace_back(0);
  while (!s.empty() && s.back() == 'L') {
    two.back()++;
    s.pop_back();
  }
  reverse(begin(s), end(s));
  two.emplace_back(0);
  while (!s.empty() && s.back() == 'L') {
    two.back()++;
    s.pop_back();
  }
  reverse(begin(s), end(s));
  
  lint score = 0;
  last = 0;
  for (auto i : s) {
    if (i == 'W') {
      if (last == 0) {
        score += 1;
      } else {
        score += 2;
      }
      last++;
    } else {
      last = 0;
    }
  }

  last = 0;
  for (auto i : s) {
    if (i == 'W') {
      if (last > 0) {
        a.emplace_back(last);
      }
      last = 0;
    } else {
      last++;
    }
  }

  sort(begin(a), end(a));
  for (auto i : a) {
    if (k >= i) {
      k -= i;
      score += 2 * i + 1;
    } else {
      score += 2 * k;
      k = 0;
    }
  }

  score += 2 * min(two[0] + two[1], k);
  
  cout << score << "\n";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}