#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

std::vector<int> ask(int l, int r) {
  printf("? %d %d\n", l, r);
  fflush(stdout);
  vector<int> ret(r - l + 1);
  for (int i = 0; i < ret.size(); ++i) {
    scanf("%d", &ret[i]);
  }
  return ret;
}

int solve() {
  scanf("%d", &n);

  int l = 1, r = n;
  int ans = 1;
  while (l < r) {
    int mid = (l + r) >> 1;

    vector<int> res = ask(l, mid);
    int cnt = 0;
    for (int num : res) {
      if (num < l || num > mid) {
        ++cnt;
      }
    }

    if (cnt % 2 == (mid - l + 1) % 2) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  printf("! %d\n", l);
  fflush(stdout);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}