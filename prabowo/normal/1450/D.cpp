#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int INF = 1e9;

int n;
int a[N];

vector<int> pos[N];
char ans[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) pos[i].clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    pos[--a[i]].push_back(i);
    ans[i] = '0';
  }
  ans[n] = 0;

  int l = 0, r = n - 1;
  for (int i = 0; i < n; ++i) {
    int idx = lower_bound(pos[i].begin(), pos[i].end(), l) - pos[i].begin();
    if (idx < pos[i].size() && pos[i][idx] <= r) {
      ans[n - i - 1] = '1';
    } else {
      break;
    }

    if (pos[i].size() != 1) break;
    if (pos[i][0] == l) ++l;
    else if (pos[i][0] == r) --r;
    else break;
  }

  sort(a, a + n); ans[0] = '1';
  for (int i = 0; i < n; ++i) if (a[i] != i) ans[0] = '0';

  printf("%s\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}