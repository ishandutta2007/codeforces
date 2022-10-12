#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;

int n;
char s[N];
int pre[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  long long cur = 0;
  vector<int> rgt;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      cur += i - (int) rgt.size();
      rgt.push_back(i);
    }
  }

  reverse(rgt.begin(), rgt.end());
  vector<int> lft;

  long long ans = cur;
  for (int i = rgt.size(); i < n; ++i) {
    while (rgt.size() > 0 && rgt.back() < i - (int) rgt.size() + 1) {
      lft.push_back(rgt.back());
      rgt.pop_back();
    }

    cur += lft.size();
    cur -= rgt.size();
    ans = min(ans, cur);
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}