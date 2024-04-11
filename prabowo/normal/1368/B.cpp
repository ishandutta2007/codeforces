#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

long long n;

string s = "codeforces";

int solve() {
  scanf("%lld", &n);

  vector<int> c(s.size(), 1);
  long long cnt = 1;
  for (int i = 2; cnt < n; ++i) {
    for (int j = 0; j < s.size(); ++j) {
      cnt /= (i - 1);
      cnt *= i;
      ++c[j];

      if (cnt >= n) break;
    }
  }

  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < c[i]; ++j) {
      printf("%c", s[i]);
    }
  }

  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}