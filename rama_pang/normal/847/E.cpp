#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> men;
  vector<int> points;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      points.emplace_back(i);
    }
    if (s[i] == 'P') {
      men.emplace_back(i);
    }
  }
  const auto Check = [&](int t) {
    int ptr = 0;
    for (int i = 0; i < (int) men.size() && ptr < (int) points.size(); i++) {
      if (ptr < (int) points.size() && points[ptr] < men[i] - t) {
        return false;
      }
      int nptr = ptr;
      while (nptr < (int) points.size() && 
          abs(points[nptr] - points[ptr]) + 
          min(abs(men[i] - points[ptr]), abs(men[i] - points[nptr])) <= t) {
        nptr++;
      }
      ptr = nptr; 
    }
    return ptr == (int) points.size();
  };

  int lo = 1, hi = 2 * n;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (Check(md)) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  cout << lo << "\n";
  return 0;
}