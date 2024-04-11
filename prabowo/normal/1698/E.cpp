#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n, s;
int a[N], b[N];

vector<int> pos(int a[]) {
  vector<int> ret(n, -1);
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) continue;
    ret[a[i]] = i;
  }
  return ret;
}

int solve() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    --b[i];
  }

  vector<int> pa = pos(a), pb = pos(b);
  set<int> sb(pb.begin(), pb.end());
  sb.erase(-1);

  int ans = 1;
  set<int> seenB;
  int cnt = 0;
  for (int i = 0; i < s; ++i) {
    if (sb.find(pa[i]) == sb.end()) {
      ++cnt;
    } else {
      seenB.insert(pa[i]);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i + s < n) {
      if (sb.find(pa[i + s]) == sb.end()) {
        ++cnt;
      } else {
        seenB.insert(pa[i + s]);
      }
    }
    if (pb[i] < 0) {
      ans = 1LL * ans * cnt % MOD;
      --cnt;
    } else {
      if (seenB.find(pb[i]) == seenB.end()) {
        ans = 0;
      }
    }
  }

  printf("%d\n", ans);
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