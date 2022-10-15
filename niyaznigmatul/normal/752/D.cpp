#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void read(string &s) {
  s = "";
  int c = getchar();
  while (c <= 32) c = getchar();
  s = "";
  while (c > 32) s += (char) c, c = getchar();
}

int const INF = 1 << 30;

string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  int k, n;
  scanf("%d%d", &k, &n);
  map<string, vector<int> > f;
  for (int i = 0; i < k; i++) {
    string s;
    read(s);
    int x;
    scanf("%d", &x);
    f[s].push_back(x);
  }
  for (auto &e : f) {
    sort(e.second.begin(), e.second.end());
  }
  int ans = 0;
  for (auto &e : f) {
    string const &str = e.first;
    string rstr = rev(str);
    if (str == rstr) continue;
    if (f.find(rstr) == f.end()) continue;
    auto &a = e.second;
    auto &ra = f[rstr];
    while (!a.empty() && !ra.empty() && a.back() + ra.back() > 0) {
      ans += a.back();
      ans += ra.back();
      a.pop_back();
      ra.pop_back();
    }
  }
  int dp1 = 0;
  int dp2 = -INF;
  for (auto &e : f) {
    auto &list = e.second;
    if (e.first != rev(e.first)) continue;
    int size = (int) list.size();
    while (size > 1 && list[size - 2] > 0) {
      ans += list.back() + list[size - 2];
      size -= 2;
      list.pop_back();
      list.pop_back();
    }
    if (size > 0 && list.back() > 0) {
      int x = list.back();
      int y;
      if (size > 1) {
        y = list.back() + list[size - 2];
      } else {
        y = -INF;
      }
      int ndp1 = dp1;
      int ndp2 = dp2;
      if (y != -INF) {
        ndp1 = std::max(ndp1, dp1 + y);
        ndp2 = std::max(ndp2, dp2 + y);
      }
      ndp2 = std::max(ndp2, dp1 + x);
      dp1 = ndp1;
      dp2 = ndp2;
    }
  }
  ans += std::max(dp1, dp2);
  printf("%d\n", ans);
}