#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int t, n, x;
inline vector<int> calc(vector<int> a, int s) {
  int n = a.size();
  vector<int> ans(n);
  if (n < 4)
    for (int i = 0; i < n; i++) ans[i] = s + i;
  else {
    int tp = 0, cnt = s;
    for (int i = 1; i < 4; i++)
      if (a[i] > a[tp]) tp = i;
    for (int i = 0; i < 4; i++)
      if (i != tp) ans[i] = cnt++;
    int x = 0, y = 0;
    if (tp) x = ans[tp - 1];
    if (tp < 3) y = ans[tp + 1];
    for (int j = s;; j++)
      if (j != x && j != y) {
        ans[tp] = j;
        break;
      }
  }
  return ans;
}
inline vector<int> solve(vector<int> a, int s) {
  int n = (int)a.size();
  if (n <= 4) return calc(a, s);
  vector<int> ans(n), tp, pos(n);
  vector<bool> ok(n, 0);
  int g = 0, cnt = 0;
  for (int i = 1; i < n; i++) {
    if (i % 3 == 0)
      ok[g] = 1, pos[g] = cnt++, tp.push_back(a[g]), g = i;
    else if (a[i] < a[g])
      g = i;
  }
  pos[g] = cnt++, ok[g] = 1, tp.push_back(a[g]);
  vector<int> qwq = solve(tp, s + 3), b;
  set<int> q;
  for (int i = 0; i < n; i++) b.push_back(i);
  sort(b.begin(), b.end(), [&](int i, int j) { return a[i] < a[j]; });
  for (int i : b) {
    if (ok[i])
      q.insert(i), ans[i] = qwq[pos[i]];
    else {
      auto it = q.lower_bound(i);
      int tp[4] = {0}, cnt = 0, x = 0, y = 0;
      while (it != q.begin()) {
        it--;
        if (ans[*it] > s + 2) {
          it++;
          break;
        }
      }
      while (it != q.end()) {
        if (ans[*it] > s + 2) break;
        tp[++cnt] = ans[*it++];
      }
      sort(tp + 1, tp + cnt + 1), cnt = unique(tp + 1, tp + cnt + 1) - tp - 1;
      if (cnt <= 2)
        x = tp[1], y = tp[2];
      else {
        it = q.lower_bound(i);
        if (it != q.end()) y = ans[*it];
        if (it != q.begin()) x = ans[*--it];
      }
      q.insert(i);
      for (int k = s;; k++)
        if (k != x && k != y) {
          ans[i] = k;
          break;
        }
    }
  }
  return ans;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; i++) scanf("%d", &x), a[x - 1] = i;
    vector<int> ans = solve(a, 1);
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], " \n"[i == n - 1]);
  }
}